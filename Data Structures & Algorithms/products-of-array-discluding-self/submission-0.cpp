class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products((nums.size()), 1);
        for(int i = 1; i < nums.size(); i++){
            products[i] = products[i - 1] * nums[i - 1];
        }
        
        int right = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--){
            products[i] *= right;
            right *= nums[i];
        }
        return products;

    }
};
