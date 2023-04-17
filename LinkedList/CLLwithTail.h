#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}Node;

Node* createNode(){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp==NULL){
        printf("\nNode not created!!!\n");
    }else{
        printf("\nNode created!!!\n");
    }
    return temp;
}

int size(Node** tail){
    Node* temp = *tail;
    int idx = 1;
    temp = temp->link;
    while(temp->link!=*tail){
        temp= temp->link;
        idx++;
    }

    return idx+1;
}

void insertEnd(Node** tail,int key){
    Node* newNode = createNode();
    Node* temp= *tail;
    newNode->data = key;

    if(*tail==NULL){
        *tail = newNode;
        (*tail)->link = *tail;
    }else if((*tail)->link==(*tail)){
        (*tail)->link = newNode;
        newNode->link = *tail;
        *tail = newNode;
    }else{
        newNode->link= temp->link;
        temp->link = newNode;
        *tail = newNode;
    }

}

void insertStart(Node** tail,int key){
    Node* newNode = createNode();
    newNode->data = key;
    if(*tail==NULL){
        newNode->link = newNode;
        *tail = newNode;
    }else if((*tail)->link==*tail){
        newNode->link = *tail;
        (*tail)->link = newNode;
    }else{
        Node* temp = *tail;
        temp = temp->link;
        newNode->link = temp;
        (*tail)->link = newNode;   
    }
}

int deleteStart(Node** tail){
    int data;
    Node* temp = *tail;
    if(temp==NULL){
        return -1;
    }
    else if(temp->link==temp){
        data = temp->data;
        *tail=NULL;
        free(temp);
        return data;
    }else{
        temp = temp->link;
        data = temp->data; //taking out data
        (*tail)->link = temp->link;
        free(temp);
        return data;
    }
}

int deleteEnd(Node** tail){
    Node* temp = *tail;
    if(temp==NULL){
        return -1;
    }else if(temp->link == temp){
        int data = temp->data;
        *tail=NULL;
        free(temp);
        return data;
    }else{
        temp = temp->link;
        int data = (*tail)->data;
        while(temp->link!=*tail){
            temp = temp->link;
        }
        temp->link = (*tail)->link;
        Node* fr = *tail;
        *tail = temp;
        free(fr);
        return data;
    }
    
}

void insertAtPos(Node** tail,int key,int pos){
    Node* temp = *tail;
    Node* newNode = createNode();
    newNode->data = key;
    if(pos>1 && pos<size(tail)){
    temp = temp->link;
    int index = 0;
    while(pos-2>index){
        temp = temp->link;
        index++;
    }
    newNode->link = temp->link;
    temp->link = newNode; 
    }else{
        printf("\nInvalid position!!!\n");
    } 
}

void deleteFromPos(Node** tail,int pos){
    Node* temp = *tail;
    if(pos>1 && pos<size(tail)){
    temp = temp->link;
    int index = 0;
    while(pos-2>index){
        temp = temp->link;
        index++;
    }
    Node* fr = temp->link;
    temp->link = temp->link->link;
    }else{
        printf("\nInvalid position!!!\n");
    } 
}

void display(Node* tail){
    Node* temp = tail;
    temp = temp->link;
    printf("\n");
    while(temp->link!=tail->link){
        printf("%d\t",temp->data);
        temp = temp->link;
    }
    printf("%d",temp->data);
    printf("\n");

}
