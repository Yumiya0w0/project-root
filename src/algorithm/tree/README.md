## Trees — Pattern Roadmap
1. Tree traversal (inorder, preorder, postorder)
2. BST operations (search, insert, validate)
3. Path problems (max path sum, path sum to target)
4. LCA (Lowest Common Ancestor)
5. Tree construction (from traversals)

| Problem                  | Difficulty | Status | TC   | SC   | Notes |
|---|---|---|---|---|---|
| LC 98 Validate BST       | Medium     | ✅     | O(n) | O(h) | Clean |
| LC 113 Path Sum II       | Medium     | ✅     | O(n) | O(n) | TC/SC wrong initially |
| LC 236 LCA               | Medium     | ✅     | O(n) | O(h) | Clean |
| LC 105 Tree Construction | Medium     | ⚠️     | O(n) | O(n) | .find() vs [], off-by-one on preorder range |

# To-do
LC 99 — Recover BST (inorder + BST property)  
LC 106 — Construct from Postorder + Inorder (variant of pattern 5)  
LC 124 — Binary Tree Maximum Path Sum (harder path problem)  

> NOTE: Stack/Queue to iterate Tree  
> Stack = DFS (preorder/inorder/postorder iterative)  
> Queue = BFS (level order)  

```cpp
// Iterative inorder (the one above) — push left chain, pop, go right
// Iterative preorder — push right then left, pop processes immediately
// Iterative postorder — trickiest, often reverse of modified preorder

// BFS level order:
queue<TreeNode*> q;
q.push(root);
while (!q.empty()) {
    int size = q.size();  // current level size
    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front(); q.pop();
        // process node
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```