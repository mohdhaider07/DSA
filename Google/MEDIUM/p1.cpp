#include <iostream>
#include <vector>
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
int main()
{
    cout << "Hello, World!" << endl;
    cout << canFinish(2, {{0, 1}}) << endl;

    return 0;
}