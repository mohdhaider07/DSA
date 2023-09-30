#include <iostream>
#include <vector>
#include <climits>
#include <map>
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

// Palindrome Partitioning Recursive
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palindromicPartitionHeplper(string str, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (isPalindrome(str, i, j))
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = 1;
        temp += dp[i][k] != -1 ? dp[i][k] : dp[i][k] = palindromicPartitionHeplper(str, i, k, dp);
        temp += dp[k + 1][j] != -1 ? dp[k + 1][j] : dp[k + 1][j] = palindromicPartitionHeplper(str, k + 1, j, dp);

        ans = min(temp, ans);
    }
    return dp[i][j] = ans;
}

int palindromicPartition(string str)
{
    // code here
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return palindromicPartitionHeplper(str, 0, n - 1, dp);
}

bool isScrambleHelper(string s1, string s2, map<string, bool> &dp)
{
    int n = s1.size();
    if (n != s2.size())
    {
        return false;
    }

    if (s1 == s2)
    {
        return true;
    }
    if (n == 1)
    {
        return false;
    }
    string key = s1;
    key = key + "_";
    key = key + s2;
    if (dp.find(key) != dp.end())
    {
        return dp[key];
    }

    bool ans = false;
    for (int i = 0; i < n - 1; i++)
    {

        bool swap = isScrambleHelper(s1.substr(0, i + 1), s2.substr(n - 1 - i, n), dp) &&
                    isScrambleHelper(s1.substr(i + 1, n), s2.substr(0, n - 1 - i), dp);

        bool noSwap = isScrambleHelper(s1.substr(0, i + 1), s2.substr(0, i + 1), dp) &&
                      isScrambleHelper(s1.substr(i + 1, n), s2.substr(i + 1, n), dp);

        ans = swap || noSwap;
        if (ans)
        {
            break;
        }
    }

    return dp[key] = ans;
}

bool isScramble(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    if (n != m)
    {
        return false;
    }

    map<string, bool> dp;
    return isScrambleHelper(s1, s2, dp);
}

int main()
{
    vector<int> v{10, 30, 5, 60};
    cout << "Your ans is : " << isScramble("great", "rgeat");
    cout << "\nProgram Executed " << endl;
    return 0;
}