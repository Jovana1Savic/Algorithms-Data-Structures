class Solution {
public:
    
    int min(const int& a, const int& b){
        if (a > b) return b;
        return a;
    }
    
    int min(const int& a, const int& b, const int& c){
        return min(a, min(b, c));
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<vector<int>> DP;
        for(int i = 0; i < matrix.size(); i++){
            vector<int> v;
            for (int j = 0; j < matrix[i].size(); j++)
                v.push_back(matrix[i][j] - '0');
            DP.push_back(v);
        }
        
        for (int i = 1; i < DP.size(); i++){
            for (int j = 1; j < DP[i].size(); j++){
                if (matrix[i][j] == '1'){
                    DP[i][j] = min(DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]) + 1;
                }
                else 
                    DP[i][j] = 0;
            }
        }
        
        int max = 0;
        for (int i = 0; i < DP.size(); i++){
            for (int j = 0; j < DP[i].size(); j++){
                if (DP[i][j] > max)
                    max = DP[i][j];
            }
        }
        
        return max*max;
    }
};
