class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int> sums;
        
        int curSum = 0;
        int counter = 0;
        
        for (auto it = nums.begin(); it != nums.end(); ++it){
            curSum += (*it);
            
            if (sums.find(curSum - k) != sums.end())
                counter += sums.find(curSum - k)->second; 
            
            if (curSum == k)
                counter++;
            
            if (sums.find(curSum) != sums.end())
                sums.find(curSum)->second++;
            else 
                sums.insert(pair<int, int>(curSum, 1));
        }
        
        return counter;
    }
};
