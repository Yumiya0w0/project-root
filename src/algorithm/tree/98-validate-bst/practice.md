## 2026-06-30
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
### NOTE
- Need to loop LMax and RMin
> Def of a BST?

### Code
```cpp
bool validate (TreeNode* root, long int min, long int max) {
    if (!root) return true; // base case
    // :C 
    // if (root->left && root->val <= root->left->val) return false;
    // if (root->right && root->val >= root->right->val) return false;

                        // parent need to be max in subtree
    if (root && max <= root->val) return false;
                        // parent need to be min in subtree
    if (root && min >= root->val) return false;


    return validate(root->left, min, root->val) && validate(root->right, root->val, max);
}
bool isValidBST(TreeNode* root) {
    return validate(root, (long)INT_MIN-1, (long)INT_MAX+1);
}
```
