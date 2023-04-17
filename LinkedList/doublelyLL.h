#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
    struct Node* prev;
}Node;

Node* createNode(){
    Node* ptr;
    ptr = (Node*)malloc(sizeof(Node));
    if(ptr == NULL){
        printf("Node Not created\n");
    }else{
        printf("Node created\n");
    }
    return ptr;
}

void insertEnd(Node** head,int key){
     Node* newNode = createNode();
     newNode->data = key;
     newNode->link = NULL;
     Node* temp = *head;

     if(*head==NULL){
        *head = newNode;
        newNode->prev = NULL;
    }else if((*head)->link==NULL){
        (*head)->link = newNode;
        newNode->prev = *head;
    }else{
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link = newNode;
        newNode->prev = temp;
    }

}

void insertStart(Node** head,int key){
    Node* newNode = createNode();
    newNode->data = key;
    newNode->prev = NULL;
    newNode->link = NULL;
    if(*head==NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    *head = newNode;
    temp->prev = newNode;
    newNode->link = temp;
}

int deleteEnd(Node** head){
    int d;
    Node* temp = *head;
    if(temp==NULL){
        printf("\n\nList is Empty!!!\n\n");
        return -1;
    }else if(temp->link==NULL){
        d = temp->data; 
        Node* fr = temp;
        free(fr);
        *head = NULL;
        return d;
    }else{
        //Multiple Nodes:
        while(temp->link->link!=NULL){
            temp = temp->link;
        }
        d = temp->link->data;
        Node* fr = temp->link;
        free(fr);
        temp->link = NULL;
        return d;
    }
}

int deleteStart(Node**head){
    int d;
    
   
    if((*head)==NULL){
        printf("\n\nList is Empty!!!\n\n");
        return -1;
    }else if((*head)->link==NULL){
        d = (*head)->data; 
        Node* fr = *head;
        free(fr);
        *head = NULL;
        return d;
    }else{
        //Multiple Nodes:
        Node* temp = (*head)->link;
        d = temp->data;
        Node* fr = temp->prev;
        temp->prev = NULL;
        free(fr);
        *head = temp;
        return d;
    }

}

void printReverse(Node* head){
    if(head->link==NULL){
    printf("%d\t",head->data);
        return;
    }
    printReverse(head->link);
    printf("%d\t",head->data);
}

int size(Node* head){
    Node* temp = head;
    int i = 1;
    while(temp->link!=NULL){
        i++;
        temp = temp->link;
    }
    return i;
}

void sortDLL(Node** head){
    insertEnd(head,99999);
    for(Node* i=(*head);i->link->link!=NULL;i=i->link){
        Node* min = i;
        for(Node* j=(i->link);j->link!=NULL;j=j->link){
            if((min->data)>(j->data)){
                min = j;
            }
        }
        //Swapping
        int data = min->data;
        min->data = i->data;
        i->data = data;
    }
    deleteEnd(head);
    
}

void display(Node* head){
    Node* temp = head;
    printf("\n");
    while(temp->link!=NULL){
        printf("%d\t",temp->data);
        temp = temp->link;
    }
    printf("%d\t",temp->data);
    printf("\n");
}

int sizeofLL(Node** head){
    int s=0;
    Node* temp = *head;
    while(temp->link!=NULL){
        s++;
        temp = temp->link;
    }
    return s+1;
}

void insertAtPos(Node** head,int key,int pos){
    int index = 1;
    Node* temp = *head;
    if(pos==1){
        insertStart(head,key);
    }else if(pos>sizeofLL(head)){
        printf("\nEnter a valid position❌\n");
    }else if(pos>1 && pos<sizeofLL(head)){
        while(index<pos-1){
            index++;
            temp = temp->link;
        }
        Node* newNode = createNode();
        newNode->data=key;
        newNode->link = newNode->prev=NULL;

        newNode->link = temp->link;
        newNode->link->prev = newNode;
        temp->link = newNode;
        newNode->prev = temp;
    }
}

int deleteFromPos(Node** head,int pos){
    Node* temp = *head;
    if(pos==1){
        int key = temp->data;
        deleteStart(head);
        return key;
    }else if(pos>sizeofLL(head)){
        printf("\nInvalid Index/Position\n");
        return -1;
    }else if(pos>1 && pos<sizeofLL(head)){
        int index = 1;
        while(pos-1>index){
            index++;
            temp=temp->link;
        }
        int data = temp->link->data;
        Node* fr = temp->link;
        temp->link->link->prev = temp;
        temp->link = temp->link->link; 
        free(fr);
        return data;
    }
}

void reverse(Node** head){
    Node* temp = *head;
    while(temp->link!=NULL){
        Node* t = temp->link;
        temp->link = temp->prev;
        temp->prev = t;
        temp = t;
    }

    Node* t = temp->link;
    temp->link = temp->prev;
    temp->prev = t;
    *head = temp;
}