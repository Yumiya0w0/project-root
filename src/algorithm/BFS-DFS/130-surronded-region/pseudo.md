# 130. Surrounded Regions

# Note

'O' connected to boundary cannot be captured.

Use DFS/BFS from boundary cells to mark safe regions.

- Mark BEFORE push to stack/queue
dfs(): recursively, so check bound in caller and beggining of `dfs()` 
bfs(): iterative, so check bound in caller and only push legal coordinate

1. push 時 mark visited
2. queue 存 state (pair / struct)
3. pop 才 expand

# pseudo
```cpp
void solve(vector<vector<char>>& board) {
    if board is empty
        return
    for sides of board:
        do dfs or bfs
    for ele in board:
        if ele == O
            ele = X
    for ele in board:
        if ele == #
            ele = O
}

void bfs(i, j)
{
    queue<int> qr
    queue<int> qc
    qr.push(i)
    qc.push(j)
    board[i][j] = #
    while q is not empty
        for 4 dirs from qr.front, qc.front
            if newi <0 || newi >= board.size ||
                newj <0 || newj >=board[newi].size ||
                board[newi][newj] != O
                continue
            board[newi][newj] = #
            qr.push(newi)
            qc.push(newj)
        qr.pop
        qc.pop
}

void dfs(i, j)
{
    if i < 0 || i>=board.size || 
        j < 0 || j>=board[i].size 
        return
    if board[i][j] != O
        return
    // mark visited as '#'
    board[i][j] = #
    for 4 dirs
        dfs(next_i, next_j) 
}

```

# Dry run bfs
OOXX
OOXX
XXXX
bfs(0,0)
qr: 0
qc: 0
#OXX
OOXX
XXXX

loop1
qr: ~0~ 1 0 
qc: ~0~ 0 1
##XX
#OXX
XXXX

loop2
qr: ~1~ 0 
qc: ~0~ 1
##XX
##XX
XXXX

loop3
qr: ~0~ 
qc: ~1~
XXXX
XXXX
XXXX

# Complexity
- Time complexity: O(m*n)
- Space complexity: O(m*n)
