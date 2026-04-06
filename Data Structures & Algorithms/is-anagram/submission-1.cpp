class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> strings_of_s;
        unordered_map<char,int> strings_of_t;
        for(int i = 0; i < s.size(); i++){
            strings_of_s[s[i]]++;
        

            strings_of_t[t[i]]++;
        }
        return strings_of_s == strings_of_t;
        
    }
};
