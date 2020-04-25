class Solution {
public:
    
    int search(vector<int>& nums, int key) {
        
        int left = 0, right = nums.size() - 1;
        
        while (left <= right){
            int mid = (right + left) / 2;
            
            // At least begin-mid or mid-end arrays are sorted.
            if (nums[mid] == key) return mid;
            
            if (nums[left] <= nums[mid]){
                if (key <= nums[mid] && key >= nums[left]){
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (key <= nums[right] && key >= nums[mid]){
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
        
    }
};
