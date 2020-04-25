class Solution {
public: 
    
    int min(const int& a, const int& b){
        if (a < b) return a;
        return b;
    }
    
    int canJump(vector<int>& nums, vector<int>& dp, int j){
        
        int ret = 0;
        int maxReach = min(nums[j] + j, nums.size() - 1);
        
        for (int i = j; i <= maxReach; i++){
            ret = ret | dp[i];
        }
        return ret;
    }
    
    bool canJump(vector<int>& nums) {
        
        if (nums.size() <= 1) return true;
        
        vector<int> dp;
        for (int i = 0; i < nums.size() - 1; i++)
            dp.push_back(0);
        dp.push_back(1);
        
        for(int i = nums.size() - 2; i >= 0; i--){
            dp[i] = canJump(nums, dp, i);
        }
        
        return dp[0];
    }
};
