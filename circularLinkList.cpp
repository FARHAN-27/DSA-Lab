#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;

    node* next;

    node(int val){
        data = val;
        next = NULL;

    }

};

void insertAtHead(node* &head,int val){

   

    node* n = new node(val);
     if(head==NULL){
        n->next=n;
        head=n;
    }


    node* temp = head;

    while(temp->next!=head){
        temp=temp->next;
    }

    n->next=head;
    temp->next=n;
    head= n;


}

void dsisplay(node* &head){
    node* temp = head;

    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

void insertAtTail(node* &head,int val){

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);


    //if(head==NULL)
    node* temp = head;


    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next = n;

    n->next=head;


}
void DeleteAtHead(node* &head){

node* temp = head;

while (temp->next!=head)
{
    temp = temp->next;
}
   
    temp->next=head->next;
    head=head->next;

     
}


void DeleteNode(node* &head,int position){

    if(position==1){
        DeleteAtHead(head);
        return ;
    }
    node* temp = head;
  int  count=1;

    while(count!=position-1){
        temp=temp->next;
        count++;
    }
    temp->next=temp->next->next;

}
int main(){
    node* head= NULL;
    insertAtHead(head,5);
    insertAtHead(head,7);
    insertAtHead(head,85);
    insertAtTail(head,6);
    dsisplay(head);
    DeleteAtHead(head);
    dsisplay(head);
    DeleteNode(head,3);
    dsisplay(head);


}