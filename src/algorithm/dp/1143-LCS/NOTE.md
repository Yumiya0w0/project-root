# Records
## How to explain?
### The 4-Step Explanation Framework

**1. Restate the problem in your own words** (30 sec)
> "So we have two strings and we want to find the longest subsequence that appears in both — not necessarily contiguous."

**2. State the approach + why** (30 sec)
> "This is a classic 2D DP problem. I'll define `dp[i][j]` as the LCS of the first `i` characters of `text1` and first `j` characters of `text2`."

**3. Walk through the recurrence** (1 min)
> "At each cell, I have two cases:
> - If `text1[i-1] == text2[j-1]`, the characters match, so I extend the previous LCS: `dp[i][j] = dp[i-1][j-1] + 1`
> - Otherwise I can't use both characters, so I take the best from either skipping `text1[i]` or skipping `text2[j]`: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`"

**4. State base case + TC/SC** (30 sec)
> "Base case: empty string matches nothing, so row 0 and col 0 are all 0. TC is O(m×n), SC is O(m×n), optimizable to O(n) with a rolling array."

---

### Example — LCS full explanation out loud:

> "I'd approach this with 2D DP. Let me define `dp[i][j]` as the LCS length for `text1[0..i-1]` and `text2[0..j-1]`. 
>
> For each pair of characters: if they match, I extend the diagonal — `dp[i][j] = dp[i-1][j-1] + 1`. If not, I take the best of skipping either character — `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
>
> Base cases are row 0 and col 0 initialized to 0 — empty string has no common subsequence with anything.
>
> Final answer is `dp[m][n]`. TC O(m×n), SC O(m×n)."

That's about 2 minutes — exactly right for a medium DP problem.

---

### Common mistakes in explaining:

```
❌ "I'll use DP"          → too vague
✅ "I'll use 2D DP where dp[i][j] represents..."

❌ Jump straight to code  → interviewer can't follow
✅ Explain recurrence first, then code

❌ Forget base cases      → always mention them
✅ "Base case is... because..."

❌ TC/SC at the end       → mention before coding
✅ "This will be O(mn) time and space"
```

---

### Template sentence starters:

```
"I'd approach this with..."
"Let me define dp[i][j] as..."
"The recurrence is... because..."
"Base case is... because..."
"This gives us TC of... SC of..."
"One optimization would be..."
```

## 2026-06-28
### NOTE
- What is `dp[i][j]`?
- If char match, `dp[i][j]=?`, else?
### Explanation
- Add padding for initialization and base case
- `dp[i][j]` = LCS of `s1[0..i-1]` and `s2[0..j-1]`
### Code
```cpp
int lcs(string s1, string s2) {
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for(int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]); // skip c of s1 or s2
        }
    }
    return dp[s1.size()][s2.size()];
}
```

## 2026-06-15
### NOTE
>empty
### Code
```cpp
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
```
