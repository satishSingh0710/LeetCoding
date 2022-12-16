class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (!s2.empty()){
            int x = s2.top();
            s2.pop();
            return x;
        }else{
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            
            int x = s2.top();
            s2.pop();
            return x;
        }
    }
    
    int peek() {
        
        if (!s2.empty()){
            return s2.top();
        }else{
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            
            return s2.top();
        }
    }
    
    bool empty() {
        if (s1.empty() && s2.empty()){
            return true;
        }else{
            return false;
        }
    }
};
