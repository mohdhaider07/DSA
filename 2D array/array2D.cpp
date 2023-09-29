#include<bits/stdc++.h>

using namespace std;


//diagonal traversal
void findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        if(m<1||n<1){
            return ;
        }
        int r=0,c=0;
        int i=0;
        vector<int>ans(m*n);

        bool up=true;

        while(r<m&&c<n){
            if(up){
                while(r>0&&c<n-1){
                    ans[i++]=mat[r][c];
                    r--;
                    c++;
                }
                ans[i++]=mat[r][c];
                if(c==n-1){
                    r++;
                }else{
                    c++;
                }
            }else{
                while (r<m-1&&c>0)
                {
                     ans[i++]=mat[r][c];
                    r++;
                    c--;  
                }
                  ans[i++]=mat[r][c];
                  if(r==m-1){
                    c++;
                }else{
                    r++;
                }
            }

        up=!up;
        }

for(auto i:ans){
    cout<<i<<" ";
}
    }

// set zero 

void setZeroes(vector<vector<int>>& matrix) {
   
    int m=matrix.size();
    int n=matrix[0].size();

    if(m<1||n<1){
            return ;
        }

    vector<vector<int>> m1=matrix;

    for(int i=0;i<m;i++){
        for (int  j = 0; j < n; j++)
        {
            if(matrix[i][j]==0){
                for(int k=0;k<m;k++){
                    m1[k][j]=0;
                }
                for(int k=0;k<n;k++){
                    m1[i][k]=0;
                }
            }
        }
    }

   


 for(int i=0;i<m;i++){
        for (int  j = 0; j < n; j++)
        {
            cout<<m1[i][j]<<",";
        }
        cout<<endl;
        }
        
    }

    // pring matrix spiral order

     void spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m<1){
            return;
        }
        int n=matrix[0].size();
         if(n<1){
            return;
        }

        int l=0,r=n;
        int t=0,b=m;

        while (l<r&&t<b)
        {
            // goint left to ringt
            for(int i=l;i<r;i++){
                cout<<matrix[t][i];
            }
                t+=1;
            //goint top to bottom
            for (int  i = t; i < b; i++)
            {
                cout<<matrix[i][r-1];
            }
                r-=1;

            // checkint the condition
            if(!(l<r&&t<b))
            break;

            //goint right to left
            for(int i=r-1;i>=l;i--){
                cout<<matrix[b-1][i];
            }
                b-=1;
            for(int i=b-1;i>=t;i--){
                cout<<matrix[i][l];
            }
            l+=1;
        }
    }

    // rotate 90deg clock wise
void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n<2){
            return ;
        }

        int l=0,r=n-1;
        while(l<r){

            for(int i=l;i<r;i++){
                int top=l,bottom=r;
                // save top left
                int topLeft=matrix[top][l+i];

                // bottom left into top left
                matrix[top][l+i]=matrix[bottom-i][l];

                // bottom right into bottom left

                matrix[bottom-i][l]=matrix[bottom][r-i];

                // top right into bottom right 
                matrix[bottom][r-i]=matrix[top+i][r];

                // top left into top right

                matrix[top+i][r]=topLeft;

            }
            r--;
            l++;
        }


}



int main(){
    
vector<vector<int>> mat{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

rotate(mat);

    return 0;
}
