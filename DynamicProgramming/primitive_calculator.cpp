#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
const int n_max = 1000001;
int DP[n_max];

int min(const int& a, const int& b) {
    if (a < b) return a;
    return b;
}

int min(const int& a, const int& b, const int& c) {
    return min(min(a, b), c);
}

// multiply by 2, 3 or add 1 to get n in min number of steps
vector<int> optimal_sequence(int n) {
    
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;
    DP[n] = n;

    for (int i = 4; i <= n; i++) {
        int div2 = n, div3 = n, sub1 = i - 1;
        if (i % 2 == 0)
            div2 = i / 2;
        if (i % 3 == 0)
            div3 = i / 3;
        DP[i] = 1 + min(DP[div2], DP[div3], DP[sub1]);
    }

    std::vector<int> sequence;
    
    while (n >= 4) {
        sequence.push_back(n);
        if ((n % 3 == 0) && (DP[n] == DP[n / 3] + 1)) {
            n = n / 3;
            continue;
        }
        if ((n % 2 == 0) && (DP[n] == DP[n / 2] + 1)) {
            n = n / 2;
            continue;
        }
        n--;
    }

    if (n == 3) {
        sequence.push_back(3);
    }
    if (n == 2) {
        sequence.push_back(2);
    }
    sequence.push_back(1);

    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
