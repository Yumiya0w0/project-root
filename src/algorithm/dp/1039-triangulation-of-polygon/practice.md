- Thinking : how to avoid crossing diagonals
When you fix dp[i][j] as the subproblem (triangulate vertices i to j), and pick a third vertex k between i and j:

Triangle is (i, k, j)
Left subproblem: dp[i][k] — triangulate vertices i to k
Right subproblem: dp[k][j] — triangulate vertices k to j

The diagonals drawn are (i,k) and (k,j) — both are within the interval [i,j], so they cannot cross each other or any diagonal from subproblems.
Crossing is impossible because:

Left subproblem only draws diagonals within [i,k]
Right subproblem only draws diagonals within [k,j]
These two ranges don't overlap

The interval structure guarantees non-crossing by construction. 
triangulation for a side

`dp[i][j]`: min score of subgraph i, j
- initialization
```cpp
dp[i][j] = MAX_INT
dp[i][i] = 0
dp[i][i+1] = 0
```
- recurrence
```cpp
n = value.size
for nvertex = 3..n
    for i = 0..n-nvertex
    j = i+nvertex-1
        for k = i+1..j-1
            dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]+value[i]*value[j]*value[k])
return dp[0][n-1]
```