class Solution {
public:

    string encode(vector<string>& strs) {
        string enc_str = "";
        for(const string& st : strs){
            enc_str += to_string(st.size()) + "#" + st;
        }
        return enc_str;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i<s.size()){
            int j = i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i , j-i));
            i = j+1;
            res.push_back(s.substr(i , len));
            i += len;
        }
        return res;
    }
};
