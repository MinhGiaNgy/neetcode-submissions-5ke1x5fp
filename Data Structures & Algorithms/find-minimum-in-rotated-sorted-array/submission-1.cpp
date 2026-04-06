class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        int ans = INT_MAX;
        while(right >= left){
            int mid = (right+left)/2;
            if(nums[mid] >= nums[right] && nums[mid] >= nums[left]){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            } 
            ans = min(ans, nums[mid]);
        }
        return ans;
    }
};
