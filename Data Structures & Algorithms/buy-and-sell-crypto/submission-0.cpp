class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val=prices[0];
        int max_pro = 0;
        for(int val : prices){
            int profit = val-min_val;
            max_pro = max(profit , max_pro);
            if(min_val > val) min_val=val;
        }
        return max_pro;
    }
};
