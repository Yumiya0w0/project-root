# Path sum
```cpp
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        // if node is a leaf
        if(!root->left && !root->right) return (root->val==targetSum);
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
```

# Path sum II
- DFS helper
- push val at first for recursive
- Remove val at last for clean-up and backtracking
```cpp
vector<vector<int>> ans;
void dfs(TreeNode* root, int targetSum, vector<int> path)
{
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right) // isLeaf
    {
        if (targetSum == root->val)
        {
            ans.push_back(path);
        }
    }
    else 
    {
        dfs(root->left, targetSum-root->val, path);
        dfs(root->right, targetSum-root->val, path);
    }
    path.pop_back(root->val);
}
```
```cpp
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (!root) return ans;
    vector<int> path;
    dfs(root, targetSum, path);
    return ans;
}
```
