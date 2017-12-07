// Problem: Write a program to delete node from given position in linked list
//Note:  0 based indexing
#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void del(struct node **head, int position){
    struct node *trav = *head;
    struct node *prev= NULL;
    //If list is empty
    if(!trav)
        return;
    //Special case:  if head needs to be deleted
    if(position==0){
        *head= (*head)->next;
        free(trav);
        return;
    }
    while(trav && position--){
        prev= trav;
        trav= trav->next;
    }
    if(trav){
        prev->next= trav->next;
        free(trav);
    }
    else{
        cout<<"Position not found\n";
    }

}

//Necessary functions

void push(struct node **head, int data){
    struct node *newNode= new node;
    newNode->data= data;
    newNode->next= *head;
    *head= newNode;
}

void display(struct node *head){
    struct node *trav= head;
    while(trav){
        cout<<trav->data<<"\t";
        trav= trav->next;
    }
    cout<<"\n";
}

int main(){
    struct node *head= NULL;
    for(int i=5;i;i--)
        push(&head,i);
    display(head);
    del(&head,0);
    display(head);
    return 0;
}
