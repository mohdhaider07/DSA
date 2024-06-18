#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int helper(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    // another base case

    if (i >= s1.size() || j >= s2.size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if ((s1[i] == s2[j]))
    {
        return dp[i][j] = 1 + helper(s1, s2, i + 1, j + 1, dp);
    }

    return dp[i][j] = max(helper(s1, s2, i + 1, j, dp), helper(s1, s2, i, j + 1, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));

    return helper(text1, text2, 0, 0, dp);
}

// top down
int lcsMemo(string s1, string s2)
{
    int n, m;
    n = s1.size();
    m = s2.size();

    if (n == 0 || m == 0)
    {
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

string lcsMemoString(string s1, string s2)
{
    int n, m;
    n = s1.size();
    m = s2.size();

    if (n == 0 || m == 0)
    {
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans = "";

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans = s1[i - 1] + ans;
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    return ans;
}

// 718. Maximum Length of Repeated Subarray
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
int findlengthHelper(vector<int> &n1, vector<int> &n2, int i, int j, int ans)
{
    if (i >= n1.size() || j >= n2.size())
    {
        return ans;
    }
    if (n1[i] == n2[j])
    {
        ans = findlengthHelper(n1, n2, i + 1, j + 1, ans + 1);
    }

    ans = max(ans, max(
                       findlengthHelper(n1, n2, i + 1, j, 0),
                       findlengthHelper(n1, n2, i, j + 1, 0)));

    return ans;
}

int findLength(vector<int> nums1, vector<int> nums2)
{
    int ans = 0;
    return findlengthHelper(nums1, nums2, 0, 0, ans);
}

int findLen(vector<int> nums1, vector<int> nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    // code here
    return (m + n) - lcsMemo(X, Y);
}

// longet common palindrome subsequence

int longestPalindromeSubseqLcs(string s1, string s2, int i, int j)
{
    if (i >= s1.size() || j >= s2.size())
    {
        return 0;
    }

    if (s1[i] == s2[j])
    {
        return 1 + longestPalindromeSubseqLcs(s1, s2, i + 1, j + 1);
    }

    return max(
        longestPalindromeSubseqLcs(s1, s2, i + 1, j),
        longestPalindromeSubseqLcs(s1, s2, i, j + 1));
}

int longestPalindromeSubseq(string s)
{

    string s2 = s;
    reverse(s2.begin(), s2.end());

    return lcsMemo(s, s2);
}

// sortest common supersequence
// https://leetcode.com/problems/shortest-common-supersequence/
string shortestCommonSupersequenceTopDown(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
            }
        }
    }

    string ans = "";

    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans = s1[i - 1] + ans;
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                ans = s2[j - 1] + ans;
                j--;
            }
            else
            {
                ans = s1[i - 1] + ans;
                i--;
            }
        }
    }

    while (i > 0)
    {
        ans = s1[i - 1] + ans;
        i--;
    }
    while (j > 0)
    {
        ans = s2[j - 1] + ans;
        j--;
    }

    return ans;
}

string shortestCommonSupersequence(string str1, string str2)
{
    return shortestCommonSupersequenceTopDown(str1, str2);
}

// https://leetcode.com/problems/longest-subsequence-repeated-k-times/description/
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// https://leetcode.com/problems/wildcard-matching/
bool isMatch(string s, string p)
{
    if (p.empty())
    {
        return s.empty();
    }

    if (p[0] == '*')
    {
        // If we encounter '*', we have two choices:
        // 1. Match 0 characters with '*'
        // 2. Match 1 character with '*'
        return isMatch(s, p.substr(1)) ||
               (!s.empty() && isMatch(s.substr(1), p));
    }

    if (!s.empty() && (s[0] == p[0] || p[0] == '?'))
    {

        return isMatch(s.substr(1), p.substr(1));
    }

    return false;
}

int main()
{

    cout << isMatch("adceb", "*a*b");

    cout << "\nPrpgram end";

    return 0;
}