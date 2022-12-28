template <class T>
class Node{
    public: 
        T data;
        Node *next;
        Node(){
            data = 0;
            next = NULL;
        }
};

template <class T>
class Stack{
public: 
    Node<T>* top;

    Stack(){
        top = NULL;
    }
    bool isEmpty(){
        return top == NULL;
    }
    void push(T n){
        Node<T> *temp = new Node<T>();
        temp->data = n;
        if(isEmpty()){
            temp->next = NULL;
            top = temp;
        }else{
            temp->next = top;
            top = temp;
        }
        
    }
    void pop(){
        if(isEmpty()){
            return;
        }else{
            Node<T>* temp = top;
            top = top->next;
            temp->next = NULL;
            free(temp);
        }
    }

    T getTop(){
        return top->data;
    }
};