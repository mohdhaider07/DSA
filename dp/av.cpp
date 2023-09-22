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

bool canPartition(vector<int> &nums)
{
    int i = nums.size() - 1;
    return canPartitionHelper(nums, i, 0, 0);
}

bool isSubsetSumHelper(vector<int>arr,int sum, int i){
     if(sum==0) return true;

    int n=arr.size();

    if(i<0){
        return false;
    }

    if(arr[i]>sum){
        return isSubsetSumHelper(arr,sum,i-1);
    }else{
        return isSubsetSumHelper(arr,sum-arr[i],i-1) || isSubsetSumHelper(arr,sum,i-1);
    }
}

// bool isSubsetSum(vector<int>arr, int sum){
//     // code here 
//     if(sum==0) return true;
//     int n=arr.size();
//     if(n==0){
//         return false;
//     }
//     int i=arr.size()-1; 
//     return isSubsetSumHelper(arr,sum,i);
// }

//  top down 

bool isSubsetSum(vector<int>v, int sum){
    if(sum==0) return true;
    int n=v.size();
    if(n==0){
        return false;
    }


    // bool arr[n+1][sum+1]=false;
     vector<vector<bool>> arr(n + 1, vector<bool>(sum + 1, false));

    for(int k=0;k<=sum;k++){
        arr[0][k] = false ;
    }

    for(int k=0;k<=n;k++){
        arr[k][0] = true ;
    }

    // for loop
    for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(v[i]>j){
                    arr[i][j] = arr[i-1][j];
                }else{
                    arr[i][j] = arr[i-1][j-v[i]] || arr[i-1][j];
                }
            }
    }

return arr[n][sum];

}



int main()
{
    vector<int>v{3, 34, 4, 12, 5, 2};
    cout << "output is : "<<isSubsetSum(v,30);
    cout << "\n Code executed";
    return 0;
}