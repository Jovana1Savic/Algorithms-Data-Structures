class Solution {
public:
    
    int min(const int& a, const int& b){
        if (a > b) return b;
        return a;
    }
    
    int minCostPath(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp){
        
        int r_max = grid.size() - 1;
        int c_max = grid[0].size() - 1;
        
        if (dp[r][c] != -1)
            return dp[r][c];
            
        if (r == r_max && c == c_max)
        {
            dp[r][c] = grid[r][c];
            return grid[r][c];
        }
        
        if (r == r_max){
            dp[r][c] = grid[r][c] + minCostPath(grid, r, c + 1, dp);
            return dp[r][c];
        }
        
        if (c == c_max){
            dp[r][c] = grid[r][c] + minCostPath(grid, r + 1, c, dp);
            return dp[r][c];
        }
            
        
        dp[r][c] = grid[r][c] + min(minCostPath(grid, r + 1, c, dp), 
                                    minCostPath(grid, r, c + 1, dp));
        
        return dp[r][c];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        if (grid.size() == 0) return 0;
        
        vector<vector<int>> dp;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++){
            vector<int> v;
            for (int j = 0; j < m; j++)
                v.push_back(-1);
            dp.push_back(v);
        }
        
        return minCostPath(grid, 0, 0, dp);
    }
};
