// Original problem statement: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> map(26,0);
        vector<bool> on_stack(26, false);
        
        for(char& c : s){
            map[c - 'a']++;
        }
        
        stack<char> st;
        
        for(char& c : s){
            
            if (map[c - 'a'] == 0) continue;
            
            if (on_stack[c - 'a']){
                map[c-'a']--;
                continue;
            }
            
            while(!st.empty() && st.top() > c && map[st.top() - 'a'] > 0){
                on_stack[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(c);
            on_stack[c - 'a'] = true;
            map[c - 'a']--;
        }
        
        string ret(st.size(), '*');
        for(int i = ret.size() - 1; i >= 0; i--){
            ret[i] = st.top();
            st.pop();
        }
        
        return ret;
    }
};
