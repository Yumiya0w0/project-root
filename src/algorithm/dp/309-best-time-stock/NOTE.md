# Records

## 2026-06-29
### NOTE
- hold = max profit when holding stock
- sold = max profit when just sold (cooldown next)
- rest = max profit when resting/cooldown
```
hold = max(hold, rest - price)  // keep holding or buy from rest
sold = hold + price              // sell today
rest = max(rest, sold)           // keep resting or finish cooldown
```
> buy from rest: come up with is hard for me

**hold today = either:**  
  - I was holding yesterday (do nothing)
  - I was resting yesterday and buy today

**sold today = either:**
  - I was holding yesterday and sell today

**rest today = either:**
  - I was resting yesterday (do nothing)
  - I was in sold yesterday (cooldown finished)

### Explanation
- dp[i], size=n+1 : max profit at day i
- state[i] : hold/sell/cool at day i
- Base case: dp[0]=0, state[0]=cool
- Recurrence: dp[i]=

### Code
```cpp
int maxProfit(vector<int>& prices) {
    int hold=INT_MIN, sold=0, cool=0;
    for(int p: prices) {
        int prevSold=sold;
        sold=hold+p; // hold init with int min make it subtle at day 0
        hold=max(hold, rest-p);
        rest=max(rest, prevSold);
    }
    return max(max(sold, hold), rest);
}
```
