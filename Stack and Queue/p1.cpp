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

vector<int>getNextLargestElementIndex(int arr[],int n){

    if(n==1){
    return {-1};
    }
    vector<int>ans;
    stack<int>s;

    ans.push_back(-2);
    s.push(0);

    for(int i=1;i<n;i++){
        if(!s.empty() && arr[i]>= arr[s.top()]){
            while(!s.empty() && arr[i]>= arr[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
                s.push(i);
            }else{
                ans.push_back(s.top());
                s.push(i);
            }
        }else {
            ans.push_back(s.top());
            s.push(i);
        }
    }
return ans;
}

void calculateSpan(int price[], int n)
{
    // Your code here
    if(n==1){
    return ;
    }
    vector<int>ans;
    vector<int>indexNextGreaterLeft=getNextLargestElementIndex(price,n);

     for(auto i: indexNextGreaterLeft){
        cout<<i<<" ";
    }

    for(int i=0;i<n;i++){
        if(indexNextGreaterLeft[i]==-2){
            ans.push_back(1);
        }else{
            int stockSpan=i-indexNextGreaterLeft[i];
            ans.push_back(stockSpan);
        }
    }
cout<<"\n########################################################################"<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }

}


// ***********************************************************************
// get index of next smallest to the right
 vector<int> getIndexOfSmallerRight(vector<int> arr){
    if(arr.size()==1){
        return {0};
    }
    int n=arr.size();
    vector<int>ans;
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.insert(ans.begin(),n);
            s.push(i);
        }
        else if (
            !s.empty() && arr[s.top()]>=arr[i]
        ){
           while (!s.empty() && arr[s.top()]>=arr[i])
           {
           s.pop();
           }
           if(s.empty()){
            ans.insert(ans.begin(),n);
            s.push(i);
           }else{
            ans.insert(ans.begin(),s.top());
            s.push(i);
           }
        }else{
            ans.insert(ans.begin(),s.top());
            s.push(i);
        }
    }
    return ans;
 }

//   get the index of next smallest in the left side
vector<int> getIndexOfSmallestInLeft(vector<int>arr){
    int n=arr.size();
    if(n==1){
        return {0};
    }
    vector<int>ans;
    stack<int>s;

     for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(-1);
            s.push(i);
        }
        else if (
            !s.empty() && arr[s.top()] >= arr[i]
        ){
           while (!s.empty() && arr[s.top()] >= arr[i])
           {
           s.pop();
           }
           if(s.empty()){
            ans.push_back(-1);
            s.push(i);
           }else{
            ans.push_back(s.top());
            s.push(i);
           }
        }else{
            ans.push_back(s.top());
            s.push(i);
        }
    }

    return ans;
}

//  https://leetcode.com/problems/largest-rectangle-in-histogram/
int largestRectangleArea(vector<int>& heights) {
    if(heights.size()==1){
        return heights[0];
    }

    int n=heights.size();
    vector<int>left=getIndexOfSmallestInLeft(heights);
    vector<int>right=getIndexOfSmallerRight(heights);

    // for(auto i:left){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i:right){
    //     cout<<i<<" ";
    // }
    int maxArea=INT8_MIN;

    for(int i=0;i<n;i++){
        
        int width = right[i]-left[i]-1;
        int area = width * heights[i];
        maxArea=max(maxArea,area);

    }

return maxArea;
}



int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int> v;
         for(auto i:matrix[0]){
                v.push_back(i-'0');
         }
         int maxArea=largestRectangleArea(v);

         for(int i=1;i<matrix.size();i++){
            for(int l=0; l< matrix[i].size();l++){
                if(matrix[i][l]=='1'){
                    v[l]=v[l]+1;
                }else{
                    v[l]=0;
                }
            }
            int area=largestRectangleArea(v);
            maxArea=max(area,maxArea);
         }

        return maxArea;
}


int main(){
        vector<int>v{3,1,3,2,2};
    


    cout<<"\nMohd Haider"<<endl;
    return 0;
}