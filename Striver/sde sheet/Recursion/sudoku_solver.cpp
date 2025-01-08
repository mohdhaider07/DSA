// cpp templete
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// sudoku solver
bool isValid(vector<vector<char>> &board, int row, int col, char num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return false;
    }
    // check for the column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }
    // check for the sub box
    int startcol = (col / 3) * 3;
    int startrow = (row / 3) * 3;
    for (int i = startrow; i < startrow + 3; i++)
    {
        for (int j = startcol; j < startcol + 3; j++)
        {
            if (board[i][j] == num)
                return false;
            /* code */
        }

        /* code */
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {

            if (board[row][col] == '.')
            {
                for (char num = '1'; num <= '9'; num++)
                {
                    if (isValid(board, row, col, num))
                    {
                        board[row][col] = num; // place the number
                        if (solve(board))
                            return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{

    cout << "Haider";
    return 0;
}