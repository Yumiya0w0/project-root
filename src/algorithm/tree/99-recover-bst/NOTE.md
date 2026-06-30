# Records

## 2026-06-30
### NOTE
- 98-validate-bst

### Explanation
- find invalid node recursively (use template in validate-BST)
- if 2 diff invalid nodes found, swap their value
- if 1 invalid node found, swap it and the node with violated boundary value

### Code
```cpp
TreeNode* prev, n1, n2;
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    if (prev && prev->val > root->val)
    {
        if (!n1) n1=prev; // first bigger val than root
        n2=root; // keep updating so that we can catch the violation if it happened
        // later smaller val than prev
    }
    prev=root; // last visit
    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    inorder(root);
    swap(n1->val, n2->val);
}
```
