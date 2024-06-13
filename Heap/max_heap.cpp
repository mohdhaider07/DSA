#include <iostream>
#include <vector>
using namespace std;
   
   
   
    void Heap(vector<int>&nums,int i){
        int l=2*i+1;
        int r=2*i+2;
        int large=i;
        if(l<=nums.size()-1&&nums[l]>nums[i]){
            large=l;
        }
        if(r<=nums.size()-1&&nums[r]>nums[large]){
            large=r;
        }

            if(large!=i){
                swap(nums[i],nums[large]);
                Heap(nums,large);
            }

    }

    void buildHeap(vector<int>&nums){
        for(int i=(nums.size()/2)-1;i>=0;--i){
            Heap(nums,i);
        }
    }


    int findKthLargest(vector<int>& nums, int k) {
        buildHeap(nums);

        
        while(--k){

            int last=nums[nums.size()-1];
            nums[0]=last;
            nums.pop_back();
            Heap(nums,0);

        }

        return nums[0];


    }

    int main(){
        vector<int>nums={3,2,3,1,2,4,5,5,6};
        int k=4;
        cout<<findKthLargest(nums,k)<<endl;
        return 0;
    }