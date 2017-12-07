// Problem: Write a program to find length of a linked list
// Note: Must use recursive method

#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node *next;
};

int getlen(struct node *head){
    if(!head)
        return 0;
    return(1+ getlen(head->next));
}

//Necessary functions

void display(struct node *head){
    struct node *trav= head;
    while(trav){
        cout<<trav->data<<"\t";
        trav= trav->next;
    }
    cout<<"\n";
}

void push(struct node **head, int data){
    struct node *newNode= new node;
    newNode->data= data;
    newNode->next= *head;
    *head= newNode;
}

int main(){
    struct node *head= NULL;
    for(int i=6;i;i--)
        push(&head,i);
    display(head);
    cout<<getlen(head);
    return 0;
}
