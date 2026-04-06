class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            if(n <= 1) return nums[0];
            else {
                return max(nums[0], nums[1]);
            }
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i = 2; i < n - 1;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int ans = dp[n-2];
        vector<int> dp2(n, 0);
        dp2[0] = 0;
        dp2[1] = max(dp2[0],nums[1]);
        for(int i = 2; i < n;i++){
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        ans = max(ans, dp2[n-1]);
        return ans;

    }
};
