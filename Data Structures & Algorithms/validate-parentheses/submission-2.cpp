class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                stack.push(s[i]);
            }
            if(s[i] == '}'){
                if(stack.size() == 0 || stack.top() != '{'){
                    return false;
                }
                stack.pop();
            }
            if(s[i] == ')'){
                if(stack.size() == 0 || stack.top() != '('){
                    return false;
                }
                stack.pop();
            }
            if(s[i] == ']'){
                if(stack.size() == 0 || stack.top() != '['){
                    return false;
                } 
                stack.pop();
            }
            
            
        }
        if(stack.size()){
            return false;
        }
        return true;
        
    }
};
