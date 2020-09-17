#include <iostream>
#include <vector>

using std::vector;
const int N_MAX = 101;
int DP[N_MAX][N_MAX][N_MAX];

int max(const int& a, const int& b) {
    if (a > b) return a;
    return b;
}

int max(const int& a, const int& b, const int& c) {
    return max(max(a, b), c);
}

int lcs3(vector<int>& a, vector<int>& b, vector<int>& c) {
    
    int n = a.size(); int m = b.size(); int p = c.size();
    for (int i = 0; i <= n; i++)
        DP[i][0][0] = 0;
    for (int j = 0; j <= m; j++)
        DP[0][j][0] = 0;
    for (int k = 0; k <= p; k++)
        DP[0][0][k] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= p; k++) {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                    DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
                else
                    DP[i][j][k] = max(DP[i - 1][j][k], DP[i][j - 1][k], DP[i][j][k - 1]);
            }
        }
    }

    return DP[n][m][p];
}

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
