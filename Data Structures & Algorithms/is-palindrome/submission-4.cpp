class Solution {
public:
    bool isPalindrome(string s) {
        string og;
        string palin;
        for(size_t i = 0; i < s.size(); i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                og += tolower(s[i]);
            }
        }
        for(int j = og.size() - 1; j >= 0; j--){
            palin += og[j];
        }
        if(palin == og){
            return true;
        }
        return false;
        
    }
};