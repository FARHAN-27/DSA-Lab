#include<bits/stdc++.h>
using namespace std;
#define n 5

//queue using link list

class node{
    public:
   
    int data;
    node* next;

    node(int val){
        data=val;
        next = NULL;

    }
};


class LLQUEUES{
   
    node* front;
    node* back;
    public:

    LLQUEUES(){
        front=NULL;
        back=NULL;
    }

    void push(int x){
        node* nod = new node(x);
        if(front==NULL){
            back = nod;
            front = nod;
            return;
        }
        back->next=nod;
        back=nod;

    }

    void pop(){
        if(front==NULL){
            cout<<"queue is empty"<<endl;
            return;
        }
        node* todelete = front;
        front = front->next;

        delete todelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"queue is empty"<<endl;
            return -1 ;
        }

        return front->data;

    }
    bool empty(){
        if(front==NULL){
           
            return  true ;
        }
        return false ;
        
    }
};


//queue using array

class Queue{
    
    private:

    int arr[n];
    int front;
    int back;

    public:

    Queue(){
       
        front=-1;
        back=-1;
    }

    void push(int x){
        if(back==n-1){
            cout<<"queue is overflow"<<endl;
            return ;
        }
        back++;
        arr[back]= x;

        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"queue is empty"<<endl;
            return;
        }

        front++;
    }

    int peek(){
         if(front==-1 || front>back){
            cout<<"queue is empty"<<endl;
            return -1;
        }

        return arr[front];

    }

    bool empty(){
         if(front==-1 || front>back){
           
            return true ;
        }
        return false;

    }

};

class CirQueue{

    private:
    int arr[n];
    int front;
    int back;

    public:

    CirQueue(){
        front=-1;
        back=-1;
    }

    void push(int x){
        if(front==-1 && back == -1){
            front=0;
            back= 0;
            arr[back]=x;

        }
        else if(front==(back+1)){
            cout<<"quweue is full"<<endl;
        }

        else {
            back = (back+1)%n;
            arr[back]=x;

        }

        
    }

    void pop(){
        if(front==-1 && back == -1){
            cout<<"empty quwuw"<<endl;
        }
        else if(front==back){ //if 1 elemnt in the queue 
            front=-1;
            back=-1;
        }

        else {
            front = (front+1)%n;
        }
    }
    void display(){
        if(front==-1 && back == -1){
            cout<<"empty quwuw"<<endl;
        }

        else{
            for (int i = front; i != back; i=(i+1)%n)
            {
                cout<<arr[i]<<" ";
            }
            
        }
    }

    int peek(){

        return arr[front];

    }

};
class Deque {
    private:
   
    int arr[n];
    int front;
    int rear;
    int size;

   public:
    Deque(int size) {
    front = -1;
    rear = 0;
    this->size = size;
  }

//   void insertfront(int key);
//   void insertrear(int key);
//   void deletefront();
//   void deleterear();
//   bool isFull();
//   bool isEmpty();
//   int getFront();
//   int getRear();


bool isFull() {
        return ((front == 0 && rear == size - 1) ||
        front == rear + 1);
    }

bool isEmpty() {
     return (front == -1);
    }

void insertfront(int key) {
    if (isFull()) {
    cout << "Overflow\n" << endl;
    return;
   }

    if (front == -1) {
        front = 0;
        rear = 0;
    }

    else if (front == 0)
        front = size - 1;

  else
    front = front - 1;

    arr[front] = key;
}

void insertrear(int key) {
  if (isFull()) {
    cout << " Overflow\n " << endl;
    return;
  }

  if (front == -1) {
    front = 0;
    rear = 0;
  }

  else if (rear == size - 1)
    rear = 0;

  else
    rear = rear + 1;

  arr[rear] = key;
}

void deletefront() {
  if (isEmpty()) {
    cout << "Queue Underflow\n"<< endl;
    return;
  }

  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (front == size - 1)
    front = 0;

  else
    front = front + 1;
}

void deleterear() {
  if (isEmpty()) {
    cout << " Underflow\n"<< endl;
    return;
  }

  if (front == rear) {
    front = -1;
    rear = -1;
  } 
  
  else if (rear == 0)
    rear = size - 1;
  
  else
    rear = rear - 1;
}

int getFront() {
  if (isEmpty()) {
    cout << " Underflow\n"<< endl;
    return -1;
  }
  return arr[front];
}

int getRear() {
  if (isEmpty() || rear < 0) {
    cout << " Underflow\n"<< endl;
    return -1;
  }
  return arr[rear];
}
};

int main(){

     Deque q(5);

    q.insertfront(12);
    q.insertfront(45);
    q.insertfront(43);
    q.insertrear(123);
    q.insertrear(14);

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;

    


    return 0;
}