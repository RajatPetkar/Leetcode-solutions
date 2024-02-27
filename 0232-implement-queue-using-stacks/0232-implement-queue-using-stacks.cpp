
class MyQueue {
public:
    stack<int> inbox,outbox;

    // int front = -1;
    // int rear = 0;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        inbox.push(x);
    }
    
    int pop() {
        if (outbox.empty()) { 
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        int frontElement = outbox.top(); 
        outbox.pop(); 
        return frontElement;
    }
    
    int peek() {
        if (outbox.empty()) { 
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        return outbox.top();
    }
    
    bool empty() {
        return inbox.empty() && outbox.empty();
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