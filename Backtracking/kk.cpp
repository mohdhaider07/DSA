#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

int coutTheway(vector<vector<int>> matrix, int i, int j, int &n)
{
    if (i >= n - 1 || j >= n - 1)
    {
        return 1;
    }

    int down = 0, right = 0;
    if (j < n - 1)
    {
        right = coutTheway(matrix, i, j + 1, n);
    }
    if (i < n - 1)
    {
        down = coutTheway(matrix, i + 1, j, n);
    }

    return right + down;
}

void PrintMatrix(vector<vector<int>> &matrix, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printThePath(vector<vector<int>> matrix, int i, int j, int &n)
{

    if (i >= n || j >= n)
    {
        return;
    }

    matrix[i][j] = 1;
    // cout<<"ee ";
    if (i == n - 1 && j == n - 1)
    {

        PrintMatrix(matrix, n);

        return;
    }

    if (j < n - 1)
    {
        printThePath(matrix, i, j + 1, n);
    }
    if (i < n - 1)
    {
        printThePath(matrix, i + 1, j, n);
    }
}

void printPathString(int i, int j, int n, string path)
{
    if (i >= n || j >= n)
    {
        return;
    }

    if (i == n - 1 && j == n - 1)
    {

        cout << path << endl;
        return;
    }

    if (j < n - 1)
    {
        printPathString(i, j + 1, n, path + "R");
    }
    if (i < n - 1)
    {
        printPathString(i + 1, j, n, path + "D");
    }
}

void nearestExitHelper(vector<vector<char>> &maze, int i, int j, int tempAns, int &ans)
{

    int n = maze.size();
    int m = maze[0].size();

    if (i > 0 || i >= n || j < 0 || j >= m)
    {
        return;
    }

    if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
    {
        cout << " 105 ";
        ans = min(ans, tempAns);
        return;
    }

    maze[i][j] = '+';
    // up i-1,j
    if (i - 1 > 0 && maze[i - 1][j] != '+')
    {
        cout << " 110 ";
        nearestExitHelper(maze, i - 1, j, tempAns + 1, ans);
    }
    // down i+1,j
    if (i + 1 < n - 1 && maze[i + 1][j] != '+')
    {
        nearestExitHelper(maze, i + 1, j, tempAns + 1, ans);
    }
    // left i,j-1
    if (j - 1 > 0 && maze[i][j - 1] != '+')
    {
        nearestExitHelper(maze, i, j - 1, tempAns + 1, ans);
    }
    // right i,j+1
    if (j + 1 < m - 1 && maze[i][j + 1] != '+')
    {
        nearestExitHelper(maze, i, j + 1, tempAns + 1, ans);
    }
}

int nearestExit(vector<vector<char>> maze, vector<int> entrance)
{

    int ans = INT_MAX;
    nearestExitHelper(maze, entrance[0], entrance[1], 0, ans);
    return ans == INT_MAX ? -1 : ans;
}
int main()
{

    int n = 3;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    // cout<<"Number of ways : "<<coutTheway(matrix,0,0,n);

    // printThePath(matrix,0,0,n);

    // printPathString(0, 0, n, "");
    vector<vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};

    cout << "Minimum steps is : " << nearestExit(maze, {1, 2});
    cout << "\nBackTracing";
    return 0;
}