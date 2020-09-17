#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int>& weights) {
    int n = weights.size();
    vector<vector<int>> DP; // W+1 x n+1
    for (int i = 0; i <= W; i++) {
        DP.push_back(vector<int>(n + 1, 0));
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            DP[w][i] = DP[w][i - 1];
            if (weights[i - 1] <= w) {
                int val = DP[w - weights[i - 1]][i - 1] + weights[i - 1]; // with i-1 -th item included
                if (DP[w][i] < val)
                    DP[w][i] = val;
            }
        }
    }

    return DP[W][n];
    
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
