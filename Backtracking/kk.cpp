#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <map>
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

void printThePath(vector<vector<int>> &matrix, int i, int j, int &n)
{

    if (i >= n || j >= n)
    {
        return;
    }

    matrix[i][j] = 1;
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
    matrix[i][j] = 0;
}

void printAllPath(vector<vector<int>> &matrix, int i, int j, int &n, int &stp)
{
    if (i >= n || j >= n || matrix[i][j] != 0)
    {
        return;
    }

    matrix[i][j] = stp++;

    if (i == n - 1 && j == n - 1)
    {
        PrintMatrix(matrix, n);
        matrix[i][j] = 0;
        stp--;
        return;
    }

    if (j < n - 1)
    {
        // right
        printAllPath(matrix, i, j + 1, n, stp);
    }

    // left
    if (j > 0)
    {
        printAllPath(matrix, i, j - 1, n, stp);
    }

    if (i < n - 1)
    { // down
        printAllPath(matrix, i + 1, j, n, stp);
    }
    // up
    if (i > 0)
    {
        printAllPath(matrix, i - 1, j, n, stp);
    }

    if (j < n - 1 && i < n - 1)
    { // digonal forward
        printAllPath(matrix, i + 1, j + 1, n, stp);
    }

    // diagonal upwards
    if (j > 0 && i > 0)
    {
        printAllPath(matrix, i - 1, j - 1, n, stp);
    }

    matrix[i][j] = 0;
    stp--;
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

void printBoad(vector<vector<string>> &board)
{
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            /* code */
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void solveNQueensHelper(vector<pair<int, int>> &blocked, vector<vector<string>> &board, int i, int j, int &q)
{
    int n = board.size();
    int m = board[0].size();

    // check the posion is occupied or not
    if (board[i][j] == "Q" || board[i][j] == "+")
    {

        cout << "it is having queen  and also + so returning : " << endl;

        return;
    }

    if (q == 0)
    {

        printBoad(board);
        cout << "prongting board ";
        return;
    }

    int x = 1;
    for (auto pos : blocked)
    {
        if (pos.first == i || pos.second == j || (abs(pos.first - i) == abs(pos.second - j)))
        {
            x = 0;
            cout << "it posiotion is blocked ;  " << i << " " << j << endl;
            break;
        }
    }

    if (x == 1)
    {
        blocked.push_back({i, j});
        board[i][j] = "Q";
        q--;
    }
    else
    {
        board[i][j] = "+";
    }

    // down
    if (i < n - 1)
    {
        cout << "down" << endl;
        solveNQueensHelper(blocked, board, i + 1, j, q);
    }
    // up
    if (i > 0)
    {
        cout << "up" << endl;
        solveNQueensHelper(blocked, board, i - 1, j, q);
    }

    // right
    if (j < m - 1)
    {
        cout << "right" << endl;
        solveNQueensHelper(blocked, board, i, j + 1, q);
    }
    // left

    if (j > 0)
    {
        cout << "left" << endl;
        solveNQueensHelper(blocked, board, i, j - 1, q);
    }

    if (x == 1)
    {
        blocked.pop_back();
        q++;
    }

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

bool isEscapePossibleHelper(vector<vector<int>> &blocked, int i, int j, vector<int> &target, int &n, unordered_map<string, int> mp)
{

    string key = to_string(i) + to_string(j);

    if (mp[key] != 0)
    {
        return mp[key];
    }

    vector<int> currPos = {i, j};

    if (currPos == target)
    {
        return true;
    }

    for (auto b : blocked)
    {
        if (b == currPos)
        {
            // return because it is blocked;
            return false;
        }
    }

    // mark currpos
    blocked.push_back(currPos);

    // down
    bool down = false;
    if (i < n - 1)
    {
        down |= mp[to_string(i + 1) + to_string(j)] = isEscapePossibleHelper(blocked, i + 1, j, target, n, mp);
    }
    // up
    bool up = down;
    if (i > 0)
    {
        up |= mp[to_string(i - 1) + to_string(j)] = isEscapePossibleHelper(blocked, i - 1, j, target, n, mp);
    }

    // right
    bool right = up;
    if (j < n - 1)
    {
        right |= mp[to_string(i) + to_string(j + 1)] = isEscapePossibleHelper(blocked, i, j + 1, target, n, mp);
    }

    // left
    bool left = right;
    if (j > 0)
    {
        left |= mp[to_string(i) + to_string(j - 1)] = isEscapePossibleHelper(blocked, i, j - 1, target, n, mp);
    }

    // backtrack
    blocked.pop_back();

    return mp[key] = left;
}

bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
{
    int n = 1e6;
    unordered_map<string, int> mp;
    return isEscapePossibleHelper(blocked, source[0], source[1], target, n, mp);
}

string keyStringify(int i, int j, int maxMove)
{
    return to_string(i) + to_string(j) + to_string(maxMove);
}
int findPathsHelper(int maxMove, int i, int j, int m, int n, unordered_map<string, int> &mp)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
    {
        return 1;
    }
    if (maxMove == 0)
    {
        return 0;
    }

    string key = keyStringify(i, j, maxMove);

    int MOD = 1e9 + 7;

    if (mp[key] != 0)
    {
        return mp[key] % MOD;
    }

    int count = 0;
    // down
    if (mp[keyStringify(i + 1, j, maxMove - 1)] != 0)
    {
        count = ((count % MOD + mp[keyStringify(i + 1, j, maxMove - 1)] % MOD) % MOD);
    }
    else
    {
        count = (count % MOD + (mp[keyStringify(i + 1, j, maxMove - 1)] = findPathsHelper(maxMove - 1, i + 1, j, m, n, mp) % MOD)) % MOD;
    }
    // up
    if (mp[keyStringify(i - 1, j, maxMove - 1)] != 0)
    {
        count = (count % MOD + mp[keyStringify(i - 1, j, maxMove - 1)] % MOD) % MOD;
    }
    else
    {
        count = (count % MOD + (mp[keyStringify(i - 1, j, maxMove - 1)] = findPathsHelper(maxMove - 1, i - 1, j, m, n, mp) % MOD)) % MOD;
    }
    // right
    if (mp[keyStringify(i, j + 1, maxMove - 1)] != 0)
    {
        count = (count % MOD + mp[keyStringify(i, j + 1, maxMove - 1)] % MOD) % MOD;
    }
    else
    {
        count = (count % MOD + (mp[keyStringify(i, j + 1, maxMove - 1)] = findPathsHelper(maxMove - 1, i, j + 1, m, n, mp) % MOD)) % MOD;
    }
    // left

    if (mp[keyStringify(i, j - 1, maxMove - 1)] != 0)
    {
        count = (count % MOD + mp[keyStringify(i, j - 1, maxMove - 1)] % MOD) % MOD;
    }
    else
    {
        count = (count % MOD + (mp[keyStringify(i, j - 1, maxMove - 1)] = findPathsHelper(maxMove - 1, i, j - 1, m, n, mp) % MOD)) % MOD;
    }

    return mp[key] = count % MOD;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    unordered_map<string, int> mp;
    int MOD = 1e9 + 7;
    return findPathsHelper(maxMove, startRow, startColumn, m, n, mp) % MOD;
}

int main()
{

    // int n = 3;
    // vector<vector<int>> matrix(n, vector<int>(n, 0));

    // int stp = 1;
    // printAllPath(matrix, 0, 0, n, stp);

    // printThePath(matrix,0,0,n);

    // printPathString(0, 0, n, "");

    // vector<vector<char>> maze = {{'.', '+'}};
    // vector<vector<char>> maze = {{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};

    // cout << "Minimum steps is : " << nearestExit(maze, {1, 0});

    // Escape a Large Maze

    // vector<vector<int>> blocked = {};

    // vector<int> source = {0, 0};

    // vector<int> target = {999999, 999999};

    solveNQueens(4);

    cout << "\nBackTracing";
    return 0;
}