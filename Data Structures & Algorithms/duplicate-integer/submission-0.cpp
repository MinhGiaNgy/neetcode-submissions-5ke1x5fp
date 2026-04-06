class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num : nums){
            m[num]++;
            std::cout << m[num];
            if(m[num] > 1){
                return true;
            }
        }
        return 0;

    }
};
