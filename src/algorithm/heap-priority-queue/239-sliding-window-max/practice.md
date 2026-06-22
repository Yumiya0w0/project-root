```cpp
deque<int> dq;  // stores indices, not values
for (int i = 0; i < n; i++) {
    // remove out-of-window elements
    if (!dq.empty() && dq.front() < i - k + 1)
        dq.pop_front();
    // maintain decreasing order (for max)
    while (!dq.empty() && nums[dq.back()] < nums[i])
        dq.pop_back();
    dq.push_back(i);
    // window is valid from index k-1 onwards
    if (i >= k - 1)
        result.push_back(nums[dq.front()]);
}
```
```
i=0, nums=1: dq=[0]
i=1, nums=3: 3>1 → pop 0, push 1 → dq=[1]       max=—
i=2, nums=-1: -1<3 → push 2 → dq=[1,2]           max=nums[1]=3
i=3, nums=-3: -3<-1 → push 3 → dq=[1,2,3]        max=nums[1]=3
i=4, nums=5: pop 3,2,1(all smaller), push 4→dq=[4] max=nums[4]=5
```
Key insight: Elements popped from the back are permanently useless — if nums[back] < nums[i], and i will outlive back in future windows, back can never be a maximum again.