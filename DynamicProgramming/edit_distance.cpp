#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int edit_distance(const string& str1, const string& str2) {

    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> DP;
    for (int i = 0; i <= n; i++) {
        DP.push_back(vector<int>(m + 1, 0));
    }

    for (int i = 0; i <= n; i++)
        DP[i][0] = i;
    for (int j = 0; j <= m; j++)
        DP[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i-1] == str2[j-1]) {
                DP[i][j] = min(DP[i - 1][j] + 1, DP[i][j - 1] + 1, DP[i - 1][j - 1]);
            }
            else {
                DP[i][j] = min(DP[i - 1][j] + 1, DP[i][j - 1] + 1, DP[i - 1][j - 1] + 1);
            }
        }
    }

    return DP[n][m];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
