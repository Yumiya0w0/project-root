- Template
```cpp
// Each element: {value, list_index, element_index}
priority_queue<tuple<int,int,int>, 
               vector<tuple<int,int,int>>, 
               greater<>> minpq;

// Init — push first element of each list
for (int i = 0; i < k; i++)
    if (!lists[i].empty())
        minpq.push({lists[i][0], i, 0});

while (!minpq.empty()) {
    auto [val, i, j] = minpq.top(); minpq.pop();
    // process val
    if (j + 1 < lists[i].size())
        minpq.push({lists[i][j+1], i, j+1});
}
```
- Solve Leetcode 23
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
```
```cpp
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second; // min-heap by second, means "a has lower priority than b when a is larger"
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```
```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    // initialization
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> meanHeap;
    ListNode* head = new ListNode();
    ListNode* cur = head;
    for(auto list : lists)
    {
        if(list != nullptr)
            meanHeap.push(list);
    }
    while(!meanHeap.empty())
    {
        cur->next = meanHeap.top();
        meanHeap.pop();
        if (cur->next->next != nullptr)
            meanHeap.push(cur->next->next);
        cur = cur->next;
    }
    return head->next;
}
```