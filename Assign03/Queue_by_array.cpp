#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
    int front, rear, capacity, a[];
    Queue(int n){
        front = rear = -1;
        capacity = n;
        a[capacity];
    }  
    
    void enqueue(int n){
        //check if full
        if(rear == capacity -1){
            cout<<"queue overflow!"<<endl;
            return;
        }
        else{
            a[++rear] = n;
        }
    }

    int dequeue(){
        int result;
        // check if empty
        if(rear == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            // delete front
            result = a[0];
            for(int i=0; i<capacity ; i++){
                a[i] = a[i+1];
            }
        }
        rear--;
        return result;
    }

    void display(){
        for(int i =0; i<rear; i++){
            cout<<a[i]<<" ";
        }cout<<endl;
    }
    int getFront(){
        if(front==rear==-1){
            cout<<"Queue empty"<<endl;
            return -1;
        }
        return a[0];
    }
};
int main()
{
    Queue *q = new Queue(3);
    q->enqueue(5);
    q->enqueue(3);
    q->enqueue(6);
    cout<<"Dequeued elemenet: "<<q->dequeue()<<endl;
    q->display();
    cout<<"Front: "<<q->getFront()<<endl;

    return 0;
}