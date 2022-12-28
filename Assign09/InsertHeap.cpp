#include<bits/stdc++.h>
using namespace std;

void insert(int *arr, int size, int val){
    size = size +1;
    arr[size] = val;
    // make tree satisfies heap property
    int i = size;
    while(i>=1){
        int parent = i/2;
        if(arr[i]>arr[parent]){
            swap(arr[i], arr[parent]);
            i=parent;
        }else{
            return;
        }
    }
}

int main()
{
    int heap[] = {50,30,40,10,5,20,30};
    int size = sizeof(heap)/sizeof(heap[0]);
    insert(heap,size,60);
    for(int i =0 ;i<size; i++){
        cout<<heap[i]<<" ";
    }cout<<endl;
    return 0;
}