int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == '1')
            {
                // dfs(grid, i, j);
                bfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

void dfs(vector<vector<char>>& grid, int r, int c)
{
    if(r<0 || r>=grid.size() ||
        c<0 || c>=grid[0].size() ||
        grid[r][c] == '0' ) return;
    grid[r][c] = '0';
    dfs(grid, r+1, c);
    dfs(grid, r-1, c);
    dfs(grid, r, c+1);
    dfs(grid, r, c-1);
}

void bfs(vector<vector<char>>& grid, int r, int c)
{
    int m = grid.size();
    int n = grid[0].size();
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    
    q.push({r, c}); //!
    grid[r][c] = '0'; //! mark as visited
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(auto& d: dirs)
        {
            int newR = row+d[0], newC=col+d[1];
            if(newR<0 || newR>=m || newC<0 || newC>=n || grid[newR][newC]=='0')
                continue;
            //! All grids in Q are visited, so we just dealwith ther neighbor
            grid[newR][newC] = '0';
            q.push({newR, newC});
        }
    }
}
