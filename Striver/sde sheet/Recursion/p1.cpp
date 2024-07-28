// cpp
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// subset sum problem
// subset is all the combinaiton possible within the array
// subarray is you can remove elements from the starting from the end but not from between of the word

void subsetSumsHelper(vector<int> arr, int i, int n, int sum, vector<int> &ans)
{
    if (i >= n)
    {
        ans.push_back(sum);
        return;
    }
    subsetSumsHelper(arr, i + 1, n, sum + arr[i], ans);
    subsetSumsHelper(arr, i + 1, n, sum, ans);
}

vector<int> subsetSums(vector<int> arr, int n)
{
    // Write Your Code here
    vector<int> ans;
    subsetSumsHelper(arr, 0, n, 0, ans);
    return ans;
}
void subsetsWithDupHelper(vector<int> arr, int i, int n, vector<int> v, set<vector<int>> &myset)
{
    if (i >= n)
    {
        myset.insert(v);
        return;
    }
    vector<int> newV = v;
    v.push_back(arr[i]);
    subsetsWithDupHelper(arr, i + 1, n, v, myset);
    subsetsWithDupHelper(arr, i + 1, n, newV, myset);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    set<vector<int>> myset;

    subsetsWithDupHelper(nums, 0, n, {}, myset);

    for (vector<int> v : myset)
    {
        ans.push_back(v);
    }

    return ans;
}

int main()
{

    return 0;
}