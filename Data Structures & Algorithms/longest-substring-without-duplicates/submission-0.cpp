class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int max_size = 0;
        int i = 0;
        int j = 0;
        int size = 0;
        while(i<s.size()){
            if(seen.find(s[i])==seen.end()){
                size++;
                seen.insert(s[i]);
                i++;
            }
            max_size = max(size , max_size);
            if(seen.find(s[i])!=seen.end()){
                while(seen.find(s[i])!=seen.end()){
                    seen.erase(s[j]);
                    j++;
                    size--;
                }
            }
        }
        return max_size;
    }
};
