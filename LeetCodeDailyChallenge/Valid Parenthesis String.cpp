class Solution {
public:
    bool checkValidString(string s) {
        
        int openBrackets = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] =='(' || s[i] == '*')
                openBrackets++;
            else 
                openBrackets--;
            
            // If open + asterix < closed 
            if (openBrackets < 0) return false;
        }
        
        if (openBrackets == 0) return true;
        
        int closedBrackets = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == ')' || s[i] == '*')
                closedBrackets++;
            else 
                closedBrackets--;
            
            if (closedBrackets < 0) return false;
        }
        
        return true;
        
        
    }
};
