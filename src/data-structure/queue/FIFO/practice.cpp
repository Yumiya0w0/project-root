#include <limits.h>
// Circular Ring Buff
const int cap = 128;
class CircularQueue
{
public:
    CircularQueue(){};
    bool isFull() { return full; }
    bool isEmpty() { return (tail == head) && !full;}
    int top() { return (isEmpty() ? std::numeric_limits<int>::quiet_NaN() : data[head]); };
    void pop() 
    {
        if(isEmpty()) { return; }
        head = (head + 1) % cap;
        full = false;
    };
    void push(int val){
        if(isFull()) { return; }
        data[tail] = val;
        tail = (tail + 1) % cap;
        if(tail == head) full = true;
    }
private:
    unsigned int head = 0; // pos to read
    unsigned int tail = 0; // pos to write
    bool full = false;
    int data[cap];
};

