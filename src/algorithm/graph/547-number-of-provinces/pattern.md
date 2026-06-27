## Pattern 4 — Union Find

**Core idea:** Track connected components. Two operations: `find` (which component?) and `union` (merge two components).
Good question — let me make it concrete.

**`parent[i]`** = the parent of node `i` in the Union Find tree. If `parent[i] == i`, then `i` is the **root** of its component.

```
Init: parent = [0, 1, 2, 3, 4]
      every node is its own root = 5 separate components

After unite(0,1): parent = [0, 0, 2, 3, 4]
      node 1's parent is now 0
      0 and 1 are in same component, root=0

After unite(1,2): parent = [0, 0, 0, 3, 4]
      find(1)=0, find(2)=2, merge → parent[2]=0
      0,1,2 in same component
```

**`rank[i]`** = approximate height of the tree rooted at `i`. Used to decide who becomes the parent during union — always attach shorter tree under taller tree to keep tree flat.

```
rank[px] < rank[py] → swap, so px is always the taller
parent[py] = px     → attach shorter (py) under taller (px)
```

Visually — without rank:
```
0→1→2→3→4  (degenerate, height=4, slow find)
```

With rank (union by rank):
```
    0
  / | \
 1  2  3  (flat, height=1, fast find)
```

Path compression makes it even flatter over time.

---

**Template:**
```cpp
vector<int> parent, rank;

void init(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    iota(parent.begin(), parent.end(), 0); // parent[i]=i
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  // path compression
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;  // already connected
    if (rank[px] < rank[py]) swap(px, py);
    parent[py] = px;       // merge smaller into larger
    if (rank[px] == rank[py]) rank[px]++;
}

bool connected(int x, int y) {
    return find(x) == find(y);
}
```

**Two optimizations:**
- **Path compression** — `parent[x] = find(parent[x])` flattens tree during find
- **Union by rank** — always merge smaller tree into larger

With both: nearly O(1) amortized per operation (technically O(α(n)) where α is inverse Ackermann).

---

**LC 547 — Number of Provinces**

> There are `n` cities. `isConnected[i][j]=1` means city `i` and `j` are directly connected. Return number of provinces (connected components).
>
> `isConnected=[[1,1,0],[1,1,0],[0,0,1]]` → `2`

Before coding:
1. How do you count connected components using Union Find?
2. TC/SC?