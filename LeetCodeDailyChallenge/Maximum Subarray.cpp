#include <climits> 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_so_far = INT_MIN;
        int max_ending_here = 0;
        
        for(auto it = nums.begin(); it != nums.end(); ++it){
            
            max_ending_here += (*it);
            
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            
            if (max_ending_here < 0)
                max_ending_here = 0; 
        }
        
        return max_so_far;
    }
};
