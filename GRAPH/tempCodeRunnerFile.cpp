// boiler plate for c++
#include <iostream>
#include <vector>

using namespace std;
void dfs(int i, vector<int> &visited, vector<vector<int>> &graph)
{
    if (visited[i])
        return;
    visited[i] = 1;

    for (auto child : graph[i])
    {
        if (!visited[child])
        {
            dfs(child, visited, graph);
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n); // Initialize graph for 0-based indexing
    vector<int> visited(n, 0);    // Initialize visited vector for 0-based indexing
    int component_count = 0;

    // Build the graph
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    // Perform DFS for each node
    for (int i = 0; i < n; i++)
    { // Iterate over all nodes
        if (!visited[i])
        {
            dfs(i, visited, graph);
            component_count++;
        }
    }

    cout << component_count;
    return component_count;
}
int main()
{
    // call function with test case
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};

    countCompleteComponents(6, edges);

    cout << "Hello World!";
    return 0;
}