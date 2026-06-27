class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin() , nums.end());
        int streak = 0;
        for(int num : st){
            if(!st.count(num-1)){   // num-1 does not exists means it the starting of the sequence
                int curr_streak = 1;
                int curr_num = num;
                while(st.count(curr_num+1)){
                    curr_num+=1;
                    curr_streak+=1;
                }
                streak = max(curr_streak , streak);
            }
        }
        return streak;
    }
};
