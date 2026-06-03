# 132-clone-graph

# Note
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
- What to store in queue?
- How to mark visited?
# Clarify
- point to self?
- empty graph
- no edge (no neighbor)

```cpp
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
```
```cpp
Node* solution(Node* node)
{
    if(!node) return nullptr;

    unordered_map<Node*, Node*> visited;
    queue<Node*> originQ;
    // put first node 
    originQ.push(node);
    visited[node] = new Node(node->val);
    while(!originQ.empty())
    {
        Node* cur = originQ.front();
        Node* copied = visited[cur];
        originQ.pop();
        // visited all neighbors
        for(auto neighbor: cur->neighbors)
        {
            // 使用 find 確保安全，避免 operator[] 的隱式插入
            if(visited.find(neighbor) == visited.end())
            //! if(!visited[neighbor])
            {
                visited[neighbor] = new Node(neighbor->val);
                originQ.push(neighbor);
            }
            copied->neighbors.push_back(visited[neighbor]);
        }
    }
    return visited[node];
}
```

# Complexity
!Time: O(n*max_edge_cnt)
Time: $O(N + E)$ 因為每個節點只會進出 Queue 剛好一次（由 visited 保障），所以這部分是 $O(N)$ 。在處理每個節點時，我們會遍歷它所有的鄰居（邊）。在無向圖中，每條邊會被存取兩次。因此所有 for 迴圈總共執行的次數就是 $2E$，即 $O(E)$ 。兩者相加即為 $O(N + E)$，這比 $O(N \times \text{max\_edge\_cnt})$ 更精確地反映了總工作量。
Space: O(n)

# Dry run
1. 
1-2-3
Q: 1
visited:
1 - new1, []

loop1
Q: ~1~, 2
visited:
1 - new1, [new2]
2 - new2, []

loop2
Q: ~2~, 3
visited:
1 - new1, [new2]
2 - new2, [new1, new3]
3 - new3, []

loop3
Q: ~3~
visited:
1 - new1, [new2]
2 - new2, [new1, new3]
3 - new3, [new2]

2. 
1 - 2
|   |
3 - 4 - 5

Q: 1
visited:
1 - new1, []

loop1
Q: ~1~, 2, 3
visited:
1 - new1, [new2, new3]
2 - new2, []
3 - new3, []

loop2
Q: ~2~, 3, 4
visited:
1 - new1, [new2, new3]
2 - new2, [new1, new4]
3 - new3, []
4 - new4, []

loop3
Q: ~3~, 4
visited:
1 - new1, [new2, new3]
2 - new2, [new1, new4]
3 - new3, [new1, new4]
4 - new4, []

loop4
Q: ~4~, 5
visited:
1 - new1, [new2, new3]
2 - new2, [new1, new4]
3 - new3, [new1, new4]
4 - new4, [new2, new3, new5]
5 - new5, []

loop5
Q: ~5~
visited:
1 - new1, [new2, new3]
2 - new2, [new1, new4]
3 - new3, [new1, new4]
4 - new4, [new2, new3, new5]
5 - new5, [new4]
