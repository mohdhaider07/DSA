#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

// ===========================================================
// 1691. Maximum Height by Stacking Cuboids
// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
// ============================================================
// l b h
// 0 1,2
// l b h
// l h b
// b h l
// to do
// https://leetcode.com/problems/longest-increasing-subsequence/
// we will use the concept of the longest increasing subsequence

// print the vector of vector
void printVector(vector<vector<int>> &cuboids)
{
    for (auto d : cuboids)
    {
        for (auto e : d)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

// wrong solution
int maxHeight(vector<vector<int>> &cuboids)
{

    int n = cuboids.size();

    // sort the dimentions of the cuboid
    for (auto &d : cuboids)
    {
        sort(d.begin(), d.end());
    }
    sort(cuboids.begin(), cuboids.end());
    printVector(cuboids);

    int ans = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        int tempAns = 0;
        // this point is wrong
        for (int j = 0; j <= i; j++)
        {
            if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
            {
                tempAns += cuboids[j][2];
            }
        }
        ans = max(tempAns, ans);
        // till here everything is correct
    }

    return ans;
}

// Jump Game II
// https://leetcode.com/problems/jump-game-ii/description/

int jumpHelper(vector<int> &nums, int i, vector<int> &dp)
{
    int n = nums.size();

    if (i == n - 1)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int tempAns = INT_MAX;
    for (int j = 1; j <= nums[i] && i + j <= n - 1; j++)
    {
        int temp = jumpHelper(nums, i + j, dp);
        if (temp != INT_MAX)
        {
            temp = temp + 1;
        }
        tempAns = min(tempAns, temp);
    }

    return dp[i] = tempAns;
}

int jump(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n + 1, -1);
    int ans = INT_MAX;

    return jumpHelper(nums, 0, dp);
}

// **************************************************************
// Jump Game
// https://leetcode.com/problems/jump-game/description/
// ====================================================================

bool canJumpHelper(vector<int> &nums, int i, vector<int> &dp)
{
    int n = nums.size();

    if (i >= n)
    {
        return false;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    if (i == n - 1)
    {

        return true;
    }

    for (int j = 1; j <= nums[i]; j++)
    {
        if (canJumpHelper(nums, i + j, dp))
        {
            return dp[i] = true;
        }
    }
    return dp[i] = false;
}

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return true;
    }
    vector<int> dp(n + 1, -1);
    return canJumpHelper(nums, 0, dp);
}

// https://leetcode.com/problems/jump-game-iii/description/
// Jump Game III
bool canReachHelper(vector<int> &arr, int i, vector<int> &dp)
{
    int n = arr.size();
    if (i >= n || i < 0 || dp[i] == 1)
    {
        return false;
    }
    if (arr[i] == 0)
    {
        return true;
    }

    dp[i] = 1; // Marking the index as visited

    if (i + arr[i] < n && canReachHelper(arr, i + arr[i], dp))
    {
        return true;
    }
    if (i - arr[i] >= 0 && canReachHelper(arr, i - arr[i], dp))
    {
        return true;
    }
    return false;
}
bool canReach(vector<int> &arr, int start)
{
    int n = arr.size();
    vector<int> dp(n, 0);

    return canReachHelper(arr, start, dp);
}

bool canReach(const std::string &s, int minJump, int maxJump)
{
    int n = s.size();
    std::vector<bool> dp(n, false);
    dp[0] = true;

    int prefixSum = 0;

    for (int i = 1; i < n; ++i)
    {
        if (i >= minJump)
        {
            prefixSum += dp[i - minJump] ? 1 : 0;
        }
        if (i > maxJump)
        {
            prefixSum -= dp[i - maxJump - 1] ? 1 : 0;
        }

        dp[i] = (prefixSum > 0) && (s[i] == '0');
    }

    return dp[n - 1];
}

