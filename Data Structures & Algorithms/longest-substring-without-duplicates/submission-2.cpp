class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0;
        int l = 0;
        int ans{0};
        unordered_map<char, int> m;
        while(r < s.size()){
            if(m.find(s[r]) != m.end()){
                l = max(m[s[r]] + 1, l);
            }
            m[s[r]] = r;
            ans = max(ans, r - l + 1);
            r++;
            
        
        }
        return ans;
        
    }
};
