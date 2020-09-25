/*
Task. In this problem your goal is to implement the Rabin–Karp’s algorithm for
searching the given pattern in the given text.

Input Format. There are two strings in the input: the pattern 𝑃 and the text 𝑇.

Constraints. 1 ≤ |𝑃| ≤ |𝑇| ≤ 5 · 105. The total length of all occurrences of 𝑃
in 𝑇 doesn’t exceed 108. The pattern and the text contain only latin letters.

Output Format. Print all the positions of the occurrences of 𝑃 in 𝑇 in the
ascending order. Use 0-based indexing of positions in the the text 𝑇.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

static const size_t multiplier = 3;
static const size_t prime = 1000000007;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}

long long hash_func(const string& s, const int& begin, const int& end) {

    unsigned long long hash = 0;

    for (int i = end; i >= begin; --i)
        hash = (hash * multiplier + s[i]) % prime;

    return hash;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

vector<long long> precompute_hashes(const string& text, const string& pattern) {

    vector<long long> H(text.size() - pattern.size() + 1);
    H[text.size() - pattern.size()] = hash_func(text, text.size() - pattern.size(), text.size() - 1);

    long long y = 1;
    for (int i = 0; i < pattern.size(); i++)
        y = (y * multiplier) % prime;

    for (int i = H.size() - 2; i >= 0; i--) {
        H[i] = ((multiplier * H[i + 1]) % prime + text[i] - (y * text[i + pattern.size()]) % prime + prime) % prime;
    }

    return H;
}
vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    vector<int> ans;

    vector<long long> H = precompute_hashes(t, s);
    ull pattern_hash = hash_func(s, 0, s.size() - 1);

    for (size_t i = 0; i + s.size() <= t.size(); ++i) {
        if (pattern_hash != H[i])
            continue;
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    }

    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