int minJumpsHelper(vector<int> &arr, int i, vector<int> &dp)
{
    int n = arr.size();

    if (i >= n)
    {
        return INT_MAX;
    }
    if (i == n - 1)
    {

        return 1;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int tempAns = INT_MAX;
    for (int j = i + 1; j < n && arr[i] == arr[j]; j++)
    {
        int temp = minJumpsHelper(arr, j, dp);
        if (temp != INT_MAX)
        {
            temp += 1;
        }

        tempAns = min(temp, tempAns);
    }
    //

    int temp = minJumpsHelper(arr, i - 1, dp);
    if (temp != INT_MAX)
    {
        temp += 1;
    }

    tempAns = min(temp, tempAns);

    temp = minJumpsHelper(arr, i + 1, dp);
    if (temp != INT_MAX)
    {
        temp += 1;
    }

    tempAns = min(temp, tempAns);
    return dp[i] = tempAns;
}

int minJumps(vector<int> &arr)
{
    int ans = INT_MAX;
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    minJumpsHelper(arr, 0, dp);
    return ans;
}

// i+1, i+k
int maxResultHelper(vector<int> &nums, int k, int i, vector<int> &dp)
{
    int n = nums.size();
    if (i >= n)
        return INT_MIN;

    if (i == n - 1)
        return nums[i];

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int sj = i + 1;
    int ej = min(n - 1, i + k);

    int score = INT_MIN;

    for (int j = sj; j <= ej; j++)
    {

        int temp;
        if (dp[j] != -1)
        {
            temp = nums[i] + dp[j];
        }
        else
        {
            dp[j] = maxResultHelper(nums, k, j, dp);
            temp = nums[i] + dp[j];
        }

        score = max(temp, score);
    }

    return dp[i] = score;
}
int maxResult(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> dp(n + 1, -1);
    return maxResultHelper(nums, k, 0, dp);
}

// 115. Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/
int numDistinctHelper(string s, string t, int i, int j)
{

    int n = s.size();
    int m = t.size();

    if ((i == n && j == m) || j == m)
    {
        return 1;
    }

    if (i >= n || j >= m)
    {
        return 0;
    }

    if (s[i] == t[j])
    {
        return numDistinctHelper(s, t, i + 1, j + 1) + numDistinctHelper(s, t, i + 1, j);
    }
    else
    {
        return numDistinctHelper(s, t, i + 1, j);
    }
}
int numDistinct(string s, string t)
{
    return numDistinctHelper(s, t, 0, 0);
}

// . Perfect Squares
// https://leetcode.com/problems/perfect-squares/

int numSquaresHelper(vector<int> &v, int i, int w, vector<vector<int>> &dp)
{

    if (i < 0 || w < 0)
    {
        return 1e6;
    }

    if (w == 0)
    {
        return 0;
    }

    if (dp[i][w] != -1)
    {
        return dp[i][w];
    }

    if (v[i] <= w)
    {
        return dp[i][w] = min(1 + numSquaresHelper(v, i, w - v[i], dp),
                              numSquaresHelper(v, i - 1, w, dp));
    }
    else
    {
        return dp[i][w] = numSquaresHelper(v, i - 1, w, dp);
    }
}
int numSquares(int n)
{
    if (n == 1)
    {
        return 1;
    }
    vector<int> sqr;

    for (int i = 1; i <= n / 2; i++)
    {
        int temp = i * i;
        if (temp <= n)
        {
            sqr.push_back(temp);
        }
        else
        {
            break;
        }
    }

    for (auto v : sqr)
    {
        cout << " " << v;
    }

    cout << endl;
    int s = sqr.size();
    vector<vector<int>> dp(s + 1, vector<int>(n + 1, -1));
    return numSquaresHelper(sqr, s - 1, n, dp);
}

// https://leetcode.com/problems/decode-ways/description/
// 91. Decode Ways

int help(string s, int i, vector<int> &dp)
{
    int n = s.size();
    if (n <= i)
    {
        return 1;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int opt1 = s[i] - '0';

    int opt2 = 0;

    if (opt1 > 0 && i + 1 < n)
    {
        opt2 = opt1 * 10 + (s[i + 1] - '0');
    }

    int x1 = 0, x2 = 0;
    if (opt1 > 0)
    {
        x1 = help(s, i + 1, dp);
    }

    if (opt1 > 0 && opt2 > 0 && opt2 < 27)
    {
        x2 = help(s, i + 2, dp);
    }
    return dp[i] = x1 + x2;
}
int numDecodings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, -1);
    return help(s, 0, dp);
}

int numTreesHelper(int n)
{
    if (n < 2)
    {
        return 0;
    }

    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        c += numTreesHelper(i - 1) * numTreesHelper(n - i);
    }
    return c;
}
int numTrees(int n)
{

    return numTreesHelper(n);
}

int main()
{

    // vector<int> v = {3, 2, 1, 0, 4};
    // cout << canJump(v);
    cout << "Number of unique tree : " << numTrees(3);
    // cout << countPaths({{1, 1},
    //                     {3, 4}});

    cout << "\nDone with it";

    return 0;
}