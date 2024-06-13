#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_set>
using namespace std;

// print graph in
void BFS(vector<vector<int>> &matrix, vector<bool> &visited, int sv)
{

    queue<int> q;

    int n = matrix.size();
    q.push(sv);

    while (!q.empty())
    {

        // No of no de is one level
        int m = q.size();

        for (int i = 0; i < m; i++)
        {
            int v = q.front();
            visited[v] = true;
            q.pop();
            cout << v << " ";
            for (int i = 0; i < n; i++)
            {
                if (matrix[v][i] == 1 && visited[i] == false)
                {
                    q.push(i);
                }
            }
        }
        cout << endl;
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
    BFS(matrix, visited, 0);
}

// BFS Snake and ladder

// next with a label in the range [curr + 1, min(curr + 6, n2)].

int snakesAndLaddersHelper(vector<vector<int>> &board, int pos, unordered_set<int> &dp)
{
    int n = board.size();
    if (pos >= (n * n))
        return 0;

    // here we will check for the position
    if (dp.find(pos) != dp.end())
    {
        return INT_MAX;
    }
    // find the position of the
    dp.insert(pos);

    int x = n - 1 - (pos - 1) / n;
    int y = (pos - 1) % n;

    if (x % 2 == 1)
    {
        y = n - 1 - y;
    }

    if (board[x][y] != -1)
    {
        return snakesAndLaddersHelper(board, board[x][y], dp);
    }

    int s = pos + 1;
    int e = min((n * n) - 1, pos + 6);
    int step = INT_MAX;
    for (int i = s; i <= e; i++)
    {
        int tempStep = snakesAndLaddersHelper(board, i, dp);
        if (tempStep != INT_MAX)
        {
            tempStep += 1;
        }
        step = min(step, tempStep);
    }

    return step;
}

int snakesAndLadders(vector<vector<int>> &board)
{
    reverse(board.begin(), board.end());
    unordered_set<int> dp;
    int ans = snakesAndLaddersHelper(board, 1, dp);
    return ans == INT_MAX ? -1 : ans;
}

void shortestPathBinaryMatrix(vector<vector<int>> &grid, int i, int j, int step, int &ans)
{
    int n = grid.size();
    if (i >= n - 1 && j >= n - 1)
    {
        ans = min(ans, step);
        return;
    }
    if (grid[i][j] == 1)
    {
        return;
    }
    grid[i][j] = 1;
    // up
    if (i - 1 >= 0)
    {
        shortestPathBinaryMatrix(grid, i - 1, j, step + 1, ans);
    }
    //  down
    if (i + 1 < n)
    {
        shortestPathBinaryMatrix(grid, i + 1, j, step + 1, ans);
    }
    // left
    if (j - 1 >= 0)
    {
        shortestPathBinaryMatrix(grid, i, j - 1, step + 1, ans);
    }
    //  right
    if (j + 1 < n)
    {
        shortestPathBinaryMatrix(grid, i, j + 1, step + 1, ans);
    }
    // diagonal elements
    // j-1,i-1

    if (i - 1 >= 0 && j - 1 >= 0)
    {
        shortestPathBinaryMatrix(grid, i - 1, j - 1, step + 1, ans);
    }
    // i-1,j+1
    if (i - 1 >= 0 && j + 1 < n)
    {
        shortestPathBinaryMatrix(grid, i - 1, j + 1, step + 1, ans);
    }
    // i+1,j-1
    if (i + 1 < n && j - 1 >= 0)
    {
        shortestPathBinaryMatrix(grid, i + 1, j - 1, step + 1, ans);
    }
    // i+1,j+1
    if (i + 1 < n && j + 1 < n)
    {
        shortestPathBinaryMatrix(grid, i + 1, j + 1, step + 1, ans);
    }
    grid[i][j] = 0; // backtrack change
}
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int ans = INT_MAX;

    shortestPathBinaryMatrix(grid, 0, 0, 0, ans);
    return ans;
}

int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();
    // for loop
    queue<pair<int, int>> q;

    vector<vector<int>> visited(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }
    // condition if there is no iland or water
    if (q.empty() || q.size() == n * n)
    {
        return -1;
    }
    int distance = 0;
    vector<pair<int, int>> point = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        int size = q.size();
        /* code */
        while (size--)
        {
            auto [x, y] = q.front();
            q.pop();
            for (auto [px, py] : point)
            {
                int i = x + px, j = y + py;
                if (i >= 0 && j >= 0 && i < n && j < n && visited[i][j] == 0)
                {
                    visited[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        distance++;
    }
    return distance;
}

int shortestPath(vector<vector<int>> &grid, int k)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<vector<bool>>> visited(rows, vector<vector<bool>>(cols, vector<bool>(k + 1, false)));
    queue<pair<pair<int, int>, pair<int, int>>> q; // {x, y, obstacles, steps}

    q.push({{0, 0}, {0, 0}});

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int x = curr.first.first, y = curr.first.second;
        int obstacles = curr.second.first, steps = curr.second.second;

        if (x == rows - 1 && y == cols - 1)
        {
            return steps;
        }

        for (const auto &dir : directions)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols)
            {
                int nextObstacles = obstacles + grid[nx][ny];

                if (nextObstacles <= k && !visited[nx][ny][nextObstacles])
                {
                    visited[nx][ny][nextObstacles] = true;
                    q.push({{nx, ny}, {nextObstacles, steps + 1}});
                }
            }
        }
    }

    return -1; // If no valid path is found
}

void numberOfIslandHelper(vector<vector<char>> &grid, int i, int j)
{

    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0')
    {
        return;
    }
    grid[i][j] = '0';

    // up,
    numberOfIslandHelper(grid, i - 1, j);
    // down
    numberOfIslandHelper(grid, i + 1, j);
    // left
    numberOfIslandHelper(grid, i, j - 1);
    // right
    numberOfIslandHelper(grid, i, j + 1);
}

// number of island
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int numberOfIsland = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                numberOfIslandHelper(grid, i, j);
                numberOfIsland++;
            }
        }
    }
    return numberOfIsland;
}
void shortestBridgebfsHelper(vector<vector<int>> &grid, vector<vector<bool>> &visited, queue<pair<int, int>> &q, vector<vector<int>> &dirs, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == 0)
    {
        return;
    }
    visited[i][j] = true;
    q.push({i, j});
    for (auto &dir : dirs)
    {
        int newI = i + dir[0];
        int newJ = j + dir[1];
        shortestBridgebfsHelper(grid, visited, q, dirs, newI, newJ);
    }
}

int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    bool flg = false;
    int numberOfIsland = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                shortestBridgebfsHelper(grid, visited, q, dirs, i, j);
                flg = true;
                break;
            }
        }
        if (flg)
            break;
    }

    int step = 0;
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            pair<int, int> f = q.front();
            q.pop();
            for (auto &dir : dirs)
            {
                int newI = f.first + dir[0];
                int newJ = f.second + dir[1];
                if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && !visited[newI][newJ])
                {
                    if (grid[newI][newJ] == 1)
                    {
                        return step;
                    }
                    visited[newI][newJ] = true;
                    q.push({newI, newJ});
                }
            }
        }
        step++;
    }
    return -1;
}

int main()
{
    takeInput();
    cout << "\nBFS : ";
    return 0;
}