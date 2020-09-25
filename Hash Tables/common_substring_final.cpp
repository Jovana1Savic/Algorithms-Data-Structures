/*
Input Format. Every line of the input contains two strings 𝑠 and 𝑡 consisting of
lower case Latin letters.

Constraints. The total length of all 𝑠’s as well as the total length of all 𝑡’s
does not exceed 100 000.

Output Format. For each pair of strings 𝑠 and 𝑡𝑖, find its longest common
substring and specify it by outputting three integers: its starting position in
𝑠, its starting position in 𝑡 (both 0-based), and its length. More formally,
output integers 0 ≤ 𝑖 < |𝑠|, 0 ≤ 𝑗 < |𝑡|, and 𝑙 ≥ 0 such that 𝑠𝑖𝑠𝑖+1 · · ·
𝑠𝑖+𝑙−1 = 𝑡𝑗 𝑡𝑗+1 · · · 𝑡𝑗+𝑙−1 and 𝑙 is maximal. (As usual, if there are many
such triples with maximal 𝑙, output any of them.)
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

static const int num_of_hashes = 2;

size_t min(const size_t& a, const size_t& b) {
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

struct Answer {
	size_t i, j, len;
};

class SubstringSolver {

	StringHasher* first_hash;
	StringHasher* second_hash;
	bool swapped;

public:

	SubstringSolver(string& s, string& t, const vector<Hash*>& h) {

		if (s.size() < t.size()) {
			first_hash = new StringHasher(s, h);
			second_hash = new StringHasher(t, h);
			swapped = false;
		}
		else {
			first_hash = new StringHasher(t, h);
			second_hash = new StringHasher(s, h);
			swapped = true;
		}
	}

	~SubstringSolver() {

		delete first_hash;
		delete second_hash;
	}

	// Check if there's a substring of length len.
	Answer check_substring(size_t len) {

		Answer ans = { 0, 0, 0 };

		map<long long, size_t> hashes;

		for (size_t a = 0; a <= first_hash->string_size() - len; a++) {
			long long h = first_hash->get_hash(0, a, len);
			hashes.insert(pair<long long, size_t>(h, a));
		}
		for (size_t b = 0; b <= second_hash->string_size() - len; b++) {

			long long h = second_hash->get_hash(0, b, len);
			auto it = hashes.find(h);

			if (it != hashes.end()) {
				long long hash_a = first_hash->get_hash(1, it->second, len);
				long long hash_b = second_hash->get_hash(1, b, len);
				if (hash_a == hash_b) {
					ans = { it->second, b, len };
					return ans;
				}
			}
		}

		return ans;
	}

	Answer solve() {

		Answer current_best = { 0, 0, 0 };

		int left = 0, right = min(first_hash->string_size(), second_hash->string_size());
		while (left <= right) {
			int mid = left + (right - left) / 2;
			Answer ans = check_substring(mid);
			if (ans.len != 0) {
				current_best = { ans.i, ans.j, ans.len };
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		if (swapped) {
			swap(current_best.i, current_best.j);
		}
		return current_best;
	}

};

Answer brute_force_solve(const string& s, const string& t) {
	Answer ans = { 0, 0, 0 };
	for (size_t i = 0; i < s.size(); i++)
		for (size_t j = 0; j < t.size(); j++)
			for (size_t len = 0; i + len <= s.size() && j + len <= t.size(); len++)
				if (len > ans.len&& s.substr(i, len) == t.substr(j, len))
					ans = { i, j, len };
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	Hash h1(1000000007, 13);
	Hash h2(1000000009, 123);
	vector<Hash*> v;
	v.push_back(&h1);
	v.push_back(&h2);
	while (cin >> s >> t) {
		SubstringSolver solver(s, t, v);
		auto ans = solver.solve();
		// auto ans_brute = brute_force_solve(s, t);
		// if (ans.len != ans_brute.len) {
		// 	cout << " WRONG ANSWER! " << "\n";
		// 	cout << " ACTUAL ANSWER! " << "\n";
		// 	cout << ans_brute.i << " " << ans_brute.j << " " << ans_brute.len << "\n";
		// }
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";


	}
}
