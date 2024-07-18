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
    // min priority queue this queue will store (dis, node)
    // Code here
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

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    // Code here
    vector<int> dis(V, 1e8);
    dis[S] = 0;
    for (int i = 0; i < V; i++)
    {

        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dis[u] != 1e8 && dis[u] + w < dis[v])
            {
                // if(i==V){
                //     return {-1};
                // }
                dis[v] = dis[u] + w;
            }
        }
    }

    //  for detecting cycle
    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dis[u] != 1e8 && dis[u] + w < dis[v])
        {

            return {-1};

            // dis[v] = dis[u] + w;
        }
    }

    return dis;
}

void shortest_distance(vector<vector<int>> &matrix)
{
    // Code here
    // taking vertex from 0 to v-1
    int V = matrix.size();

    for (int k = 0; k < V; k++)
    {

        for (int i = 0; i < V; i++)
        {

            for (int j = 0; j < V; j++)
            {
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX)
                {
                    if (matrix[i][j] == -1)
                    {
                        matrix[i][j] = matrix[k][j] + matrix[i][k];
                    }
                    else
                    {

                        matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
                    }
                }
            }
        }
    }
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> vis(V, false);
    // it will store the {u ,v} of the minimum spaning tree
    vector<pair<int, int>> mst;

    pq.push({0, {0, -1}});
    int sum = 0;

    while (!pq.empty())
    {
        pair<int, pair<int, int>> f = pq.top();
        int w = f.first;
        int n = f.second.first;
        int parent = f.second.second;
        pq.pop();

        if (vis[n])
            continue;

        vis[n] = true;
        sum += w;

        if (parent != -1)
        {
            mst.push_back({parent, n});
        }

        for (auto neighbor : adj[n])
        {
            // int u = neighbor[0];
            int v = neighbor[0];
            int newW = neighbor[1];
            if (!vis[v])
            {
                pq.push({newW, {v, n}});
                // soring the node in the minimum spaning tree array
            }
        }
    }
    // print the mst
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].first << " " << mst[i].second << endl;
    }
    return sum;
}

int main()
{
    cout << "Hello, World!" << endl;
    cout << canFinish(2, {{0, 1}}) << endl;

    return 0;
}