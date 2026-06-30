# Records

## 2026-06-30
### NOTE
- BST <-> inorder
### Explanation
- Do a inorder traverse and find k-th
### Code
```cpp
TreeNode* ptr;
int i =0;
int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);
    return ptr ? ptr->val : -1 ;
}
void inorder(TreeNode* root, int k) {
    if (!root || i == k) return;
    inorder(root->left, k);
    if (++i==k) ptr = root;
    inorder(root->right, k);
}
```
