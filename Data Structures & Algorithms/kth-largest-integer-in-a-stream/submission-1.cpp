class KthLargest {
priority_queue<int , vector<int> , greater<int>> pq;
int gk;
public:
    KthLargest(int k, vector<int>& nums) {
        gk = k;
        int n = nums.size();
        for(auto &num : nums){
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>gk) pq.pop();
        return pq.top();
    }
};
