#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <queue>

using namespace std;

string isKSortedArray(int arr[], int n, int k)
{
    stack<int> s1;
    stack<int> s2;

    for (int i = 0; i < n; i++)
    {
        if (!s1.empty() && arr[s1.top()] < arr[i])
        {
            while (!s1.empty() && arr[s1.top()] < arr[i])
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(i);
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        else
        {
            s1.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int t = s1.top();
        s1.pop();
        if (t < i - k || t > i + k)
        {
            return "No";
        }
    }

    return "Yes";
}

// https://leetcode.com/problems/top-k-frequent-elements/submissions/
vector<int> topKFrequent(vector<int> &nums, int k)
{

    map<int, int> mp;
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min; // min value in top
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto m : mp)
    {
        min.push({m.second, m.first});
        if (min.size() > k)
        {
            min.pop();
        }
    }

    while (!min.empty())
    {
        ans.push_back(min.top().second);
        min.pop();
    }

    return ans;
}

int main()
{

    cout << "\nCode executed successfully";
    return 0;
}