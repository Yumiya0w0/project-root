# Records

## 2026-06-29
### NOTE
- we should find palindromic sub-sequence just like LCS
- Minimum insertions = n - LPS 
- LPS = Longest Palindromic Subsequence

And LPS = LCS of s and reverse(s).
### Explanation

### Code
```cpp
int minInsertions(string s) {
    int n = s.size();
    string rs = s;
    reverse(rs.begin(), rs.end());
    vector<vector<int>> dp(n+1, vector<int>(0, n+1));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (s[i] == rs[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return n - dp[n][n];
}
```
