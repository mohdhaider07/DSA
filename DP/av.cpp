#include <iostream>
#include <vector>
using namespace std;

// 0 1 knapsack prpblem

int knapsack(vector<int> profit, vector<int> wight, int capacity, int i)
{
    if (i > profit.size() || capacity <= 0)
    {
        return 0;
    }

    if (wight[i] > capacity)
    {
        return knapsack(profit, wight, capacity, i + 1);
    }
    else
    {
        return max(
            knapsack(profit, wight, capacity - wight[i], i + 1) + profit[i], knapsack(profit, wight, capacity, i + 1));
    }
}

// Partition Equal Subset Sum
bool canPartitionHelper(vector<int> &nums, int i, int left, int right)
{
    if (i < 0)
    {
        return left == right;
    }

    return canPartitionHelper(nums, i - 1, left + nums[i], right) || canPartitionHelper(nums, i - 1, left, right + nums[i]);
}

/*
bool canPartition(vector<int> &nums)
{
    int i = nums.size() - 1;
    return canPartitionHelper(nums, i, 0, 0);
}
*/

// top down can partition

/*
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return true;
    }
    if (n == 1)
    {
        return false;
    }

    int sum = 0;
    for (auto n : nums)
    {
        sum += n;
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    int d = sum / 2;

    vector<vector<bool>> matrix(n + 1, vector<bool>(d + 1, false));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            if (i == 0)
            {
                matrix[i][j] = false;
            }
            if (j == 0)
            {
                matrix[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            if (nums[i - 1] > j)
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                matrix[i][j] = matrix[i - 1][j - nums[i - 1]] ||
                               matrix[i - 1][j];
            }
        }
    }
    return matrix[n][d];
}
*/
/*
void isSubsetSumHelper(vector<int> arr, int sum, int i, vector<int> v)
{
    if (sum == 0)
    {
        cout << "{";
        for (auto i : v)
        {
            cout << i << ",";
        }
        cout << "}" << endl;

        return;
    }

    int n = arr.size();

    if (i < 0)
    {
        return;
    }

    if (arr[i] > sum)
    {
        isSubsetSumHelper(arr, sum, i - 1, v);
    }
    else
    {
        isSubsetSumHelper(arr, sum, i - 1, v);
        v.push_back(arr[i]);
        isSubsetSumHelper(arr, sum - arr[i], i - 1, v);
    }
}
*/
/*
void isSubsetSum(vector<int> arr, int sum)
{
    // code here
    if (sum == 0)
        return;
    int n = arr.size();
    if (n == 0)
    {
        return;
    }
    int i = arr.size() - 1;
    isSubsetSumHelper(arr, sum, i, {});
}
*/
//  top down dp
/*
bool isSubsetSum(vector<int> v, int sum)
{
    if (sum == 0)
        return true;
    int n = v.size();
    if (n == 0)
    {
        return false;
    }

    vector<vector<bool>> arr(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                arr[i][j] = false;
            }
            if (j == 0)
            {
                arr[i][j] = true;
            }
        }
    }

    // for loop
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            if (v[i - 1] > j)
            {
                arr[i][j] = arr[i - 1][j];
            }
            else
            {
                arr[i][j] = arr[i - 1][j - v[i - 1]] || arr[i - 1][j];
            }
        }
    }

    return arr[n][sum];
}
*/

//

int countNumOfSubsetk(vector<int> arr, int sum)
{
    if (sum == 0)
        return 1;

    int n = arr.size();

    if (n == 0)
    {
        return 0;
    }

    vector<vector<int>> matrix(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        matrix[i][0] = 1; // Initialize the first column to 1
    }


        int mod=1e9+7;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                matrix[i][j] = (matrix[i - 1][j - arr[i - 1]] + matrix[i - 1][j])%mod;
            }
        }
    }

    return matrix[n][sum];
}

// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

int minimumDifference(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (auto n : nums)
    {
        sum += std::abs(n);
    }

    int d = std::abs(sum / 2);

    vector<vector<bool>> matrix(n + 1, vector<bool>(d + 1, false));

    for(int i=0;i<=n;i++){
        matrix[i][0]=true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            if (nums[i - 1] > j)
            {                matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                matrix[i][j] = matrix[i - 1][j - nums[i - 1]] ||
                               matrix[i - 1][j];
            }
        }
    }
 
    cout << "\n##############################################";

    int ans = INT8_MAX;

    for (int i = d; i >= 0; --i)
    {
        if (matrix[n][i])
        {
            ans=min(ans ,sum - 2 * i);
        }
    }

    return ans;
}

// 11 Count the number of subset with a given difference

int countThesubsetwithDiff(vector<int>nums,int diff){
    int n=nums.size();
    if(n==0){
        return 0;
    }
    if(n==1){
        if(diff==nums[0]){
            return 1;
        }
        return 0;

    }

    



}

int main()
{
    vector<int> v{3,9,7,3};
    cout << "output is : " << minimumDifference(v);
    cout << "\n end of program";
    return 0;
}