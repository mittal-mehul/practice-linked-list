// Problem:  Delete entire linked list

#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

// Delete List

void deleteList(node **head){
    if(!head)
        return;
    node *temp= *head;
    while(temp){
        temp= temp->next;
        free(*head);
        *head= temp;
    }
}


// Necessary Functions

void push(node **head, int data){
    node *newNode= new node;
    newNode->data= data;
    newNode->next= *head;
    *head= newNode;
}

void display(node *head){
    node *temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

int main(){
    node *head= NULL;
    for(int i=0;i<6;i++)
        push(&head,i);
    display(head);
    deleteList(&head);
    cout<<"List Deleted"<<endl;
    display(head);
    return 0;
}
