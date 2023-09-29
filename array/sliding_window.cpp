#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
// sliding window

// fint maximum sum of window size k

void max_sum_subArray(vector<int> &v, int k)
{
    int n = v.size();
    if (k > n)
    {
        cout << "K is bigger than N";
        return;
    }

    // //  ifn tof window size k
    // int sum = 0;
    // for (int i = 0; i < k; i++)
    // {
    //     sum += v[i];
    // }
    // // finding for maximum sum;

    // int maxSum = sum;

    // for (int i = k; i < n; i++)
    // {
    //     sum += v[i];
    //     sum -= v[i - k];
    //     maxSum = max(sum, maxSum);
    // }
    // cout << "Max sum : " << maxSum;

    int i, j;
    i = j = 0;
    int sum = 0;
    int maxSum = sum;
    while (j < n)
    {
        sum += v[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            maxSum = max(sum, maxSum);
            sum -= v[i];
            i++;
            j++;
        }
    }

    cout << "Max sum : " << maxSum;
}
// first negative numver in window size k
void first_negative_numberInK(vector<int> v, int k)
{
    int n, i, j;
    i = j = 0;
    n = v.size();
    while (j < n)
    {

        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            if (v[i] < 0)
            {
                cout << "first negative at " << i << " " << v[i] << endl;
            }
            i++;
            j++;
        }
    }
}

// slinding window for finding anagram
int finding_anagram_value(string ang)
{
    int count = 1;

    for (int i = 0; i < ang.size(); i++)
    {
        count *= (ang[i] - 'a' + 2) * ((ang[i] - 'a' + 3) / 2);
    }

    return count;
}
void finding_anagram(string str, string ang)
{
    int ans = 0;
    int n = str.size();
    int k = ang.size();
    int anagram_value = finding_anagram_value(ang);

    cout
        << "ee" << anagram_value << endl;

    int i = 0,
        j = 0;
    int angram_value_size_k = 1;

    while (j < n)
    {

        if (j < k)
        {
            angram_value_size_k *= (str[j] - 'a' + 2) * ((str[j] - 'a' + 3) / 2);
            j++;
            if (
                angram_value_size_k == anagram_value && j == k)
            {
                ans++;
            }
        }
        else
        {
            if (
                angram_value_size_k == anagram_value)
            {
                ans++;
            }

            angram_value_size_k *= (str[j] - 'a' + 2) * ((str[j] - 'a' + 3) / 2);
            angram_value_size_k /= (str[i] - 'a' + 2) * ((str[i] - 'a' + 3) / 2);
            i++;
            j++;
        }
    }

    cout << "ans is :" << ans;
}

// Maximum of all subarrays of size k | Sliding Window

// finding size of the maximum size window of sum k
void maxSizeWindow(vector<int> &arr, int k)
{
    int sum = 0;
    int i = 0, j = 0;
    int maxWindow = INT8_MIN;
    int n = arr.size();
    while (j < n)
    {
        sum += arr[j];
        if (sum != k && j != n - 1)
        {
            j++;
        }
        else
        {
            if (sum == k)
            {
                maxWindow = max(maxWindow, j - i + 1);
            }
            sum = 0;
            i++;
            j = i;
        }
    }
    cout << "Maximum window size : " << maxWindow;
}

// finding the longest substring with k unique charaters
void longest_substring_with_k(string &str, int k)
{
    int ans = INT8_MIN;
    int i = 0, j = 0;
    int n = str.size();
    unordered_map<int, int> mp;

    while (j < n)
    {
        mp[str[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                {
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }

    cout << "Ans is : " << ans;
}
// longest substring with all charaters should be unique
void longest_substring_with_all(string &str)
{
    int ans = INT8_MIN;
    int i = 0, j = 0;
    int n = str.size();
    unordered_map<char, int> mp;
    while (j < n)
    {
        mp[str[j]]++;

        if (mp.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                {

                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }
    cout << "Ans : " << ans;
}

// Pick maximum number of toys with the maximum number od price should be k
void pick_toys(vector<int> &arr, int k)
{
    int i = 0, j = 0;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int sum = 0;
    int ans = INT8_MIN;

    while (j < n)
    {
        sum += arr[j];
        if (sum <= k)
        {
            if ((j - i + 1) > ans)
            {
                ans = j - i + 1;
            }
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }

    cout << ans;
}

// =============================================================
// 76. Minimum Window Substring leetcode
void minimum_window_substring(string s, string t)
{
    int i = 0, j = 0;
    int n = s.size();
    int ans = INT8_MAX;
    unordered_map<char, int> mt;
    for (int k = 0; k < t.size(); k++)
    {
        mt[t[k]]++;
    }
    int count = mt.size();
    while (j < n)
    {
        if (mt.find(s[j]) != mt.end())
        {
            mt[s[j]]--;
            if (mt[s[j]] == 0)
            {
                count--;
            }
        }

        while (count == 0)
        {
            ans = min(ans, j - i + 1); // Update answer when a valid window is found

            if (mt.find(s[i]) != mt.end())
            {
                mt[s[i]]++;
                if (mt[s[i]] > 0)
                {
                    count++;
                }
            }

            i++;
        }

        j++;
    }

    cout << ans;
}

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    minimum_window_substring(s, t);
    cout << "\nCode run";
    return 0;
}