class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }


        vector<vector<int>> BUCKETS(nums.size() + 1);
        for(auto c : count){
            int number = c.first;
            int frequency = c.second;
            BUCKETS[frequency].push_back(number);

        }

        vector<int> result;
        for(int i = BUCKETS.size() - 1; i >0; i--){
            for(auto n : BUCKETS[i]){
                result.push_back(n);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
