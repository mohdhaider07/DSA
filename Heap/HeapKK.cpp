#include<iostream>
#include<vector>
#include<climits>

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
       
            int l=left(i);
            int r=right(i);
            int n=arr.size();
            
            int min = i;

            if(l<n && arr[l]<arr[min] ){
                min = l;
            }
            if(r<n && arr[r]<arr[min]){
                    min=r;
            }

            if(min!=i){
                swap(arr[i],arr[min]);
                downheap(min);
            }
        }

public:


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

        void insert(int x){
            arr.push_back(x);
            int i=arr.size()-1;
            upheap(i);
        }          

};

    // void buildHeap(vector<int> &v){
    // int n=v.size();

    // for(int i=n/2-1;i>=0;i--){
    //     downheap(i);
    // }
    // }

int main(){
    Heap h;
    h.insert(22);
    h.insert(54);
    h.insert(45);
    h.insert(58);
    h.insert(96);
    h.insert(85);
    h.insert(23);


 
    cout<<"\nProgram exited : ";
    return 0;
}