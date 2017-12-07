// Problem: Write a program to delete first occurence of a given value from list
// Assumptions: The key is not present at first i.e. head node

#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node *next;
};


void del(struct node *head, int key){
    struct node *temp= head;
    struct node *prev= NULL;
    while(temp){
        if(temp->data==key){
            prev->next= temp->next;
            free(temp);
            cout<<"Delted\n";
            return;
        }
        prev= temp;
        temp= temp->next;
    }
    cout<<"Key not found\n";
}

// Necessary functions

void display(struct node *head){
    struct node *temp= head;
    while(temp){
        cout<<temp->data;
        cout<<"\t";
        temp= temp->next;
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
    for(int i=5;i;i--)
        push(&head,i);
    display(head);
    del(head,4);
    display(head);
    return 0;
}
