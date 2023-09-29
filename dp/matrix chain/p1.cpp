#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixMultiplicationHelper(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int tempAns = (matrixMultiplicationHelper(arr, i, k, dp) +
                       matrixMultiplicationHelper(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j]);

        ans = min(ans, tempAns);
    }
    return dp[i][j] = ans;
}

int matrixMultiplication(int N, vector<int> &arr)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return matrixMultiplicationHelper(arr, 1, N - 1, dp);
}

int main()
{
    vector<int> v{10, 30, 5, 60};
    cout << "Your ans is : " << matrixMultiplication(4, v);
    cout << "\nProgram Executed " << endl;
    return 0;
}