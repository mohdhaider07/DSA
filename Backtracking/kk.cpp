#include<iostream>
#include<vector>
using namespace std;



int coutTheway(vector<vector<int>>matrix,int i,int j,int &n){
    if(i>=n-1||j>=n-1){
        return 1;
    }

    int down=0, right=0;
    if(j<n-1){
        right = coutTheway(matrix,i,j+1,n);
    }
    if(i<n-1){
        down  = coutTheway(matrix,i+1,j,n);
    }

    return right + down; 

}


int  main(){

int n=3;
vector<vector<int>>matrix(n,vector<int>(n,0));

cout<< "The number of ways : "<<coutTheway(matrix,0,0,n);



cout<<"\nEnd of the Program";
    return 0;
}