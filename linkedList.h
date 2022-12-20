#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
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

void addNode(Node** head,int key){
    Node* newNode = createNode();
    newNode->data = key;
    newNode->link = NULL;
    *head = newNode;
}

void addNodeEnd(Node** head,int key){
    Node* newNode = createNode();
    newNode->data = key;
    newNode->link = NULL;
    Node* temp = *head;
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = newNode;
}

void addNodeAtBeg(Node**head,int key){
    Node* newNode = createNode();
    Node* temp = *head;
    newNode->data = key;
    *head = newNode;
    newNode->link = temp;
}

void deleteFirstNode(Node** head){
    Node* temp = *head;
    *head = (*head)->link;
    free(temp);
}

int deleteLastNode(Node** head){
    Node* temp = *head;
    while((temp->link)->link!=NULL){
        temp = temp->link;
    }
    int key = temp->link->data;
    free(temp->link);
    temp->link = NULL;

  return key;
}

int sum(Node* head){

    Node* temp = head;
    int sum=0;
    while(temp->link!=NULL){
        sum += temp->data;
        temp = temp->link;
    }
    sum+=temp->data;
    return sum;
}

int listLength(Node* head){
    Node* temp = head;
    int count=0;
    while(temp->link!=NULL){
        temp = temp->link;
        count++;
    }
    return count+1;
}

void reverse(Node** head){

    Node* prevNode;Node * currentNode;Node* nextNode;
    prevNode = NULL;
    currentNode = nextNode = *(head);
    while(nextNode!=NULL){
        nextNode = nextNode->link;
        currentNode->link = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    *(head) = prevNode;
}   


void displayList(Node* ptr){
    Node* temp = ptr; 
    printf("\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->link;
    }
    printf("\n");
}