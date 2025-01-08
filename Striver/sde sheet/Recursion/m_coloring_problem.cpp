#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, vector<vector<int>> &adj, vector<int> &colors, int color)
{
    for (int neighbor : adj[node])
    {
        if (colors[neighbor] == color)
            return false;
    }
    return true;
}
bool solve(int node, int m, vector<vector<int>> &adj, vector<int> &colors, int v)
{
    if (node == v)
        return true;
    for (int color = 1; color <= m; color++)
    {
        if (isSafe(node, adj, colors, color))
        {
            colors[node] = color;
            if (solve(node + 1, m, adj, colors, v))
                return true;
            colors[node] = 0;
        }
        /* code */
    }
    return false;
}
bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
{
    vector<vector<int>> adj(v);
    for (auto &edge : edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    vector<int> colors(v, 0);
    return solve(0, m, adj, colors, v);
}

int main()
{
    cout << "m-coloring problem";
    return 0;
}