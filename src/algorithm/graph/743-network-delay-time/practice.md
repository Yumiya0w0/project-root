## Pattern 3 — Dijkstra (Shortest Path)

**Core idea:** Greedily pick the unvisited node with smallest distance. Use min-heap for efficiency.

**Template:**
```cpp
vector<int> dijkstra(int src, int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<>> minpq;  // {dist, node}
    
    dist[src] = 0;
    minpq.push({0, src});
    
    while (!minpq.empty()) {
        auto [d, u] = minpq.top(); minpq.pop();
        if (d > dist[u]) continue;  // stale entry, skip
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                minpq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

**Key details:**
- `{dist, node}` order in pair — heap sorts by first element
- `if (d > dist[u]) continue` — lazy deletion of stale entries
- Only works with **non-negative weights**

---

**LC 743 — Network Delay Time**

> There are `n` nodes. Given weighted directed edges `times[i] = [u, v, w]`, find the minimum time for signal from node `k` to reach all nodes. Return `-1` if impossible.
>
> `times=[[2,1,1],[2,3,1],[3,4,1]], n=4, k=2` → `2`

Two questions before coding:
1. Why `if (d > dist[u]) continue`?
2. Why doesn't Dijkstra work with negative weights?

```cpp
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // form the graph
    vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());// first: dist, sec: node
    for (auto t: times) // map 1-base to 0-base
    {
        adj[t[0]-1].push_back({t[2], t[1]-1});
    }
    // min pq, vec of dist to target node,
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<>> minH;  // {dist, node}

    // to init min heap, push (k, 0)
    dist[k-1] = 0; 
    minH.push({0, k-1});
    while (!minH.empty())
    {
        // u -> v
        auto [d, u] = minH.top(); minH.pop();
        if (d > dist[u]) continue; 
        for(auto [w, v]: adj[u])
        {
            if (dist[u]+w < dist[v])
            {
                dist[v] = dist[u]+w;
                minH.push({dist[v], v});
            }
        }
    }

    long int maxD = -1;
    for (auto d: dist)
        maxD = max(maxD, d);
    return maxD == INT_MAX ? -1 : maxD;
}
```

## Complexity
- TC: `O((ElogV + VlogV))`
- sC: `O(V+E)`
