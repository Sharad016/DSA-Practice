class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int st=0;
        int end=num.size()-1;
        vector<int> res;
        while(st<end){
            if((num[st] + num[end]) > target) end--;
            else if((num[st] + num[end]) < target) st++;
            else{
                res.push_back(st+1);
                res.push_back(end+1);
                break;
            }
        }
        return res;
    }
};
