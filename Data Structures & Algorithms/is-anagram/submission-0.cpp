class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> S(26);
        vector<int> T(26);
        if(s.size()!=t.size()) return false;
        for(int i = 0 ; i<s.size() ; i++){
            S[s[i]-'a']++;
            T[t[i]-'a']++;
        }
        for(int i = 0 ; i<26 ; ++i){
            if(S[i]!=T[i]){
                return false;
                break;
            }
        }
        return true;
    }
};
