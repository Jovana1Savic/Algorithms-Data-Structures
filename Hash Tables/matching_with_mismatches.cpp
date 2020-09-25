/*
Task. For an integer parameter 𝑘 and two strings 𝑡 = 𝑡0𝑡1 · · · 𝑡𝑚−1 and 𝑝 =
𝑝0𝑝1 · · · 𝑝𝑛−1, we say that 𝑝 occurs in 𝑡 at position 𝑖 with at most 𝑘
mismatches if the strings 𝑝 and 𝑡[𝑖 : 𝑖 + 𝑝) = 𝑡𝑖𝑡𝑖+1 · · · 𝑡𝑖+𝑛−1 differ in at
most 𝑘 positions.

Input Format. Every line of the input contains an integer 𝑘 and two strings 𝑡
and 𝑝 consisting of lower case Latin letters.

Constraints. 0 ≤ 𝑘 ≤ 5, 1 ≤ |𝑡| ≤ 200 000, 1 ≤ |𝑝| ≤ min{|𝑡|, 100 000}. The
total length of all 𝑡’s does not exceed 200 000, the total length of all 𝑝’s
does not exceed 100 000.

Output Format. For each triple (𝑘, 𝑡, 𝑝), find all positions 0 ≤ 𝑖1 < 𝑖2 < · · ·
< 𝑖𝑙 < |𝑡| where 𝑝 occurs in 𝑡 with at most 𝑘 mismatches. Output 𝑙 and 𝑖1, 𝑖2, .
. . , 𝑖𝑙.
*/
#include <iostream>
#include <vector>

using namespace std;

static const int num_of_hashes = 2;

inline int min(const int& a, const int& b) {
	if (a < b) return a;
	return b;
}

class Hash {

	int prime;
	int multiplier;
	vector<long long> powers;

public:
	Hash(int prime, int multiplier) :
		prime(prime), multiplier(multiplier) {
		powers.push_back(1);
	}

	int get_prime() { return prime; }
	int get_multiplier() { return multiplier; }
	long long get_power(int pow) {
		if (powers.size() > pow) {
			return powers[pow];
		}
		for (int i = powers.size() - 1; i <= pow; i++) {
			powers.push_back((powers.back() * multiplier) % prime);
		}
		return powers[pow];
	}
};

class StringHasher {

	string s;

	vector<long long>* precomputed_hashes[num_of_hashes];
	vector<Hash*> hash;

	friend class PatternMatchSolver;

private:

	void precompute_hashes(int i, const string& s) {

		precomputed_hashes[i] = new vector<long long>(s.size() + 1);
		int prime = hash[i]->get_prime();
		int multiplier = hash[i]->get_multiplier();

		(*precomputed_hashes[i])[0] = 0;
		for (int j = 1; j < precomputed_hashes[i]->size(); j++) {
			(*precomputed_hashes[i])[j] = (((*precomputed_hashes[i])[j - 1] * multiplier) % prime + s[j - 1]) % prime;
		}
	}

public:
	StringHasher(string s, const vector<Hash*>& h) : s(s) {

		for (int i = 0; i < num_of_hashes; i++) {
			hash.push_back(h[i]); // Very unsafe!
		}

		for (int i = 0; i < num_of_hashes; i++) {
			precompute_hashes(i, s);
		}
	}

	long long get_hash(int i, int j, int len) {

		int prime = hash[i]->get_prime();
		long long mult = hash[i]->get_power(len);
		return ((*precomputed_hashes[i])[j + len] - ((mult * (*precomputed_hashes[i])[j]) % prime) + prime) % prime;
	}

	size_t string_size() { return s.size(); }

	~StringHasher() {

		for (int i = 0; i < num_of_hashes; i++) {
			delete precomputed_hashes[i];
		}
	}
};

class PatternMatchSolver {

	StringHasher* text;
	StringHasher* pattern;
	int k;

public:

