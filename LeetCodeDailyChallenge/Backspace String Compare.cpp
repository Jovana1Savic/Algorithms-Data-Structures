class Solution {
public:
    
    string trimString(string s){
        string ret = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '#'){
               if (ret.size() > 0) 
                   ret.pop_back();
            }
            else 
                ret.push_back(s[i]);
        }
        
        return ret;
    }
    
    bool backspaceCompare(string S, string T) {
        
        S = trimString(S);
        T = trimString(T);
        
        if (S.size() != T.size()) 
            return false;
        
        for (int i = 0; i < S.size(); i++){
            if (S[i] != T[i])
                return false;
        }
        
        return true;
    }
};
