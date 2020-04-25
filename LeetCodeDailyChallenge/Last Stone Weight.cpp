class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        sort(stones.begin(), stones.end());
        
        while (stones.size() > 1){
            int n = stones.size();
            
            int x = stones[n - 1];
            int y = stones[n - 2];
            
            if (x == y){
                stones.pop_back();
                stones.pop_back();
                continue;
            }
            
            if (x < y)
                x = y - x;
            else 
                x= x - y;
            
            stones.pop_back();
            stones.pop_back();
            
            int i = 0;
            for (; i < stones.size() && stones[i] < x; i++);
            stones.insert(stones.begin() + i, x);
            
        }
        
        if (stones.size() == 0) return 0;
        return stones.front();
    }
};
