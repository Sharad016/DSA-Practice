class Solution {
public:
    int solve(int i , vector<int> &arr , vector<int> &dp){
        if(i<0) return 0;
        if(i==0) return arr[i];
        if(dp[i] != -1) return dp[i];
        int not_take = 0 + solve(i-1 , arr , dp);
        int take = arr[i] + solve(i-2 , arr , dp); // not take next index
        return dp[i] = max(not_take , take);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        return solve(n-1 , nums , dp);
    }
};
