#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;


     node(int val){
        data = val;
        next=NULL;
    }

};
void insertAtTail(node* &head,int val){
   // node* &head;
    //node* &head;
    node* newnode = new node(val);

    if(head == NULL){
        head = newnode;
        return;
    }

    node* temp = head;


    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = newnode;



}

void insartAtFirst(node* &head,int val){
    node* newnode = new node(val);

    newnode->next = head;

    head = newnode;
}


void insertNodeAtMiddle(node* &head,int data, int position)
{
   node* newNode= new node(data);

   node* temp = head;
        for(int i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }       
            /* Link address part of new node */
            newNode->next = temp->next; 
           /* Link address part of n-1 node */
            temp->next = newNode;
}


void deleteathed(node* &head){
    node* todel = head;

    head = head->next;

    free(todel);
}
void removeLastNode(node* &head)
{
    if (head == NULL)
        return;
  
    if (head->next == NULL) {
        delete head;
        return;
    }
  
    // Find the second last node
    node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
  
    // Delete last node
    delete (second_last->next);
  
    // Change next of second last
    second_last->next = NULL;
  
    //return head;
} 


void DeleteNumberInAnyPoaition(node* &head,int value){

    if(head==NULL) return;

    if(head->next==NULL){
        deleteathed(head);
    }


    node* temp = head;
    while (temp->next->data!=value)
    {
        temp= temp->next;
    }
    node* todel = temp->next;

    temp->next=temp->next->next;

    delete todel;
    
}
void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}


int main(){

    node* head = NULL;
    insertAtTail(head,34);
    insertAtTail(head,3);
    insertAtTail(head,4);
     insertAtTail(head,34);
    insartAtFirst(head,3);
    deleteathed(head);
    display(head);
    insertNodeAtMiddle(head,69, 3);
    display(head);
    // removeLastNode(head);
    // display(head);
    DeleteNumberInAnyPoaition(head,69);
    display(head);

    




    return 0;
}

