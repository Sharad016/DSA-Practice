class Solution {
public:
    bool checkFreq(vector<int> &a , vector<int> &b){
        for(int i = 0 ; i<a.size() ;i++) if(a[i] != b[i]) return false;
        return true;
    }


    bool checkInclusion(string s1, string s2) {
        int n= s1.size();
        int m = s2.size();
        if(m<n) return false;

        vector<int> freq(26);
        for(int i=  0 ; i<n ; i++) freq[s1[i]-'a']++;
        
        int winSize = s1.size();
        vector<int> winFreq(26);
        for(int i = 0 ;i<winSize ;i++) winFreq[s2[i]-'a']++;

        int ptr = winSize-1;
        int l = 0;

        while(ptr<m){
            if(checkFreq(freq , winFreq)) return true;

            winFreq[s2[l]-'a']--;
            l++;
            ptr++;
            if(ptr<m) winFreq[s2[ptr]-'a']++;
        }

        return false;
    }
};
