#include<iostream>
#include<vector>
#include<stack>
using namespace std;



//  next largest to the right
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

// next smallest element in the right
vector<int> getNextSmaller(vector<int>arr){
    if(arr.size()==1){
        return {-1};
    }
    int n=arr.size();
    vector<int>ans;
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.insert(ans.begin(),-1);
            s.push(arr[i]);   
        }else if(
            !s.empty() && s.top()>arr[i]
        ){
            while (  !s.empty() && s.top()>arr[i])
            {
                s.pop();
            }

            if(s.empty()){
            ans.insert(ans.begin(),-1);
            s.push(arr[i]);   
            }else{
                ans.insert(ans.begin(),s.top());
                s.push(arr[i]);
            }
            
        }else{
            ans.insert(ans.begin(),s.top());
            s.push(arr[i]);
        }
    }
return ans;
}

//  next largest tp the left
vector<int> getNextLargestLeft(vector<int>arr){
    int n=arr.size();

    if(n==1){
        return {-1};
    }
    vector<int> ans;
    stack<int>s;

      for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(-1);
            s.push(arr[i]);
        }else if (!s.empty() && arr[i]>s.top()){
            while(!s.empty() && arr[i]>s.top()){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
                s.push(arr[i]);
            }else{
                ans.push_back(s.top());
                s.push(arr[i]);
            }
        }else {
             ans.push_back(s.top());
                s.push(arr[i]);
        }
    }

    return ans;
}

// nearest smalest to the left 
vector<int> getNextSmallestLeft(vector<int>arr){
     int n=arr.size();

    if(n==1){
        return {-1};
    }
    vector<int> ans;
    stack<int>s;

      for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(-1);
            s.push(arr[i]);
        }else if (!s.empty() && arr[i]<s.top()){
            while(!s.empty() && arr[i]<s.top()){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
                s.push(arr[i]);
            }else{
                ans.push_back(s.top());
                s.push(arr[i]);
            }
        }else {
             ans.push_back(s.top());
                s.push(arr[i]);
        }
    }

    return ans;
}

int main(){
        vector<int>v{1, 6, 4, 10, 2, 5};
        v=getNextSmallestLeft(v);

        for(auto i:v){
            cout<<i<<" ";
        }


    cout<<"\nMohd Haider"<<endl;
    return 0;
}