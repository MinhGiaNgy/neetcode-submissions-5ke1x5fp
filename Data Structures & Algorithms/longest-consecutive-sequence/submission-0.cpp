class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int num : s){
            if(s.find(num - 1) == s.end()){
                int streak = 1;
                while(s.find(num + streak) != s.end()){
                    streak++;
                }
                longest = max(streak, longest);
            }
        }
        
        return longest;
    }
};
