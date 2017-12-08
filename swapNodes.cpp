// Problem: Given a linked list and two keys in it, swap nodes for two given keys.
// Nodes should be swapped by changing links.
// Swapping data of nodes may be expensive in many situations when
// data contains many fields.

// Assumptions: All keys are distinct

#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void swap(struct node **head, int x, int y){
    struct node * nodeX=NULL, *nodeY=NULL, *prevX=NULL, *prevY=NULL;
    struct node *trav= *head, *prev=NULL;

    // Case 0:  x=y : Do Nothing
    if(x==y)
        return;
    //Finding X and Y also keeping track of previous node
    while(trav){
        if(trav->data==x){
            prevX= prev;
            nodeX= trav;
        }
        if(trav->data==y){
            prevY= prev;
            nodeY= trav;
        }
        if(nodeX && nodeY)
            break;
        prev= trav;
        trav= trav->next;
    }

    // Case 1: Either of nodes is not found: Do Nothing
    if(!nodeX || !nodeY)
        return;

    // Case 2: x is first node : Update new head
    if(!prevX)
        *head= nodeY;
    else
        // Update previous of x
        prevX->next= nodeY;

    // Case 3: y is first node : Update new head
    if(!prevY)
        *head= nodeX;
    else
        // Update previous of y
        prevY->next= nodeX;

    // Swapping next pointers, Nodes are swapped earlier
    trav= nodeX->next;
    nodeX->next=nodeY->next;
    nodeY->next= trav;
}

// Necessary functions

void display(struct node *head){
    struct node *trav=head;
    while(trav){
        cout<<trav->data<<" ";
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
    swap(&head, 1, 6);
    display(head);
    return 0;
}
