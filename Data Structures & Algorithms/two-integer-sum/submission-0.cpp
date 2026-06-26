class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0 ; i<n ; ++i){
            int look = target-nums[i];
            if(mp.find(look)!= mp.end()){
                res.push_back(i);
                res.push_back(mp[look]);
                break;
            }
            else mp[nums[i]] = i;
        }
        sort(res.begin() , res.end());
        return res;
    }
};
