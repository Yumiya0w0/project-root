# Patterns
| Problem          | Difficulty | Status | TC           | SC   | Notes |
|---|---|---|---|---|---|
| LC 78 Subsets    | Medium     | ✅     | O(2^n × n)   | O(n) | Clean |
| LC 46 Permutations| Medium   | ✅     | O(n! × n)    | O(n) | TC wrong initially |
| LC 77 Combinations| Medium   | ✅     | O(C(n,k)×k)  | O(k) | TC wrong initially |
| LC 79 Word Search| Medium     | ✅     | O(nm × 4^l)  | O(l) | Clean |
- Struggle patterns:    
TC estimation for backtracking — remember: count leaves × cost per leaf

- Review problems:  
1. LC 90 — Subsets II (with duplicates)    
2. LC 47 — Permutations II (with duplicates)   
3. LC 131 — Palindrome Partitioning

# Pattern 1 — Subsets
LC 78 — Subsets     
**Core idea:** At each element, decide include or exclude. Build solution incrementally, backtrack on dead ends.    
**Template:**
```cpp
cppvoid backtrack(vector<int>& nums, int start, 
               vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);  // record current subset
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);      // include
        backtrack(nums, i+1, path, res);
        path.pop_back();              // exclude (backtrack)
    }
}
// call as: backtrack(nums, 0, path, res)
```
**Key insight:** start prevents reusing elements and avoids duplicates.

# Pattern 2 — Permutations  
LC 46 — Permutations    
**Core idea:** Every element can be used once, order matters. Use a visited array to track used elements.   
**Template:**
```cpp
void backtrack(vector<int>& nums, vector<bool>& visited,
               vector<int>& path, vector<vector<int>>& res) {
    if (path.size() == nums.size()) {
        res.push_back(path);  // record at leaf only
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        path.push_back(nums[i]);
        backtrack(nums, visited, path, res);
        path.pop_back();
        visited[i] = false;
    }
}
```
**Key differences from Subsets:**
- No start index — try all elements each time
- visited array prevents reuse
- Record only at leaf when path.size() == nums.size()

# Pattern 3 — Combinations
```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        backtrack(1, n, k, comb);
        return res;
    }
    void backtrack(int start, int n, int k, vector<int>& comb)
    {
        if (comb.size() == k) 
        {
            res.push_back(comb);
            return;
        }
        for(int i = start; i <= n; i++)
        {
            comb.push_back(i);
            backtrack(i+1, n, k, comb);
            comb.pop_back();
        }
    }
};
```
# Pattern 4
LC79 Word Search
```cpp
class Solution {
public:
    bool dfs (vector<vector<char>>& board, string& word, int x, int y, int i)
    {
        // check size
        if (i+1 == word.size()) return true;
        // out of boundary
        if (x>=board.size() || x<0 || y >= board[0].size() || y<0 ) return false;
        // not match
        if (board[x][y] != word[i]) return false;
        char tmp = board[x][y];
        board[x][y] = '#';
        bool found = 
            dfs (board, word, x+1, y, i+1) ||
            dfs (board, word, x-1, y, i+1) ||
            dfs (board, word, x, y+1, i+1) ||
            dfs (board, word, x, y-1, i+1);
        board[x][y] = tmp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
};

```
