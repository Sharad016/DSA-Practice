class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int val : nums){
            if(st.find(val) != st.end()){
                return true;
                break;
            }
            else st.insert(val);
        }
        return false;
    }
};