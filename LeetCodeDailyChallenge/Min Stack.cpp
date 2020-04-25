class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
        if (elements.empty())
            elements.push_back(x);
        else {
            int i = 0;
            for (; i < elements.size() && elements[i] <= x; i++);
            elements.insert(elements.begin() + i, x);
        }
    }
    
    void pop() {
        
        if (st.empty())
            return;
        
        int x = st.back();
        st.pop_back();
        
        int i =0;
        for (; i < elements.size() && elements[i] != x; i++);
        if (i == elements.size()) return;
        
        elements.erase(elements.begin() + i);
    }
    
    int top() {
        if (st.empty()) return -1;
        return st.back();
    }
    
    int getMin() {
        if (elements.empty()) return -1;
        return elements[0];
    }

private: 
    vector<int> st;
    vector<int> elements;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
