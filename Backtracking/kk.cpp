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

void nearestExitHelper(vector<vector<char>> &maze, int i, int j, int tempAns, int &ans, vector<int> &entrance)
{

    int n = maze.size();
    int m = maze[0].size();
    // cout << " I am here " << i << j << endl;
    if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == '+')
    {
        cout << " returning :" << endl;
        return;
    }

    if (!(entrance[0] == i && entrance[1] == j) && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
    {
        // cout << " assigning min value " << endl;
        ans = min(ans, tempAns);
        return;
    }

    maze[i][j] = '+';
    // up i-1,j

    if (i - 1 >= 0 && maze[i - 1][j] != '+')
    {

        cout << " up " << endl;
        nearestExitHelper(maze, i - 1, j, tempAns + 1, ans, entrance);
    }
    // down i+1,j
    if (i + 1 < n && maze[i + 1][j] != '+')
    {
        cout << " down " << endl;
        nearestExitHelper(maze, i + 1, j, tempAns + 1, ans, entrance);
    }
    // left i,j-1
    if (j - 1 >= 0 && maze[i][j - 1] != '+')
    {
        cout << "left" << endl;
        nearestExitHelper(maze, i, j - 1, tempAns + 1, ans, entrance);
    }
    // right i,j+1
    if (j + 1 < m && maze[i][j + 1] != '+')
    {
        cout << "right" << endl;
        nearestExitHelper(maze, i, j + 1, tempAns + 1, ans, entrance);
    }
}

int nearestExit(vector<vector<char>> maze, vector<int> entrance)
{

    int ans = INT_MAX;
    nearestExitHelper(maze, entrance[0], entrance[1], 0, ans, entrance);
    return ans == INT_MAX ? -1 : ans;
}

// =================================================
// N-Queens
// https://leetcode.com/problems/n-queens/description/
// ====================================================

void solveNQueensHelper(vector<pair<int, int>> &blocked, vector<vector<string>> &board, int i, int j, int q)
{
    int n = board.size();
    int m = board[0].size();

    // check the posion is occupied or not

    if (q == 0 || board[i][j] == "Q")
    {
        return;
    }

    for (auto pos : blocked)
    {
        if (pos.first == i || pos.second == j || (abs(pos.first - i) == abs(pos.second - j)))
        {

            return;
        }
    }

    blocked.push_back({i, j});
    board[i][j] = "Q";
    // down
    if (i < n - 1)
    {
        solveNQueensHelper(blocked, board, i + 1, j, q - 1);
    }
    // up
    if (i > 0)
    {
        solveNQueensHelper(blocked, board, i - 1, j, q - 1);
    }

    // right
    if (j < m - 1)
    {
        solveNQueensHelper(blocked, board, i, j + 1, q - 1);
    }
    // left

    if (j > 0)
    {
        solveNQueensHelper(blocked, board, i, j - 1, q - 1);
    }

    blocked.pop_back();
    board[i][j] = ".";
}

vector<vector<string>> solveNQueens(int n)
{
    vector<pair<int, int>> blocked;

    vector<vector<string>> board(n, vector<string>(n, "."));
    // clall the heloper fucntion

    solveNQueensHelper(blocked, board, 0, 0, n);

    return board;
}

int main()
{

    // int n = 3;
    // vector<vector<int>> matrix(n, vector<int>(n, 0));

    // cout<<"Number of ways : "<<coutTheway(matrix,0,0,n);

    // printThePath(matrix,0,0,n);

    // printPathString(0, 0, n, "");

    // vector<vector<char>> maze = {{'.', '+'}};
    vector<vector<char>> maze = {{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};

    cout << "Minimum steps is : " << nearestExit(maze, {1, 0});
    cout << "\nBackTracing";
    return 0;
}