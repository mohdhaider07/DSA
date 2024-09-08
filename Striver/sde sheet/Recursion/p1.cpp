// cpp
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void permuteHelper(vector<int> &nums,int index,vector<vector<int>>&ans){
    int n=nums.size();
    if(index>=n){
        ans.push_back(nums);
        return ;
    }

    for (int i = index; i < n; i++)
    {
        swap(nums[index],nums[i]);
        permuteHelper(nums,index+1,ans);
        swap(nums[index],nums[i]);
    }
    
}

 vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permuteHelper(nums,0,ans);

        return ans;
    }

// N queen problem 
 vector<vector<string>> solveNQueens(int n) {
        
    }


int main()
{
    cout << "Enter the size of the array: \n";
    return 0;
}