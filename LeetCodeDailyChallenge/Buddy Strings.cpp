// Original problem statement : https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3492/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if (A.size() != B.size()) return false;
        
        vector<int> map(26,0);
        
        int ind1 = -1, ind2 = -1;
        for(int i = 0; i < A.size(); i++){
            if (A[i] == B[i]){
                map[A[i] - 'a']++;
                continue;
            }
            if (ind1 == -1){
                ind1 = i;
                continue;
            }
            if (ind2 == -1){
                ind2 = i;
                continue;
            }
            return false;
        }
        
        if (ind1 == -1 && ind2 == -1){
            for(int i = 0; i < 26; i++){
                if (map[i] >= 2) return true;
            }
            return false;
        }
        if (ind1 == -1 || ind2 == -1) return false;
        
        if (A[ind1] == B[ind2] && A[ind2] == B[ind1]) return true;
        
        return false;
    }
};
