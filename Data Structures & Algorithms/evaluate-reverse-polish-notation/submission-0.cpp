class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> storage;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
            int b = storage.top();
            storage.pop();
            int a = storage.top();
            storage.pop();
            if(tokens[i] == "+"){
                storage.push(a + b);
            }
            else if(tokens[i] == "*"){
                storage.push(a * b);
            }
            else if(tokens[i] == "-"){
                storage.push(a - b);
            }
            else if(tokens[i] == "/"){
                storage.push(a / b);
            }
            }
            else {
                storage.push(stoi(tokens[i]));
            }
        }
        return storage.top();
        
    }
};
