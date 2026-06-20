# Practice Progress

## Ongoing Practice Areas
### Current focus
- Dynamic Programming (L4 Google prep)

### Latest updates
## Session: Dynamic Programming (Date: 2026-06-15 ~ 2026-06-20)

### Problems Solved
| Problem | Difficulty | Status | TC | SC | Notes |
|---|---|---|---|---|---|
| LC 70 Climbing Stairs | Easy | ✅ | O(n) | O(1) | Optimized to O(1) space unprompted |
| LC 198 House Robber | Easy | ✅ | O(n) | O(1) | Clean, no issues |
| LC 300 LIS | Medium | ✅ | O(n²) | O(n) | Needed nudge on dp[i]=1 init and max() vs overwrite |
| LC 53 Max Subarray | Easy | ✅ | O(n) | O(1) | Clean, caught all-negative case |
| LC 62 Unique Paths | Medium | ✅ | O(m×n) | O(n) | Optimized to 1D unprompted |
| LC 1143 LCS | Medium | ⚠️ | O(m×n) | O(m×n) | Needed pattern explanation, dry run correct |
| LC 322 Coin Change | Medium | ⚠️ | O(W×n) | O(W) | Needed Q1→Q3 scaffolding, sentinel value nudge |
| LC 312 Burst Balloons | Hard | ⚠️ | O(n³) | O(n²) | Confused dp values vs nums in cost, needed boundary explanation |
| LC 72 Edit Distance          | Medium | ✅ | O(nm) | O(nm) | Needed nudge on insert=dp[i][j-1] intuition |
| LC 416 Partition Equal Subset| Medium | ⚠️ | O(nW) | O(W)  | Missed skip option; 0/1 vs unbounded loop direction |
| LC 1039 Polygon Triangulation| Hard   | ✅ | O(n³) | O(n²) | Clean after interval DP explanation |

### Struggle Patterns
- LCS / 2D subsequence DP — recurrence intuition
- Knapsack formulation from scratch
- Interval DP cost function construction
- Sentinel initialization (MAX_INT vs -1)
- dp[i] initialization before inner loop
- 0/1 vs unbounded knapsack loop direction
  → 0/1: iterate w backwards (prevent reuse)
  → Unbounded: iterate w forwards (allow reuse)
  → Forward reads updated values = item reusable
  → Backward reads original values = item used once

### Strengths
- Space optimization (1D rolling array) — consistently unprompted
- Base case reasoning
- Self-correction (found greedy counterexample independently)
#### 2026-06-04
- 70-Climbing Stairs
- 198-House Robber

## Completed Practice Areas
- `src/algorithm/BFS-DFS`
  - BFS/DFS practice file
  - 130-surrounded-region pseudo plan
  - 132-clone-graph pseudo plan
  - 200-islands-nums implementation
  - 207-Course-Schedule practice and pseudo code
  - 695-Max-area-island
  - 1254-num-closed-island
  - 3619-divisible-island
- `src/algorithm/binary-search`
  - Rotated array minimum, peak finding, rotated array search
  - First/last in sorted array
  - Search matrix and Koko banana problems
- `src/data-structure/array`
  - Jug rotate and rotate array solutions
  - Longest substring, reverse sentence, rotate matrix practice and solutions
- `src/data-structure/link-list`
  - Reverse linked list implementation
- `src/data-structure/queue`
  - FIFO queue practice and thread-safe queue code
  - String decode practice and solution
- `src/embedded/bit-wise`
  - Bit-wise operations and reverse/subsets examples
- `src/embedded/ISR`
  - ISR solution implementation
- `src/embedded/memory`
  - Memory alignment practice code
- `src/sprint`
  - Sprint practice files for bit operations and warm-up exercises
