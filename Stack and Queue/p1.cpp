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
        if(!s.empty() && arr[i]>arr[s.top()]){
            while(!s.empty() && arr[i]>arr[s.top()]){
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



int main(){

       int arr[] = {68, 735, 101, 770, 525, 279, 559, 563, 465, 106, 146, 82, 28, 362, 492, 596, 743, 28, 637, 392, 205, 703, 154, 293, 383, 622, 317, 519, 696, 648, 127, 372, 339, 270, 713, 68, 700, 236, 295, 704, 612, 123};

        calculateSpan(arr,42);
      

    cout<<"\nMohd Haider"<<endl;
    return 0;
}