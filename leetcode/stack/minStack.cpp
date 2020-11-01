class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> aux;
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        if(aux.size()==0 || x<=aux[aux.size()-1]) //not x< as it will create problem 
                                                //for pop() and getMin() in this order
        {
            aux.push_back(x);
        }
    }
    
    void pop() {
        if(stack[stack.size()-1]==aux[aux.size()-1])
            aux.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return aux[aux.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
