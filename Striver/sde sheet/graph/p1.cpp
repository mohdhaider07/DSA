// boiler plate c++ code
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> inDeg(V, 0);
    // Calculate in-degree of each vertex
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            inDeg[adj[i][j]]++;
        }
    }

    queue<int> q;
    // travers over indeg for if some one is zero then add in que
    for (int i = 0; i < V; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i = 0; i < adj[node].size(); i++)
        {
            // remove the node from the graph and redure there childern indegree to  -1
            inDeg[adj[node][i]]--;
            // check if any node is having indegree zero then enter in queue
            if (inDeg[adj[node][i]] == 0)
            {
                q.push(adj[node][i]);
            }
        }
    }

    return ans;
}

void topoSortDfsHelper(vector<int> adj[], vector<int> &vis, int node, vector<int> &ans)
{
    if (vis[node])
    {
        return;
    }
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        topoSortDfsHelper(adj, vis, i, ans);
    }

    ans.insert(ans.begin(), node);
}

vector<int> topoSortDfs(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    // creating ans verotr
    vector<int> ans;
    // Calculate in-degree of each vertex
    for (int i = 0; i < V; i++)
    {
        topoSortDfsHelper(adj, vis, i, ans);
    }

    return ans;
}

int main()
{
    cout << "GRAPH/p1.cpp\n";

    cout << "PROGRAM EXECUTED DONE\n";
    return 0;
}