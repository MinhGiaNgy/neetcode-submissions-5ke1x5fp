class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(count.find(complement) != count.end()){
            return {count[complement], i};
            }
            count[nums[i]] = i;
        }
        return {};


    }
};
