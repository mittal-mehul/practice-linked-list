// Problem: Given a liked list find Nth node form the end of the list

#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

node* getNth(node *head, int n){
    if(!head || n==0)
        return NULL;
    node *temp= head;
    node *nthNode= head;
    while(temp && n--)
        temp= temp->next;
    if(n)
        return NULL;
    while(temp){
        temp= temp->next;
        nthNode= nthNode->next;
    }
    return nthNode;
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
    for(int i=0;i<5;i++)
        push(&head,i);
    display(head);
    node *NthNode= getNth(head,6);
    if(NthNode)
        cout<<NthNode->data<<endl;
    return 0;
}
