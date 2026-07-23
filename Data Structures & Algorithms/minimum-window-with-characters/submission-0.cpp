class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int tn = t.size();
        vector<int> hash(256 , 0);
        int r=0;
        int l=0;
        int minl = 1e9;
        for(char ch : t){
            hash[ch] ++;
        }
        int cnt  = 0;
        int sInd = -1;
        while(r<n){
            if(hash[s[r]] > 0){
                cnt ++;
            }
            hash[s[r]]--;
            while(cnt==tn){
                if(r-l+1 < minl){
                    minl = r-l+1;
                    sInd = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(sInd == -1) return "";
        return s.substr(sInd , minl);
    }
};