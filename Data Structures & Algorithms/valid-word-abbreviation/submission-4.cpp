class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int idx1 = 0;
        int idx2 = 0;
        if(isdigit(abbr[idx2])){
            if((abbr[idx2] - '0') > (word.size())){
                return false;
            }
        }
        string num;
        while(idx2 < abbr.size()){
            if(isdigit(abbr[idx2])){
                num += abbr[idx2];
                if(num[0] == '0'){
                    cout << "third";
                    return false;
                }
                idx2++;
                continue;
            }
            if(!isdigit(abbr[idx2]) && !num.empty()){
                int add = stoi(num);
                if(add > word.size()-1){
                    cout << "second";
                    return false;
                    
                }
                idx1 += add;
                num.clear();
            } 
            if(isalpha(abbr[idx2])){
                cout << word[idx1] << endl;
                cout << abbr[idx2] << endl;
                if(word[idx1] != abbr[idx2]){
                    cout << "first";
                return false;
                }
            }
            idx1++;
            idx2++;
        }
        return true;
    }
};