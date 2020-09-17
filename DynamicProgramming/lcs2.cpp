#include <iostream>
#include <vector>

using std::vector;

int max(const int& a, const int& b) {
    if (a > b) return a;
    return b;
}

int max(const int& a, const int& b, const int& c) {
    return max(max(a, b), c);
}

int lcs2(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> DP;
    for (int i = 0; i <= n; i++) {
        DP.push_back(vector<int>(m + 1, 0));
    }
    for (int i = 0; i <= n; i++)
        DP[i][0] = 0;
    for (int j = 0; j <= m; j++)
        DP[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    return DP[n][m];
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}
