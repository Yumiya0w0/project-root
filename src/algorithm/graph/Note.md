# Graph Advanced 
1. Topological Sort (Kahn's)  ✅
2. Topological Sort (DFS)     ✅ (skipped, understood)
3. Dijkstra                   ✅
4. Union Find                 ✅

| Problem               | Difficulty | Status | TC              | SC    | Notes |
|---|---|---|---|---|---|
| LC 207 Course Schedule| Medium     | ✅     | O(V+E)          | O(V+E)| Clean, comment said DFS not BFS |
| LC 743 Network Delay  | Medium     | ✅     | O((V+E)logV)    | O(V+E)| TC wrong initially |
| LC 547 Num Provinces  | Medium     | ✅     | O(V²)           | O(V)  | Two solutions, DFS modifies input |

## Graph Fundamentals

**Two ways to represent a graph:**

**1. Adjacency Matrix — O(V²) space**
```cpp
vector<vector<int>> matrix(n, vector<int>(n, 0));
matrix[u][v] = 1;  // edge u→v
```
Good for dense graphs, O(1) edge lookup. Rarely used in interviews.

**2. Adjacency List — O(V+E) space**
```cpp
vector<vector<int>> adj(n);
adj[u].push_back(v);  // edge u→v
```
Good for sparse graphs. **This is what you'll use in 99% of interview problems.**

---

**Directed vs Undirected:**
```cpp
// Directed (one way)
adj[u].push_back(v);

// Undirected (both ways)
adj[u].push_back(v);
adj[v].push_back(u);
```

**Weighted graph:**
```cpp
vector<vector<pair<int,int>>> adj(n);
adj[u].push_back({v, weight});
```

---

**Key graph terms:**
```
V = number of vertices/nodes
E = number of edges
In-degree  = number of edges coming IN to a node
Out-degree = number of edges going OUT of a node
DAG = Directed Acyclic Graph (no cycles)
```

---

Quick check before moving to Topological Sort:

Given `n=4, edges=[[0,1],[0,2],[1,3],[2,3]]`:
1. Draw the adjacency list
2. What's the in-degree of each node?