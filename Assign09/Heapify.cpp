#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int size, int i){
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l < size && a[l] > a[largest])
        largest = l;
    if(r < size && a[r] > a[largest])
        largest = r;
    
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, size, largest);
    }
}

void buildHeap(int a[], int size){
    for(int i = size/2; i>=0; i--){
        heapify(a, size, i);
    }
}

int main()
{
    int a[] = {1,3,5,4,6,13,10,9,8,15,17};
    int size = sizeof(a)/sizeof(a[0]);
    buildHeap(a,size);
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    return 0;
}