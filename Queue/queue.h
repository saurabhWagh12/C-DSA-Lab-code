#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int *ptr;
    int head;
    int tail;
    int size;
}Queue;

int initialise(){
    return -1;
}

void create(Queue* q,int s){
    q->size = s;
    q->tail = q->head = initialise();
    q->ptr = (int*)malloc((q->size)*sizeof(int));
}

int isEmpty(Queue q){
    if(q.head==-1 && q.tail==-1){
        return 1;
    }
    return 0;
}

int isFull(Queue q){
    if(q.tail==(q.size-1)){
        return 1;
    }
    return 0;
}

void push(Queue *q,int n){
    if(isEmpty(*q)){
        q->head = q->tail = 0;
        q->ptr[q->tail] = n;
    }else if(isFull(*q)){
        printf("Cannot Insert as Queue is full");
    }else{
        if(!isFull(*q)){
            (q->tail)++;
            q->ptr[q->tail] = n;
        }else{
            printf("\nERROR in pushing element!!!\n\n");
        }
    }
}

int pop(Queue* q){
    int key;
    if(q->head==q->tail){
        key = q->ptr[q->head];
        q->head = q->tail = -1;
        return key;  
    }
    if(isEmpty(*q)){
        printf("\nQueue is empty\n");
        return -1;
    }else{
        key = q->ptr[q->head];
        (q->head)++;
    }
    return key;
}

int look(Queue q){
    return q.head;
}


void display(Queue q){
    printf("\n");
    for(int i=q.head;i<=q.tail;i++){
        printf("%d\t",q.ptr[i]);
    }
    printf("\n");
}