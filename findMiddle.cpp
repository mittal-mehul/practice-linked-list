// Problem: Find middle of linked list
// Hare and Tortoise Algorithm

#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

// find middle of linked list
node* findMiddle(node *head){
    node *fast, *slow;
    if(!head)
        return head;
    fast= head->next;
    slow= head;
    // Fast moves two nodes at once leaving
    while(fast && fast->next){
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
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
    cout<<findMiddle(head)->data<<endl;
    return 0;
}
