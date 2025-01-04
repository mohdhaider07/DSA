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

// N queen problem 

bool isSafe(int row, int col, vector<string> &board,int n){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q')return false;
    }
    // check for the upper-left diagonal
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--, j--){
        if(board[i][j]=='Q') return false;
    }
    for(int i=row-1,j = col+1; i>=0&& j<n;i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}

void solve(int row, vector<string>&board,vector<vector<string>>&solutions,int n){
    // if all queens are placed save the solution
    if(row==n){
        solutions.push_back(board);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(row+1,board,solutions,n);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>solutions;
        vector<string>board(n,string(n,'.'));
        solve(0,board,solutions,n);
        return solutions;
    }

int main()
{
    cout << "Enter the size of the array: \n";
    return 0;
}