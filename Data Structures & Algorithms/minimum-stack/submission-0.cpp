class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        if(minstk.empty()){
            val = (val);
        } else {
            val = (std::min(val, minstk.top()));
        }
        minstk.push(val);
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
        
    }
};
