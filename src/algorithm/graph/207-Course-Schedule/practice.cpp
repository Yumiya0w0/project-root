#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // construct indegree
        // make graph
        vector<int> indeg(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i++) 
        {
            indeg[pre[i][0]]++;
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) 
        {
            if (indeg[i] == 0) q.push(i);
        }
        
        // DFS
        while(!q.empty())
        {
            for(int i: graph[q.front()])
            {
                if(--indeg[i] == 0)
                {
                    q.push(i);
                }
            }
            q.pop();
        }
        for (int i = 0; i <n; i++)
            if (indeg[i] > 0) return false;
        return true;
    }
};
