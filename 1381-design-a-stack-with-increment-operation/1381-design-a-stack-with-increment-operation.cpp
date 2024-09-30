
class CustomStack {
    private:
    int* stack;       
    int top;         
    int maxSize;      

    public:
        CustomStack(int maxSize) {
            this->stack = new int[maxSize];  
            this->top = -1;                  
            this->maxSize = maxSize;         
        }
        
        ~CustomStack() {
            delete[] stack; 
        }
        
        void push(int x) {
            if (top < maxSize - 1) {  
                top++;
                stack[top] = x;      
            }
        }
        
        int pop() {
            if (top != -1) {         
                return stack[top--];  
            }
            return -1;               
        }
        
        void increment(int k, int val) {
            int limit = std::min(k, top + 1); 
            for (int i = 0; i < limit; i++) {
                stack[i] += val; 
            }
        }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */