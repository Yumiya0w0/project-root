1. Do sort
2. Traverse i=0..n-1, find 2Sum of `0-num[i]`
3. Skip duplicated

```cpp
// 2 Sum
2sum (int tar, vector<int>& n, int start)
    int l = start+1
    int r = n.size-1
    while l < r
        int sum=n[l]+n[r]
        if sum > tar
            // shrink from r
        else if sum < tar 
            // shrink from l
        else
            ret.push(n[start], n[l], n[r])
    return ret
```