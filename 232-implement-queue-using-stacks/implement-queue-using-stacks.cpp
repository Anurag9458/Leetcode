class MyQueue {
    stack<int>st1,st2;

public:
    MyQueue() {
        while(!st1.empty()){
            st1.pop();
        }
        while(!st2.empty()){
            st2.pop();
        }
    }
    
    void push(int x) {
        // cout<<st1.size();
        st1.push(x);
        
    }
    
    int pop() {
        if(st1.empty()){
            return 0;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int ans=st2.top();
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    int peek() {
        if(st1.empty()){
            return 0;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int ans=st2.top();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */