class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        if (text1.size() == 0 || text2.size() == 0) return 0;
        
        if (text1[0] == text2[0])
            DP[0][0] = 1;
        else 
            DP[0][0] = 0;
        
        
        for (int i = 1; i < text2.size(); i++){
            if (text1[0] == text2[i])
                DP[0][i] = 1;
            else 
                DP[0][i] = DP[0][i - 1];
        }
        
        for (int j = 1; j < text1.size(); j++){
            if (text1[j] == text2[0])
                DP[j][0] = 1;
            else 
                DP[j][0] = DP[j - 1][0];
        }
        
        for (int i = 1; i < text1.size(); i++){
            for (int j = 1; j < text2.size(); j++){
                if (text1[i] == text2[j])
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                else 
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
        
        return DP[text1.size() - 1][text2.size() - 1];
        
    }
private:
    const static int N_MAX = 1000;
    int DP[N_MAX][N_MAX];
};
