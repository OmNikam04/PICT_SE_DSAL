#include<bits/stdc++.h>
using namespace std;

void printArray(int a[], int n){
    for(int i= 0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}

void heapify(int a[], int size, int i){
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l < size && a[l] > a[largest])
        largest = l;
    if(r<size && a[r] > a[largest])
        largest = r;
    
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, size, largest);
    }
}

void heapSort(int a[], int size){
    for(int i = size/2; i>=0; i--){
        //build max heap
        heapify(a, size, i);
    }
    cout<<"Max heap: "<<endl;
    printArray(a,size);

    for (int i = size-1; i >= 1; i--)
    {
        //max heap is created so 
        //swap 1st element with last 
        swap(a[i], a[1]);
        heapify(a, i, 1);
    }
}



int main()
{   
    int n =6;
    int a[n] = { 12, 11, 13, 5, 6, 7 };
    heapSort(a,n);
    printArray(a,n);
    return 0;
}