class MyCircularQueue {
private:
    vector<int> arr;
    int front;
    int rear;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        arr.resize(k);
        front = -1;
        rear = -1;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */