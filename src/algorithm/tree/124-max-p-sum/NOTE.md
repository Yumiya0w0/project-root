# Records

## 2026-06-30
### NOTE
- **NOTE the condition of MAX !!**
- `return root->val + max(0, max(sumL, sumR));` is cleaner
### Explanation
- A valid path may have a turning point. Considering max path sum start and end at turning point, each node could hold dp value sumL and sumR. The max path sum at turning point `n` is sumL+sumR-(n->val)
- For a leaf, sumL=sumR=n->val
- Need sumL and sumR to calculate max path sum, so do a postorder traverse
-----
- Update val for each node: 
    - sumL = max(sumL+node->val, node->val) 
    - sumR = max(sumR+node->val, node->val)
    - Max (init with INT_MIN) = sumL+sumR-(n->val)
-----
- `dpPathSum(root) return maxPathSum ends here.

### Code
```cpp
int MAX=INT_MIN;
int oneWayMaxPathSum(TreeNode* root) {
    if (!root) return 0;
    int sumL = oneWayMaxPathSum(root->left);
    int sumR = oneWayMaxPathSum(root->right);
    // !!!
    // Calculate max at turning point root
    int rootMax = root->val // must contain self
                    + (sumL>0?sumL:0)
                    + (sumR>0?sumR:0) ;
    // Update global MAX
    MAX=max(MAX, rootMax);
    return max(root->val, max(root->val+sumL, root->val+sumR));
    // return root->val + max(0, max(sumL, sumR));
}

int maxPathSum(TreeNode* root) {
    oneWayMaxPathSum(root);
    return MAX;
}
```
