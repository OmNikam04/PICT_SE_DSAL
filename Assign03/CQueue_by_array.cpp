#include<bits/stdc++.h>
using namespace std;

class CQueue{
public:
    int front, rear,n, a[];
    CQueue(int n){
        this->n = n;
        a[n];
        front=rear=-1;
    }

    bool isEmpty(){
        return (front==rear==-1);
    }
    bool isFull(){
        return ((rear+1)%n == front);
    }
    void enqueue(int val){
        //insert at rear
        //check if queue is full
        if(isFull()){
            cout<<"Queue overflow!"<<endl;
            return;
        }
        if(front == -1)front = 0;
        rear = (rear+1)%n;
        a[rear] = val;
    }

    int dequeue(){
        if(front==-1){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        int res = a[front];
        if(front==rear){
            //if front and rear are at same index
            //then it means there is only one element remaining in queue
            //To delete that element make front and rear = -1
            front = rear = -1;
        }
        else{
            //increament front by one
            front =((front+1) %n);
        }
        return res;
    }

    void display(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
        }
        if(rear>=front){
            for(int i = front; i<=rear; i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        else{
            cout<<"Inside display"<<endl;
            for(int i = front; i<n; i++)
                cout<<a[i]<<" ";
            for(int i= 0; i<=rear; i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        
    }
    int getFront(){
        return a[front];
    }

};


int main()
{
    CQueue *q = new CQueue(3);
    q->enqueue(5);
    q->enqueue(15);
    q->enqueue(25);
    q->display();
    cout<<"Dequeueing element: "<<q->dequeue()<<endl;
    q->display();
    cout<<"Enqueu"<<endl;
    q->enqueue(35);
    q->display();
    cout<<"Front: "<<q->getFront()<<endl;
    return 0;
}