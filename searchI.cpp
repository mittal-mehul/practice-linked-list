// Problem: Write a program to search a key in a linked list
// Note: Must use iterative method

#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node *next;
};

bool lookfor(struct node *head, int key){
    struct node *trav= head;
    while(trav){
        if(trav->data==key)
            return true;
        trav= trav->next;
    }
    return false;
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
    if(lookfor(head,8))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";
    return 0;
}
