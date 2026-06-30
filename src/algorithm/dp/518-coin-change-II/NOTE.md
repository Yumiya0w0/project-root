# Records

## 2026-06-28
### NOTE
- Base case is wrong — dp[c]=1 doesn't handle all cases. What if a coin value is reachable multiple ways? Init dp[0]=1 instead — "one way to make amount 0 (use no coins)". Everything else starts at 0.
- Recurrence is wrong — if dp[i-c]>0, dp[i]++ only adds 1 per coin, but you want to add all ways to reach i-c. Should be dp[i] += dp[i-c].
- Coins outer, amount inner — for each coin, update all amounts. Each coin is considered independently before moving to next. This counts combinations (order doesn't matter): [1,2] and [2,1] are the same.
- Amount outer, coins inner — for each amount, try all coins. This counts permutations (order matters): [1,2] and [2,1] are different.

### Explanation
- `dp[i]` = combinations of `amount=i`
- base case: `dp[0]=1`
- recursion: `dp[i]+=dp[i-c]`
- outer loop: coin
- inner loop: amount

### Code
```cpp
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);
    dp[0]=1;
    for (int c: coins)
    {
        for (int i = 1; i <= amount; i++)
        {
            if (i-c >= 0)
                dp[i] += dp[i-c];
        }
    }
    return dp[amount];
}
```
