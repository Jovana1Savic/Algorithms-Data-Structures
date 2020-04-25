class Solution {
public:
    
    void visitIsland(vector<vector<char>>* grid, int r, int c){
        
        if (r < 0 || c < 0) return;
        if (r >= (*grid).size() || c >= (*grid)[0].size()) return;
        
        if ((*grid)[r][c] == '0') return;
        
        (*grid)[r][c] = '0';
        
        visitIsland(grid, r + 1, c);
        visitIsland(grid, r - 1, c);
        visitIsland(grid, r, c - 1);
        visitIsland(grid, r, c + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int num = 0;
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    num++;
                    visitIsland(&grid, i, j);
                }
            }
        }
        
        return num;
    }
};
