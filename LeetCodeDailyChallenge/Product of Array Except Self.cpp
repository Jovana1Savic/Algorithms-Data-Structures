class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ret;
        
        int p = 1;
        for (int i = 0; i < nums.size(); i++){
            ret.push_back(p);
            p = p * nums[i];
        }
        
        p = 1;
        for (int i = nums.size() - 1; i >= 0; i--){
            ret[i] *= p;
            p *= nums[i];
        }
        
        return ret;
    }
};
