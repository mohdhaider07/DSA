#include <iostream>
#include <vector>
#include <map>

using namespace std;

// print the draph
void printDFS(vector<vector<int>> matrix, int sv, vector<bool> &visited)
{
    cout << sv << endl;
    visited[sv] = true;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[sv][i] == 1 && visited[i] == false)
        {
            printDFS(matrix, i, visited);
        }
    }
}

void takeInput()
{
    int n, e;
    cout << "Enter no of Node : ";
    cin >> n;
    cout << "Enter no. of Edge : ";
    cin >> e;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++)
    {
        cout << "Edge between the nodes : " << endl;
        int x;
        int y;
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
        cout << "No of edge left is : " << e - i - 1 << endl;
    }
    vector<bool> visited(n, false);
    printDFS(matrix, 0, visited);
}

// =====================================================
// DFS for disconnected graph
// =====================================================

// sv stsnd for starting vertex
void DFSDisconnected(vector<vector<int>> &matrix, vector<bool> &visited)
{

    int n = visited.size();

    // No of disconnected Components
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            c++;
            printDFS(matrix, i, visited);
        }
    }

    cout << "No of connected components : " << c << endl;
}

// find redundent connection
vector<int> findRedundantConnection(vector<vector<int>> edges)
{
    int n = edges.size();
    vector<int> parent, rank;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        parent.push_back(i);
        rank.push_back(1);
    }
    for (auto edge : edges)
    {
        int par1 = parent[edge[0] - 1];
        int par2 = parent[edge[1] - 1];

        cout << "\nparent1 " << par1;
        cout << "\nparent2 " << par2;

        if (par1 == par2)
        {
            ans.push_back(edge[0]);
            ans.push_back(edge[1]);
            continue;
        }

        int rank1 = rank[par1 - 1];
        int rank2 = rank[par2 - 1];

        cout << "\nrank1 " << rank1;
        cout << "\nrank2 " << rank2;
        if (rank1 >= rank2)
        {
            parent[par2 - 1] = par1;
            cout << "\npaent after updation 1 " << parent[edge[1] - 1];
            rank[par1 - 1] += rank2;
        }
        else
        {
            parent[par1 - 1] = par2;
            cout << "\npaent after updation 0 " << parent[edge[0] - 1];
            rank[par2 - 1] += rank1;
        }
    }
    cout << " size of ans is " << ans.size() << endl;
    return ans;
}
// detect cycle in directed graph
// Find Eventual Safe States  https://leetcode.com/problems/find-eventual-safe-states/

int main()
{
    vector<int> ans = findRedundantConnection({{1, 2}, {1, 3}, {2, 3}});
    for (auto x : ans)
    {
        cout << x << ", ";
    }
    cout << "program executed";

    return 0;
}