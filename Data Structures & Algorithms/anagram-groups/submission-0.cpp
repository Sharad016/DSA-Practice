class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> hash(strs);
        int i = 0;
        for(string str : hash){
            sort(str.begin() , str.end());
            hash[i] = str;
            i++;
        }
        vector<vector<string>> res;
        vector<bool> visited(hash.size(), false);
        for(int j = 0 ; j<hash.size() ; j++){
            if(visited[j]) continue;
            vector<string> temp;
            temp.push_back(strs[j]);
            visited[j] = true;
            for(int k = j + 1 ; k<hash.size() ; k++){
                if(!visited[k] && hash[k]==hash[j]) {
                    temp.push_back(strs[k]);
                    visited[k] = true;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
