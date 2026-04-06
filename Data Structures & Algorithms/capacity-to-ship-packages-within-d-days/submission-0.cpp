class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low{0};
        int high = 0;
        for(auto w : weights){
            low = max(w, low);
            high += w;
        }
        int ans = 0;
        while(high >= low){
            int total_days = 1;
            int mid = low + (high - low)/2;
            int tmp = mid;
            for(auto w : weights){
                if(w > tmp){
                    tmp = mid;
                    total_days++;
                }tmp -= w;
            }
            if(total_days > days){
                low = mid + 1;
            } else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};