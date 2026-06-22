1. sort and push by start time
2. pop by end time

`sort` on `vector<vector<int>>` uses lexicographic comparison by default, so it compares intervals[i][0] first, then intervals[i][1] if tied. 

```cpp
int requiredRooms(vector<vector<int>> intervals)
{
    sort(intervals.begin(), intervals.end()); // sort by start time
    priority_queue<int, vector<int>, greater<int>> minpq; // min-heap of end times
    
    for (auto& interval : intervals) {
        if (!minpq.empty() && minpq.top() <= interval[0])
            minpq.pop();  // reuse room
        minpq.push(interval[1]);  // assign room, track end time
    }
    return minpq.size();  // number of rooms used
}
```