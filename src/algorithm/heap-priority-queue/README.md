## Heap / Priority Queue — Fundamentals

**Heap** is a complete binary tree where every parent satisfies the heap property:
- **Min-heap:** parent ≤ children → top is always the minimum
- **Max-heap:** parent ≥ children → top is always the maximum

**Key operations — all O(log n):**
- `push` — insert element
- `pop` — remove top
- `top` — peek top (O(1))

## C++ API

STL `priority_queue` is a **max-heap by default**:

```cpp
// Max-heap (default)
priority_queue<int> maxpq;

// Min-heap
priority_queue<int, vector<int>, greater<int>> minpq;

// Custom comparator (e.g. pair, sorted by second element ascending)
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second; // min-heap by second, means "a has lower priority than b when a is larger"
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

// Operations
pq.push({1, 2});
pq.top();     // peek
pq.pop();     // remove top
pq.size();
pq.empty();
```

**Build from vector — O(n):**
```cpp
vector<int> v = {3,1,4,1,5};
priority_queue<int> pq(v.begin(), v.end());
```

---

## When to use min vs max heap:

```
Find K largest   → min-heap of size K (pop when size > K)
Find K smallest  → max-heap of size K (pop when size > K)
Always want min  → min-heap
Always want max  → max-heap
```

The trick: to keep K largest, maintain a **min-heap of size K** — the top is the smallest of the K largest, easy to compare and evict.

**Heap operation costs:**
|Operation|TC|Description|
|---|---|---|
|push        |O(log n)    |sift up|
|pop         |O(log n)    |sift down|
|top         |O(1)        |just read root|
|build heap  |O(n)        |from existing array (heapify)|

**Why O(n) build?** 
Intuitively, most nodes are near the bottom and need little sifting. The math works out to O(n) even though it seems like it should be O(n log n).

**Why O(log n) push/pop?** 
Tree height is log n, and you sift up/down at most one path from root to leaf.

## Heap / Priority Queue

### Progress Table
| Problem                     | Difficulty | Status | TC        | SC   | Notes |
|---|---|---|---|---|---|
| LC 215 Kth Largest Element  | Medium     | ✅     | O(nlogk)  | O(k) | Clean |
| LC 23 Merge K Sorted Lists  | Hard       | ✅     | O(nlogk)  | O(k) | Comparator syntax nudge |
| LC 253 Meeting Rooms II     | Medium     | ✅     | O(nlogn)  | O(n) | Clean |
| LC 295 Median from Stream   | Hard       | ✅     | O(nlogn)  | O(n) | Missing braces bug |
| LC 239 Sliding Window Max   | Hard       | ✅     | O(n)      | O(k) | Monotonic deque, not heap |

### Pattern Summary

**Top-K:** Maintain min-heap of size K. Evict when size exceeds K. Min-heap for K largest, max-heap for K smallest. TC O(n log k).

**K-way Merge:** Push first element of each list into min-heap. Each pop gives global minimum; push that node's next immediately. Heap size never exceeds K. TC O(n log k).

**Meeting Rooms II:** Sort intervals by start time. Min-heap tracks end times. If earliest end ≤ next start, reuse room (pop then push). Heap size = rooms in use. TC O(n log n).

**Two Heaps:** Max-heap for lower half, min-heap for upper half. Always push to lower first, rebalance to upper, rebalance back if sizes flip. Median is `lower.top()` or average of both tops. TC O(log n) per insert, O(1) median.

**Monotonic Deque:** Deque stores indices in decreasing value order. Front = window maximum. Pop front when out of window. Pop back when back value < current (permanently useless). TC O(n), SC O(k).

### Struggle Patterns
- None flagged for heap — strong session
- Always use braces for if/else (missing braces bug in LC 295)

