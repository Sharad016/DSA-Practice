class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> hash;
        for(int val : nums) hash[val]++;
        int n = nums.size();
        vector<vector<int>> buckets(n+1); 
        for(auto& [ele , freq] : hash){
            buckets[freq].push_back(ele);
        }
        vector<int> res;
        for(int i = n ; i>=0 ; i--){
            for(int num : buckets[i]){
                res.push_back(num);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};
