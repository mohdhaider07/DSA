#include<iostream>
#include<vector>
using namespace std;


// 0 1 knapsack prpblem 

int knapsack(vector<int>profit,vector<int>wight,int capacity,int i){
    if(i>profit.size()|| capacity<=0){
        return 0;
    }

    if(wight[i]>capacity){
        return knapsack(profit,wight,capacity,i+1);
    }else{
        return max( 
            knapsack(profit,wight,capacity - wight[i],i+1) + profit[i], knapsack(profit,wight,capacity,i+1)
        )
    }
}

int main(){

    vector<int>w{4,5,1};
    vector<int>p{1,2,3};
  cout<<knapsack(p,w,4,0);
    cout<<"\n Code executed";
    return 0;
}