#include<iostream>
#include<vector>
#include<stack>
using namespace std;




vector<int> getNextLargest(vector<int>arr){
    if(arr.size()==1){
        return {-1};
    }

    vector<int> ans;
    stack<int>s;
    int n=arr.size();

    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.insert(ans.begin(),-1);
            s.push(arr[i]);
        }else if (!s.empty() && arr[i]>s.top()){
            while(!s.empty() && arr[i]>s.top()){
                s.pop();
            }
            if(s.empty()){
                 ans.insert(ans.begin(),-1);
                s.push(arr[i]);
            }else{
                ans.insert(ans.begin(),s.top());
                s.push(arr[i]);
            }
        }else {
             ans.insert(ans.begin(),s.top());
                s.push(arr[i]);
        }
    }
    return ans;
}



int main(){
        vector<int>v{6 ,8, 0, 1, 3};
        v=getNextLargest(v);

        for(auto i:v){
            cout<<i<<" ";
        }


    cout<<"\nMohd Haider"<<endl;
    return 0;
}