class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // Use a vector or array for O(1) access
        int n = s.size();
        int l = 0, maxlen = 0, maxFreq = 0;

        for (int r = 0; r < n; r++) {
            // 1. Expand the window: Add the current character
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            // 2. Check if the window is valid
            // (Window Size - Count of most frequent char) = number of chars to replace
            while ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
                // Note: We don't strictly need to update maxFreq here. 
                // The maxlen only increases when we find a new maxFreq.
            }

            // 3. Update the maximum length
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};