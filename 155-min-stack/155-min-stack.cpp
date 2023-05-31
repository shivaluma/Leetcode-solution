class MinStack {
public:

    stack<int> st1, st2;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st1.size() == 0) {
            st1.push(val);
        } else {
            if (val <= st1.top()) {
                st1.push(val);
            }
        }

        st2.push(val);
    }
    
    void pop() {
        if (st2.top() == st1.top()) {
            st1.pop();
        }

        st2.pop();
    }
    
    int top() {
        return st2.top();
    }
    
    int getMin() {
        return st1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */