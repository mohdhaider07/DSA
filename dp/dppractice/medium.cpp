#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

int longestIncreasingPath(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    // left = i,j-1
    if (j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1])
    {
        ans = max(ans, 1 + (dp[i][j - 1] = longestIncreasingPath(matrix, i, j - 1, dp)));
    }
    // right = i,j+1
    if (j + 1 < matrix[0].size() && matrix[i][j] < matrix[i][j + 1])
    {
        ans = max(ans, 1 + (dp[i][j + 1] = longestIncreasingPath(matrix, i, j + 1, dp)));
    }

    // top = i-1,j
    if (i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j])
    {
        ans = max(ans, 1 + (dp[i - 1][j] = longestIncreasingPath(matrix, i - 1, j, dp)));
    }
    // bottom = i+1,j
    if (i + 1 < matrix.size() && matrix[i][j] < matrix[i + 1][j])
    {
        ans = max(ans, 1 + (dp[i + 1][j] = longestIncreasingPath(matrix, i + 1, j, dp)));
    }
    return dp[i][j] = ans;
}

int longestIncreasingPath(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MIN;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // call helper function
            ans = max(ans,
                      longestIncreasingPath(matrix, i, j, dp) + 1);
        }
    }

    return ans;
}

// ==========================================================================================

// 2328. Number of Increasing Paths in a Grid
// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/

// ==========================================================================================

int countPathsHelper(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    // left = i,j-1
    if (j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1])
    {
        ans = ans + 1 + (dp[i][j - 1] = countPathsHelper(matrix, i, j - 1, dp));
    }
    // right = i,j+1
    if (j + 1 < matrix[0].size() && matrix[i][j] < matrix[i][j + 1])
    {
        ans = ans + 1 + (dp[i][j + 1] = countPathsHelper(matrix, i, j + 1, dp));
    }

    // top = i-1,j
    if (i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j])
    {
        ans = ans + 1 + (dp[i - 1][j] = countPathsHelper(matrix, i - 1, j, dp));
    }
    // bottom = i+1,j
    if (i + 1 < matrix.size() && matrix[i][j] < matrix[i + 1][j])
    {
        ans = ans + 1 + (dp[i + 1][j] = countPathsHelper(matrix, i + 1, j, dp));
    }
    return dp[i][j] = ans;
}

int countPaths(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans++;
            int temp = countPathsHelper(grid, i, j, dp);
            if (temp > 0)
            {
                ans += temp;
            }
        }
    }

    return ans;
}

// =================================================================================================

// https://leetcode.com/problems/predict-the-winner/

// ==============================================================================================

bool predictTheWinnerHelper(vector<int> &nums, int i, int j, int l, int r)
{
    if (i >= nums.size() || j < 0 || j < i)
    {
        return l >= r;
    }
    if (i == j)
    {
        return l + nums[i] >= r;
    }

    if (j - i == 1)
    {
        return predictTheWinnerHelper(nums, i + 1, j - 1, l + nums[i], r + nums[j]) || predictTheWinnerHelper(nums, i + 1, j - 1, l + nums[j], r + nums[i]);
    }

    bool left = false;

    if (i < nums.size() - 1 && nums[i + 1] > nums[j])
    {
        left = predictTheWinnerHelper(nums, i + 2, j, l + nums[i], r + nums[i + 1]);
    }
    else
    {
        left = predictTheWinnerHelper(nums, i + 1, j - 1, l + nums[i], r + nums[j]);
    }

    bool right = false;
    if (j > 0 && nums[j - 1] > nums[i])
    {
        right = predictTheWinnerHelper(nums, i, j - 2, l + nums[j], r + nums[j - 1]);
    }
    else
    {
        right = predictTheWinnerHelper(nums, i + 1, j - 1, l + nums[j], r + nums[i]);
    }

    return left || right;
}

bool predictTheWinner(vector<int> nums)
{
    int n = nums.size();

    return predictTheWinnerHelper(nums, 0, n - 1, 0, 0);
}

// *********************************************************************
//  Word Break
// https://leetcode.com/problems/word-break/description/
// *********************************************************************

bool wordBreakHelper(string s, vector<string> &wordDict, int i, string tempStr)
{
    int n = s.size();
    int m = tempStr.size();

    if (s == tempStr)
    {
        return true;
    }

    if (m >= n || i < 0)
    {
        return false;
    }

    return wordBreakHelper(s, wordDict, i, tempStr + wordDict[i]) || wordBreakHelper(s, wordDict, i, wordDict[i] + tempStr) ||
           wordBreakHelper(s, wordDict, i - 1, tempStr);
}

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = wordDict.size();
    return wordBreakHelper(s, wordDict, n - 1, "");
}

int main()
{

    cout << predictTheWinner({2});

    // cout << countPaths({{1, 1},
    //                     {3, 4}});

    cout << "\nDone with it";

    return 0;
}