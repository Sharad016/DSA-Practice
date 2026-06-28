class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> res;
        set<vector<int>> dup;
        for(int i=0;i<n;++i){
            int target = -nums[i];
            unordered_set<int> st;
            for(int j=i+1 ; j<n ;j++){
                int to_find = target-nums[j];
                if(st.find(to_find)!=st.end()){
                    vector<int> temp;
                    temp.push_back(to_find);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[i]);
                    sort(temp.begin() , temp.end());
                    if(dup.find(temp)==dup.end()) res.push_back(temp);
                    dup.insert(temp);
                }
                st.insert(nums[j]);
            }
        }
        return res;
    }
};
