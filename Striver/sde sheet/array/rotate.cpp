#include <iostream>
#include <string>
#include <vector>

using namespace std;

string rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            /* code */
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    cout << "rotate";
    return 0;
}