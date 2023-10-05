#include<iostream>
#include<vector>

using namespace std;


// min heap;
class Heap {
        private:
        vector<int>arr;
        int parent(int i){
            return (i-1)/2;
        }
        int left(int i){
            return 2*i+1;
        }
        int right(int i){
            return 2*i+2;
        }
        void upheap(int i){
            if(i==0)return ;

            int p=parent(i);
            if(arr[i]<arr[p]){
                swap(arr[i],arr[p]);
                upheap(p);
            }
        }

        void downheap(int i){
            if( i==0)return ;
            int l=left(i);
            int r=right(i);
            int n=arr.size();

            
            


        }
public:
        void insert(int x){
            arr.push_back(x);
            int i=arr.size()-1;
            upheap(i);
        }

        int getTop(){
            int n=arr.size();
            if(n<1) return -1;

            int top=arr[0];
            
            int last= arr[n-1];

            arr[0]=last;

            if(n>1){

            arr.pop_back();
            downheap(0);
            }


            return top;

        }

        

};

int main(){
    Heap h;
    h.insert(5);
    h.insert(2);
    h.insert(10);

    cout<<"Top "<<h.getTop()<<endl;
    cout<<"Top "<<h.getTop()<<endl;
    cout<<"\nProgram exited : ";
    return 0;
}