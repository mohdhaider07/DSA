#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// DEPTH FIRST SEARCH (DFS) RECURSIVE APPROCH
void printDFS(vector<vector<int>>&matrix,int sv,vector<int>&visited){
        cout<<sv<<" ";
        visited[sv]=1;
        int n=matrix.size();
            for(int i=0;i<n;i++){
                if(matrix[sv][i]==1&& visited[i]==0){
                    printDFS(matrix,i,visited);
                }
            }
}

// DFS
void DFS(vector<vector<int>>&matrix){
    int n=matrix.size();
        vector<int>visited(n,0);
        int c=0;// count the components
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            c++;
            printDFS(matrix,i,visited);
        }
    }
    cout<<"Number of Connected componenets is the graph: "<<c;
}

// Breadth first  search it is similar to level order traversel
void printBFS(vector<vector<int>>&matrix,int sv,vector<int>&visited){
queue<int>q;
int n=matrix.size();

q.push(sv);

while (!q.empty())
{
    int f=q.front();
    q.pop();
    cout<<f<<" ";
    visited[f]=1;
    for(int i=0;i<n;i++){
    if(matrix[f][i]==1&&!visited[i]==1){
    q.push(i);
        }
    }
}
}

void BFS(vector<vector<int>>&matrix){
    int n=matrix.size();
    vector<int>visited(n,0);int c=0;// number of connected componentes
    for (int i = 0; i < n; i++)
    {
        if (visited[i]==0)
        {c++;
            printBFS(matrix,i,visited);
        }
        
    }
    
cout<<"number of connected componentes"<<c;
}


int main(){
    int n;
    cout<<"Enter vertex: ";
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n,0));
    int e;
    cout<<"Enter edge: ";
    cin>>e;
    for(int i=0;i<e;i++){
        cout<<"enter edge between vertex: ";
        int x,y;
        cin>>x>>y;
        matrix[x][y]=matrix[y][x]=1;
    }

BFS(matrix);
    return 0;
}