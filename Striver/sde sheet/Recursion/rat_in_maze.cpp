#include <iostream>
#include <vector>

using namespace std;
void solve(int x, int y, vector<vector<int>> &mat, int n, vector<string> &res, string path, vector<vector<int>> &visited)
{
    // base case to check the bottom right cornet
    if (x == n - 1 && y == n - 1)
    {
        res.push_back(path);
        return;
    }
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char move[] = {'D', 'L', 'R', 'U'};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // check if the move is valid or not;
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && mat[nx][ny] == 1)
        {
            /* code */
            visited[x][y] = 1;
            solve(nx, ny, mat, n, res, path + move[i], visited);
            visited[x][y] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> res;
    int n = mat.size();
    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
        return res;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    solve(0, 0, mat, n, res, "", visited);
    return res;
}

int main()
{
    cout << "rat in maze backtracing";
    return 0;
}