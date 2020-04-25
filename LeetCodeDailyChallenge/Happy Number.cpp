class Solution {
public:
    int sumOfSquareDigits(int n){
        int sum = 0;
        
        while (n > 0){
            sum += ((n % 10)*(n % 10));
            n = n / 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        
        vector<int> seen;
        
        while(n > 0){
            int sq = sumOfSquareDigits(n);
            
            if (sq == 1) return true;
            
            for (auto it = seen.begin(); it != seen.end(); ++it){
                if ((*it) == sq) 
                    return false;
            }
            
            seen.push_back(sq);
            
            n = sq;
        }
        
        return false;
    }
};
