You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

```cpp
slow = 0, fast = 0
freqMap[256]={0,...0}
maxLen=0
maxFreq=0
for (fast=0; fast < str.size; fast++)
{
    curChar=str[fast]
    freqMap[curChar]++
    maxFreq=max(maxFreq, freqMap[curChar])
    if(fast-slow+1 - maxFreq > k)
        slow++
    maxLen=max(maxLen, fast-slow+1)
}
return maxLen
```