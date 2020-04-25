class Solution {
public:
    
    int max(int a, int b){
        if (a > b) return a;
        return b;
    }
    
    int findMaxLength(vector<int>& nums) {
        
        map<int, int> sums;
        sums.insert(pair<int, int>(0, -1));
        
        int sum = 0, maxLen = 0;
        
        for (int i = 0; i < nums.size(); i++){
            
            if (nums[i] == 0) sum -= 1;
            else sum += 1;
            
            if (sums.find(sum) != sums.end())
                maxLen = max(maxLen, i - sums.find(sum)->second);
            else 
                sums.insert(pair<int, int>(sum, i));
        }
        
        return maxLen;
    }
};
