#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

bool dfs(vector<vector<int>> &graph, int node, vector<bool> &vis)
{

    vis[node] = true;

    for (int i = 0; i < graph[node].size(); i++)
    {
        if (vis[graph[node][i]] || !dfs(graph, graph[node][i], vis))
        {
            return false;
        }
    }

    return true;
}

bool canFinish(int numCourses, vector<vector<int>> prerequisites)
{
    vector<vector<int>> graph(numCourses);
    vector<bool> vis(numCourses, false);
    for (vector<int> node : prerequisites)
    {
        graph[node[1]].push_back(node[0]);
    }
    // pring graph
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " :{ ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "}" << endl;
    }
    // one more fore loop

    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i])
            continue;

        bool flag = dfs(graph, i, vis);

        if (flag == false)
        {
            return flag;
        }
    }

    return true;
}

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    // min priority queue this queue will store (dis, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // initilize a distance vector
    vector<int> dis(V, INT_MAX);
    pq.push({0, S});
    dis[S] = 0;
    while (!pq.empty())
    {
        pair<int, int> f = pq.top();
        // distance of node form source
        int dist = f.first;
        // distance of the node
        int node = f.second;
        pq.pop();
        for (auto it : adj[node])
        {
            int n = it[0];
            int w = it[1];
            if (dist + w < dis[n])
            {
                dis[n] = dist + w;
                pq.push({dist + w, n});
            }
        }
    }

    return dis;
}

int main()
{
    cout << "Hello, World!" << endl;
    cout << canFinish(2, {{0, 1}}) << endl;

    return 0;
}