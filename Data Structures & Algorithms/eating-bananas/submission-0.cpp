class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1e9;
        int ans = 0;
        sort(piles.begin(), piles.end());
        while(high >= low){
            long long time = 0;
            int mid = low + (high - low) / 2;
            for(auto p : piles){
                time += (p + mid - 1) / mid; 
            }
            if(time > h){
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
