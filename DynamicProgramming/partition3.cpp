#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

int subsets(unordered_map<string, bool>& lookup, int S1, int S2, int S3, int i, vector<int>& A) {

    string key = to_string(S1) + "|" + to_string(S2) + "|" + to_string(S3) + "|" + to_string(i);


    if (lookup.find(key) == lookup.end()) {

        if (S1 == 0 && S2 == 0 && S3 == 0 && i == A.size()) {
            lookup.insert(pair<string, bool>(key, true));
            return 1;
        }

        if (i == A.size()) {
            lookup.insert(pair<string, bool>(key, false));
            return 0;
        }

        if (S1 < 0 || S2 < 0 || S3 < 0) {
            lookup.insert(pair<string, bool>(key, false));
            return 0;
        }

        // Need to calculate it.
        if (S1 - A[i] >= 0) {
            // Try to put it into first set.
            if (subsets(lookup, S1 - A[i], S2, S3, i + 1, A)) {
                lookup.insert(pair<string, bool>(key, true));
                return 1;
            }
        }
        if (S2 - A[i] >= 0) {
            // Try second if first one didn't work.
            if (subsets(lookup, S1, S2 - A[i], S3, i + 1, A)) {
                lookup.insert(pair<string, bool>(key, true));
                return 1;
            }
        }

        if (S3 - A[i] >= 0) {
            if (subsets(lookup, S1, S2, S3 - A[i], i + 1, A)) {
                lookup.insert(pair<string, bool>(key, true));
                return 1;
            }
        }

        lookup.insert(pair<string, bool>(key, false));
        return 0;
    }

    return lookup.find(key)->second ? 1 : 0;
    
}
int partition3(vector<int>& A) {

    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % 3) return 0; // trivial case.

    unordered_map<string, bool> lookup;

    return subsets(lookup, sum / 3, sum / 3, sum / 3, 0, A);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}
