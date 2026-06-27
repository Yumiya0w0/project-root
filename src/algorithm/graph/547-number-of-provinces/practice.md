## DFS solve (Good :>)

```cpp
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (isConnected[i][i] == 1) // not visited
        {
            dfs(isConnected,i);
            n++;
        }
    }
    return n;
}

void dfs (vector<vector<int>>& isConnected, int i)
{
    if (isConnected[i][i] == 0) return;
    isConnected[i][i] = 0;
    for (int j = 0; j < isConnected.size(); j++)
    {
        if (isConnected[i][j] == 1)
        {
            isConnected[i][j] = 0;
            isConnected[j][i] = 0;
            dfs (isConnected,j);
        }
    }
}
```

## Union find

```cpp
vector<int> parent, rank;

void init(int n)
{
    parent.resize(n);
    rank.resize(n, 0);
    iota(parent.begin(), parent.end(), 0);
}
int find(int x)
{
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}
void unite(int x, int y)
{
    int px = find(x), py = find(y);
    if (px == py) return;
    if (rank[px] < rank[py]) swap(px, py); // make px the larger one
    parent[py] = px;       // merge smaller into larger
    if (rank[px] == rank[py]) rank[px]++;
}
bool connected(int x, int y) {
    return find(x) == find(y);
}
```
```cpp
int findCircleNum(vector<vector<int>>& isConnected) {
    init(isConnected.size());
    for (int i = 0; i < isConnected.size(); i++) {
        for (int j = i; j < isConnected.size(); j++) {
            if (isConnected[i][j]==1)
                unite(i, j);
        }
    }
    int count = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (find(i) == i) count++;
    }
    return count;
}
