// https://practice.geeksforgeeks.org/problems/path-in-matrix/0

#include <iostream>
#include <climits>
using namespace std;

const int N_MAX = 20;
int mat[N_MAX][N_MAX];
int dp[N_MAX][N_MAX];

void readMat(int n){
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
}

void prepareDP(int n){
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }
}

int max(const int& a, const int& b){
    if (a > b) return a;
    return b;
}

int max(const int& a, const int& b, const int& c){
    return max(a, max(b, c));
}

int maxSumPath(int r, int c, int n){
    
    if (c < 0 || c >= n) return INT_MIN;
    
    if (dp[r][c] != -1)
        return dp[r][c];
    
    if (r == n - 1){
        dp[r][c] = mat[r][c];
        return mat[r][c];
    }
    
    dp[r][c] = mat[r][c] + 
        max(maxSumPath(r + 1, c, n), maxSumPath(r + 1, c - 1, n), maxSumPath(r + 1, c + 1, n));
    return dp[r][c];
}

int maxSumPath(int n){
    
    int maxSum = INT_MIN;
    prepareDP(n);
    
    for (int j = 0; j < n; j++){
        int cMax = maxSumPath(0, j, n);
        if (maxSum < cMax)
            maxSum = cMax;
    }
    
    return maxSum;
}

int main() {
	int t, n;
	cin >> t;
	while (t--){
	    cin >> n;
	    readMat(n);
	    cout << maxSumPath(n) << endl;
	}
	
	return 0;
}
