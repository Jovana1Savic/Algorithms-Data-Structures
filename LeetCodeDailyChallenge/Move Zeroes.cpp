class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int zero_ptr = 0;
        int non_zero_ptr = 0;
        int n = nums.size();
        
        while (non_zero_ptr < n && zero_ptr < n){
            
            while (zero_ptr < n && nums[zero_ptr] != 0){
                zero_ptr++;
            }
            
            if (zero_ptr >= n) return;
            
            if (non_zero_ptr < zero_ptr)
                non_zero_ptr = zero_ptr + 1;
            
            while (non_zero_ptr < n && nums[non_zero_ptr] == 0){
                non_zero_ptr++;
            }
            
            if (non_zero_ptr >= n) return;
            
            nums[zero_ptr] = nums[non_zero_ptr];
            nums[non_zero_ptr] = 0;
            
            zero_ptr++;
            non_zero_ptr++;
        }
    }
};
