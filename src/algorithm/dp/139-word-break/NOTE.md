## 2026-06-28
### NOTE
- index match in for loop:
  O: for i=0..n-1
  X: for i=1..n
- optimize w/ unorder map?
### Explanation
- match every word in dict for every position of string. 
- bool dp[i] : can match a word at breakpoint i 
### Code
```cpp
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1, false);
    dp[0]=true;
    for (int i = 0; i < s.size(); i++)
    {
        if (!dp[i]) continue;
        for (string w: wordDict)
        {
            int size = w.size();
            if (i + size <= n && s.substr(i, size) == word) 
                dp[i + size] = true;
        }
    }
    return dp[s.size()];
}
```