	PatternMatchSolver(int k, const string& txt, const string& pat, const vector<Hash*> h):k(k) {
		text = new StringHasher(txt, h);
		pattern = new StringHasher(pat, h);
	}

	~PatternMatchSolver() {
		delete text;
		delete pattern;
	}

	bool strings_equal(size_t pos, size_t left, size_t right) {
		int len = right - left + 1;
		if (len == 0) return true;
		if (text->get_hash(0, pos + left, len) == pattern->get_hash(0, left, len)) {
			if (text->get_hash(1, pos + left, len) == pattern->get_hash(1, left, len)) {
				return true;
			}
		}
		return false;
	}

	bool h_fits_pattern(size_t pos, size_t left, size_t right, int& curr_mismatch) {
		
		if (left > right) return 0;

		size_t mid = left + (right - left) / 2;
		if (text->s[mid + pos] != pattern->s[mid])
			curr_mismatch++;
		if (curr_mismatch > k) return false;
		if (!strings_equal(pos, left, mid - 1))
			if (!h_fits_pattern(pos, left, mid - 1, curr_mismatch))
				return false;
		if (!strings_equal(pos, mid + 1, right))
			if (!h_fits_pattern(pos, mid + 1, right, curr_mismatch))
				return false;
		return true;

	}

	bool fits_pattern(size_t pos) {
		int current_mismatch = 0;
		return h_fits_pattern(pos, 0, pattern->string_size()-1, current_mismatch);
	}

	vector<size_t> solve() {
		vector<size_t> res;
		if (pattern->string_size() > text->string_size()) return res;
		for (size_t pos = 0; pos <= text->string_size() - pattern->string_size(); pos++) {
			if (fits_pattern(pos)) {
				res.push_back(pos);
			}
		}
		return res;
	}
};

int num_of_mismatches(const string& text, const string& pattern, size_t pos) {

	int count = 0;
	for (size_t i = 0; i < pattern.size(); i++) {
		if (text[pos + i] != pattern[i])
			count++;
	}
	return count;
}

vector<int> brute_force_solve(int k, const string& text, const string& pattern) {
	
	vector<int> result;
	if (pattern.size() > text.size()) return result;

	for (size_t pos = 0; pos <= text.size() - pattern.size(); pos++) {
		if (num_of_mismatches(text, pattern, pos) <= k) {
			result.push_back(pos);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int k;
	string t, p;

	Hash h1(1000000007, 13);
	Hash h2(1000000009, 123);
	vector<Hash*> v;
	v.push_back(&h1);
	v.push_back(&h2);

	while (cin >> k >> t >> p) {
		PatternMatchSolver solver(k, t, p, v);
		auto a = solver.solve();
		// auto a_brute = brute_force_solve(k, t, p);

		// if (a.size() != a_brute.size()) {
		// 	cout << "ERROR : Different sizes!" << "\n";
		// 	cout << "Actual size = " << a_brute.size() << "\n";
		// 	cout << "Your size =" << a.size() << "\n";
		// 	int i = 0;
		// 	for (; i < min(a.size(), a_brute.size()); i++) {
		// 		cout << "Actual: " << a_brute[i] << " Your: " << a[i] << "\n";
		// 	}
		// 	for (; i < a.size(); i++) {
		// 		cout << "Your: " << a[i] << "\n";
		// 	}
		// 	for (; i < a_brute.size(); i++) {
		// 		cout << "Actual: " << a_brute[i] << "\n";
		// 	}
		// 	cout << "\n";
		// 	continue;
		// }

		// bool error = false;
		// for (int i = 0; i < a.size(); i++) {
		// 	cout << "Actual: " << a_brute[i] << "Your: " << a[i] << "\n";
		// 	if (a_brute[i] != a[i])
		// 		error = true;
		// }
		
		// if (error) {
		// 	cout << "ERROR: THERE WAS AN ERROR!" << "\n";
		// }
		// else {
		// 	cout << "There was no error..." << "\n";
		// }
		cout << a.size();
		for (int x : a)
			cout << " " << x;
		cout << "\n";
	}
}
