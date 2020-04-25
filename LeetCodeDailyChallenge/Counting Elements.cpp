class Solution {
public:
    
    int countElements(vector<int>& arr) {
        
        map<int, int> hash;
        for (int i = 0; i < arr.size(); i++){
            if (hash.find(arr[i]) != hash.end()){
                hash.find(arr[i])->second++;
            }
            else {
                hash.insert(pair<int, int>(arr[i], 1));
            }
        }
        
        int count = 0;
        
        for (auto it = hash.begin(); it != hash.end(); ++it){
            int x = it->first;
            int x_count = it->second;
            if (hash.find(x + 1) != hash.end()){
                count += x_count;
            }
        }
        
        return count;
    }
};
