#include<iostream>
#include<vector>
#include<climits>

using namespace std;



   int maxPro(vector<int>&cuts,int n,int i,int num){


        if(i>=cuts.size()){
            return n==num?INT_MIN:n;
        }

        return max(
                cuts[i]*maxPro(cuts,n-cuts[i],i+1,num),
                maxPro(cuts,n,i+1,num)
        );

    }

    int integerBreak(int n) {
        vector<int>cuts;

        for(int i=1;i<n;i++){
            cuts.push_back(i);
        }

        cout<<cuts.size()<<endl;

        return maxPro(cuts,n,0,n);
    }



int main(){

    cout<<integerBreak(9)<<endl;

    cout<<"\nEnd";

    return 0;
}