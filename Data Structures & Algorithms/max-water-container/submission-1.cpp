class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int max_water = 0;
        int st = 0;
        int end = n-1;
        while(st<end){
            int water = min(h[st] , h[end])*(end-st);
            max_water = max(max_water , water);
            if (h[st] < h[end]) {
                st++;
            } else {
                end--;
            }
        }
        return max_water;
    }
};
