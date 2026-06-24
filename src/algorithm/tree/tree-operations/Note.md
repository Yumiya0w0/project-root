## Struct
```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```
## Traverse
```cpp
void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);   // left
    res.push_back(root->val);   // root
    inorder(root->right, res);  // right
}
// preorder: root → left → right
// postorder: left → right → root
```
## Build from level order
- Using BFS (Queue)
```cpp
/*Queue - BFS*/
TreeNode* build(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        TreeNode* cur = q.front(); q.pop();
        if (i < nums.size()) {
            cur->left = new TreeNode(nums[i++]);
            q.push(cur->left);
        }
        if (i < nums.size()) {
            cur->right = new TreeNode(nums[i++]);
            q.push(cur->right);
        }
    }
    return root;
}
```

## Search BST
```cpp
TreeNode* search(TreeNode* root, int target) {
    if (!root || root->val == target) return root;
    if (target < root->val) return search(root->left, target);
    return search(root->right, target);
}
```

## Insert BST
```cpp
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}
```

## Is a BST
- BST property requires strictly greater/less — **duplicates are not allowed** in a valid BST. 
```cpp
# define LONGMIN
# define LONGMAX
bool isValidBST(TreeNode* root, long min, long max)
{
    // BASE CASE 
    if (!root) return true;
    if (root->val => max || root->val <= min) return false;
    return isValidBST(root->left, LONGMIN, root->val) && isValidBST(root->right, root->val, LONGMAX);
}
```
# Build from inorder & postorder
```cpp
unordered_map<int, int> inorderIndex;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;
    for (int i=0; i<preorder.size(); i++)
    {
        inoderIndex[inorder[i]] = i;
    }
    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}
TreeNode* build(vector<int>& preorder, int preL, int preR,
                vector<int>& inorder, int inL, int inR) 
{
    //* boundary check preL
    if(preL>preR) return nullptr;
    TreeNode* root = new TreeNode(preorder[preL]);
    // find left tree size from inorder
    int index=inorderIndex.find(preorder[preL])->second;
    // int index=inorderIndex[preorder[preL]]; // 預設不存在就寫入
    int leftSize=index-inL;
    root->left = build(preorder, preL+1, preL+leftSize, inorder, inL, index-1);
    root->right = build(preorder, preL+leftSize+1, preR, inorder, index+1, inR);
    return root;
}

```