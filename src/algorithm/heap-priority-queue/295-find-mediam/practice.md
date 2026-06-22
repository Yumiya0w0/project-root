- Template
```cpp
priority_queue<int> lower;                              // max-heap
priority_queue<int, vector<int>, greater<int>> upper;   // min-heap

void addNum(int num) {
    lower.push(num);
    upper.push(lower.top()); lower.pop();  // balance
    if (lower.size() < upper.size())
        lower.push(upper.top()); upper.pop();
}

double findMedian() {
    if (lower.size() > upper.size())
        return lower.top();
    return (lower.top() + upper.top()) / 2.0;
}
```

```cpp
class MedianFinder {
public:
    priority_queue<int> lower; //max heap
    priority_queue<int, vector<int>, greater<>> upper; // min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lower.push(num);
        // to ensure all value in lower smaller than upper
        upper.push(lower.top()); lower.pop();
        // balance size for efficiency
        if (lower.size() < upper.size())
        {   lower.push(upper.top()); upper.pop(); }
    }
    double findMedian() {
        if(upper.empty() && lower.empty()) return 0;
        if(upper.size() < lower.size())
            return lower.top();
        return (lower.top()+upper.top()) / 2.0;
    }
};
```
