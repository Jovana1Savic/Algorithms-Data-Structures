class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if (nums.empty()) return -1;
        
        int xor_sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
            xor_sum ^= nums[i];
        
        return xor_sum;
    }
};
