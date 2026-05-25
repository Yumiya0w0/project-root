const int capacity = 100;
class circularQueue {
private:
    int data[capacity];
    int head = 0; 
    int tail = 0;
    int size = 0;
public:
    circularQueue(){};
    ~circularQueue(){};
    int front();
    int rear();
    bool isEmpty();
    bool isFull();
    bool enQueue(int value);
    bool deQueue();
};

bool circularQueue::isEmpty()
{
    return (size == 0) ? true : false;
}

bool circularQueue::isFull()
{
    return (size == capacity) ? true : false;
}

int circularQueue::front()
{
    if(this->isEmpty()) return -1;
    return data[head];
}

int circularQueue::rear()
{
    if(this->isEmpty()) return -1;
    return data[(tail-1+capacity)%capacity];
}

bool circularQueue::enQueue(int value)
{
    if(this->isFull()) return false;
    data[tail] = value;
    tail = (tail+1)%capacity;
    size++;
    return true;
}

bool circularQueue::deQueue()
{
    if(this->isEmpty()) return false;
    head = (head+1)%capacity;
    size--;
    return true;
}
