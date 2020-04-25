#include <string>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> m;
        
        for(auto it = strs.begin(); it != strs.end(); ++it){
            string s = (*it);
            sort(s.begin(), s.end());
            if (m.find(s) != m.end()){
                (m.find(s)->second).push_back(*it);
            }
            else {
                vector<string> v;
                v.push_back(*it);
                m.insert(pair<string, vector<string>>(s, v));
            }      
        }
        
        vector<vector<string>> ret;
        for (auto it = m.begin(); it != m.end(); ++it) { 
            ret.push_back(it->second);
        } 
        
        return ret;
    }
};
