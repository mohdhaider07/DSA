// boiler plate c++ code
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    if (vis[node] == 1)
    {
        return;
    }
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        topoSortDfsHelper(adj, vis, adj[node][i], ans);
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

void numIslandsHelper(vector<vector<char>> &grid, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0')
    {
        return;
    }
    grid[i][j] = '0';
    vector<vector<int>> path = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (vector<int> p : path)
    {
        int k = i + p[0];
        int l = j + p[1];
        numIslandsHelper(grid, k, l);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                numIslandsHelper(grid, i, j);
            }
        }
    }
    return ans;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<int> color(v, -1);
    queue<int> q;
    color[0] = 1;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (color[graph[node][i]] == -1)
            {
                if (color[node] == 1)
                {
                    color[graph[node][i]] = 0;
                }
                else
                {
                    color[graph[node][i]] = 1;
                }

                q.push(graph[node][i]);
            }
            else if (color[node] == graph[node][i])
            {
                return false;
            }
        }
    }

    return true;
}

void DFSTIME(vector<vector<int>> &adj, stack<int> &s, int node, vector<bool> &vis)
{
    if (vis[node])
    {
        return;
    }
    vis[node] = true;
    for (auto nearNode : adj[node])
    {
        if (!vis[node])
        {
            DFSTIME(adj, s, nearNode, vis);
        }
    }

    s.push(node);
}

void makeVisitDfs(vector<vector<int>> &adj, vector<bool> &vis, int node)
{
    if (vis[node])
    {
        return;
    }
    vis[node] = true;
    for (auto nearNode : adj[node])
    {
        if (!vis[node])
        {
            makeVisitDfs(adj, vis, nearNode);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    vector<bool> vis(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            DFSTIME(adj, s, i, vis);
        }
    }

    vector<vector<int>> adjT(V);
    for (int i = 0; i < V; i++)
    {
        vis[i] = false;
        for (auto nearNode : adj[i])
        {
            adjT[nearNode].push_back(i);
        }
    }

    int scc = 0;
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        if (!vis[t])
        {
            scc++;
            makeVisitDfs(adj, vis, t);
        }
    }

    return scc;
}

int main()
{
    cout << "GRAPH/p1.cpp\n";

    cout << "PROGRAM EXECUTED DONE\n";
    return 0;
}