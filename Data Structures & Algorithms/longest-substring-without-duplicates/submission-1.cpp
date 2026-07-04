class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int max_size = 0;
        int i = 0;
        int j = 0;
        
        while (i < s.size()) {
            // If the character is not in the set, it's unique
            if (seen.find(s[i]) == seen.end()) {
                seen.insert(s[i]);
                i++; // Move right pointer forward
                max_size = max(max_size, i - j); // Window size is (i - j)
            } 
            // If it's a duplicate, shrink the window from the left
            else {
                seen.erase(s[j]);
                j++; // Move left pointer forward
            }
        }
        return max_size;
    }
};