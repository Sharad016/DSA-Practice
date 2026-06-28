class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // Step 2: Skip duplicate values for the anchor element 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Step 3: Two-pointer approach for the remaining two elements
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Step 4: Skip duplicates for 'left' and 'right' pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move both pointers inward after finding a valid triplet
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Sum is too small, move left pointer to increase it
                } 
                else {
                    right--; // Sum is too large, move right pointer to decrease it
                }
            }
        }
        return res;
    }
};