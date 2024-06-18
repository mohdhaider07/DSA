#include<iostream>
#include<vector>
using namespace std;

// rod cutting problem
/*
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22*/
// recursive code
/*
int cutRodHelper(vector<int>& price,vector<int> &len,int n,int i){
        if(n==0)return 0;
        if(i==len.size()){
            return 0;
        }
        if(len[i]>n){
            return cutRodHelper(price,len,n,i+1);
        }else{
            return max((price[i] + cutRodHelper(price,len,n-len[i],i))
                ,
                cutRodHelper(price,len,n,i+1)
            );
        }
}

int cutRod(vector<int>price,int n){
    if(n==1){
        return price[0];
    }

    vector<int>len;
    for(int i=1;i<=n;i++){
        len.push_back(i);
    }

return cutRodHelper(price,len,n,0);

}
*/
/*
 int cutRod(vector<int>price, int n) {
        //code here
        if(n==1){
            return price[0];
        }

        vector<int>len;
        for(int i=1;i<=n;i++){
            len.push_back(i);
        }

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(len[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],
                    dp[i-1][j]
                    );
                }
            }
        }

        return dp[n][n];

}
*/

// Minimum Cost to Cut a Stick
int minCost(int n, vector<int>& cuts) {
        
        int c=cuts.size();
        vector<vector<int>>dp(c+1,vector<int>(n+1,0));

        for(int i=1;i<=c;i++){
            for(int j=0;j<=n;j++){
                
                if(cuts[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=min(j+dp[i][j-cuts[i-1]],
                    dp[i-1][j]
                    );
                }
            }
        }
        return dp[c][n];

    }

int main(){
    vector<int>v{1,3,4,5};
    cout<<"ans is "<<minCost(7,v);
    cout<<"\nprogram ended";
    return 0;
}