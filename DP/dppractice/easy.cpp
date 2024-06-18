#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int maxPro(int n, vector<int> &dp)
{
    if (n == 1)
    {
        return 1;
    }

    int ans = INT_MIN;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    for (int i = 1; i < n; i++)
    {
        int l;
        if (i == 1 || i == 2 || i == 3)
        {
            l = i;
        }
        else
        {
            l = dp[i] = maxPro(i, dp);
        }
        int r;
        if (n - i == 1 || n - i == 2 || n - i == 3)
        {
            r = n - i;
        }
        else
        {
            r = dp[n - i] = maxPro(n - i, dp);
        }

        int temp = l * r;

        ans = max(ans, temp);
    }

    return dp[n] = ans;
}

int integerBreak(int n)
{

    if (n < 4)
    {
        return n - 1;
    }
    vector<int> dp(n + 1, -1);

    return maxPro(n, dp);
}

int helperLis(vector<int> &arr, int i, int x, unordered_map<string, int> &dp)
{
    if (i <= 0)
        return 0;

    string key = to_string(i) + to_string(x);
    if (dp[key] != 0)
    {
        return dp[key];
    }

    if (arr[i - 1] >= x)
    {

        return dp[key] = helperLis(arr, i - 1, x, dp);
    }
    else
    {
        return dp[key] = max(
                   1 + helperLis(arr, i - 1, arr[i - 1], dp),
                   helperLis(arr, i - 1, x, dp));
    }
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0 || n == 1)
    {
        return n;
    }

    unordered_map<string, int> dp;

    int ans = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        ans = max(ans, 1 + helperLis(nums, i, nums[i], dp));
    }

    return ans;
}

int main()
{

    cout << "\nEnd";

    return 0;
}