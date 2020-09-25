/*
Input Format. The first line contains a string 𝑠 consisting of small Latin
letters. The second line contains the number of queries 𝑞. Each of the next 𝑞
lines specifies a query by three integers 𝑎, 𝑏, and 𝑙.

Constraints. 1 ≤ |𝑠| ≤ 500 000. 1 ≤ 𝑞 ≤ 100 000. 0 ≤ 𝑎, 𝑏 ≤ |𝑠| − 𝑙 (hence the
indices 𝑎 and 𝑏 are 0-based).

Output Format. For each query, output “Yes” if 𝑠𝑎𝑠𝑎+1. . .𝑠𝑎+𝑙−1 = 𝑠𝑏𝑠𝑏+1. .
.𝑠𝑏+𝑙−1 are equal, and “No” otherwise.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solver {

	string s;

	static const int num_of_hashes = 2;

	vector<long long>* hashes[num_of_hashes];
	vector<long long>* powers[num_of_hashes];

private:

	static const int get_prime(int i) {
		if (i == 0)
			return 1000000007;
		return 1000000009;
	}

	static const int get_multiplier(int i) {
		if (i == 0)
			return 3;
		return 2;
	}

	void precompute_hashes(int i, const string& s) {
		
		hashes[i] = new vector<long long>(s.size() + 1);
		int prime = get_prime(i);
		int multiplier = get_multiplier(i);

		(*hashes[i])[0] = 0;
		for (int j = 1; j < hashes[i]->size(); j++) {
			(*hashes[i])[j] = (((*hashes[i])[j - 1] * multiplier) % prime + s[j-1]) % prime;
		}
	}

	void precompute_powers(int i, int size) {

		powers[i] = new vector<long long>(size);
		int prime = get_prime(i);
		int multiplier = get_multiplier(i);

		(*powers[i])[0] = 1;
		for (int j = 1; j < size; j++) {
			(*powers[i])[j] = ((*powers[i])[j - 1] * multiplier) % prime;
		}
	}

	long long get_hash(int i, int j, int len) {

		int prime = get_prime(i);
		return ((*hashes[i])[j + len] - ((*powers[i])[len] * (*hashes[i])[j]) % prime + prime) % prime;
	}

public:
	Solver(string s) : s(s) {

		for (int i = 0; i < num_of_hashes; i++) {
			precompute_hashes(i, s);
			precompute_powers(i, s.size() + 1);
		}
	}

	bool ask(int a, int b, int l) {
		
		for (int i = 0; i < num_of_hashes; i++) {
			if (get_hash(i, a, l) != get_hash(i, b, l))
				return false;
		}
		return true;
	}

	~Solver() {

		for (int i = 0; i < num_of_hashes; i++) {
			delete hashes[i];
			delete powers[i];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
