#include<stdio.h>
#include<stdlib.h>
typedef struct QueueOppo{
    int *ptr;
    int head;
    int tail;
    int size;
}QueueOppo;

void createOppo(QueueOppo* q,int s){
    q->size = s;
    q->tail = q->head = q->size;
    q->ptr = (int*)malloc((q->size)*sizeof(int));
}

int isEmptyOppo(QueueOppo q){
    if(q.tail==q.size && q.head==q.size){
        return 1;
    }
    return 0;
}

int isFullOppo(QueueOppo q){
    if(q.head==0){
        return 1;
    }
    return 0;
}

void pushOppo(QueueOppo *q,int n){
    if(isEmptyOppo(*q)){
        q->head = q->tail = q->size-1;
        q->ptr[q->head] = n;
    }else if(isFullOppo(*q)){
        printf("Cannot Insert as Queue is full");
    }else{
        if(!isFullOppo(*q)){
            (q->head)--;
            q->ptr[q->head] = n;
        }else{
            printf("\nERROR in pushing element!!!\n\n");
        }
    }
}

int popOppo(QueueOppo* q){
    int key;
    if(q->head==q->tail){
        key = q->ptr[q->tail];
        q->head = q->tail = q->size;
        return key;  
    }
    if(isEmptyOppo(*q)){
        printf("\nQueue is empty\n");
        return -1;
    }else{
        key = q->ptr[q->tail];
        (q->tail)--;
    }
    return key;
}

int lookOppo(QueueOppo q){
    return q.tail;
}

void displayOppo(QueueOppo q){
    printf("\n");
    for(int i=q.head;i<=q.tail;i++){
        printf("%d\t",q.ptr[i]);
    }
    printf("\n");
}