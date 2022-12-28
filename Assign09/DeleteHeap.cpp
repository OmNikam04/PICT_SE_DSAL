#include<bits/stdc++.h>
using namespace std;


void deleteElement(int *a, int size){
    a[0] = a[size];
    size = size-1;
    int i =1;
    while(i<size){
        int left_child = a[i*2];
        int right_child = a[i*2 + 1];
        int largest_child = left_child>right_child ? i*2 : i*2+1;

        if(a[i] < a[largest_child]){
            swap(a[i], a[largest_child]);
            i = largest_child;
        }else{
            return;
        }
    }
}

int main()
{
    int heap[] = {50,30,40,10,5,20,30};
    int size = sizeof(heap)/sizeof(heap[0]);
    deleteElement(heap,size);
    for(int i =1 ;i<=size; i++){
        cout<<heap[i]<<" ";
    }cout<<endl;
    return 0;
}