class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int>m;
        string ans = "";
        int left = 0;
        int right = 0;
        while(right < s.size()){
            m[s[right]]++;
            if(m.size() > k){
                    m[s[left]]--;
                    if(m[s[left]] == 0) m.erase(s[left]);
                    left++;  
            } else if(m.size() <= k){
                if(right - left + 1 > ans.size()){
                    ans = s.substr(left, right - left + 1);
                    cout << ans << endl;
                }
            }
            right++;
        }
        return (int)(ans.size());
    }
};
