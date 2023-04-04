#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int val;
    node* prev;
    node* next;

    node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }

};
void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next = head ;
    if(head!=NULL){
    head ->prev = n ;
    }
    head= n;
}
void insertAtTail(node* &head,int val){

    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
 
    node* temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }

    temp->next = n ;
    n->prev = temp;
}

void insertAtMiddle(node* &head, int val, int position){
    if(head == NULL || position == 1){
        insertAtHead(head, val);
        return;
    }

    int curr_pos = 1;
    node* curr = head;
    while(curr_pos != position-1 && curr->next != NULL){
        curr = curr->next;
        curr_pos++;
    }

    if(curr_pos == position-1){
        node* n = new node(val);
        n->next = curr->next;
        n->prev = curr;
        //if(curr->next != NULL){
        curr->next->prev = n;
        curr->next = n;
        // curr->next = n;
        // n->prev = curr;
        // n->next = curr->next;
        // curr->next->prev = n;

    }
    else{
        insertAtTail(head, val);
    }
}
void deleteAtHead(node* &head){
    node* todel = head;
    head = head ->next;
    head->prev = NULL;
    delete todel;

}

void DeleteAtPosition(node* &head,int pos){

    if(pos==1){
        deleteAtHead(head);
    }
    node* temp =  head;

    int cnt = 1;

    while(temp!=NULL && cnt!=pos){
        temp = temp->next;
        cnt++;
    }
     
    // temp->next=temp->next->next;
    // temp->next->prev=temp;//if we count pos -1 the its right
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }

}





void display(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp= temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int main(){
    node* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head,69);
    display(head);
    insertAtMiddle(head,169,3);
    display(head);

    DeleteAtPosition(head,2);

    display(head);
    deleteAtHead(head);
    display(head);





}