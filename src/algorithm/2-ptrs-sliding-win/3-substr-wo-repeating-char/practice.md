Given a string s, find the length of the longest substring without duplicate characters.

```cpp
slow=0, fast=0
maxLen = 0
lastSeen[256]={-1,...,-1}
for(fast = 0; fast < str.size; fast++)
    if slow <= lastSeen[str[fast]] && lastSeen[str[fast]] <= fast
        slow = lastSeen[str[fast]]+1
    maxLen = max(fast-slow+1, maxLen)
    lastSeen[str[fast]] = fast;
return maxLen
```