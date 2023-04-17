#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int* arr;
    int maxSize;
    int front,rear;
}Queue;

int initialise(){
    return -1;
}

void createQueue(Queue* q,int n){
    q->maxSize = n;
    q->arr = (int*)malloc(sizeof(int)*q->maxSize);
    q->front = q->rear = initialise(); 
}

int isEmpty(Queue* q){
    if(q->front==-1 && q->rear==-1){
        return 1;
    }
    return 0;
}

int isFull(Queue* q){
    if(((q->rear+1)%(q->maxSize))==q->front){
        return 1;
    }
    return 0;
}

void enQueEnd(Queue* q,int key){
    if(isEmpty(q)){
        (q->front)++;
        (q->rear)++;
        q->arr[q->rear] = key;
    }else{
        if(!isFull(q)){
            q->rear = ((q->rear+1)%(q->maxSize));
            q->arr[q->rear] = key;
        }else{
            printf("\n\nQueue if Full Cannot insert!!!\n\n");
        }
    }
}

int deQueStart(Queue* q){
    int data;
    if(isEmpty(q)){
        printf("\n\nQueue is Empty!!!\n\n");
        return -1;
    }else if(q->front==q->rear){
        data = q->arr[q->front];
        q->front=q->rear=initialise();
    }else{
        data = q->arr[q->front];
        q->front = (q->front+1)%(q->maxSize);
    }
    return data;
}

void enQueStart(Queue* q,int key){
    if(isEmpty(q)){
        q->rear = q->front = 1;
        q->arr[q->front] = key;
    }else{
        if(isFull(q)){
            printf("\n\nQueue is full can't Insert\n\n");
        }else{
            q->front = (q->front+q->maxSize-1)%(q->maxSize);
            q->arr[q->front] = key;
        }
    }
    
}

int deQueEnd(Queue* q){
    int data;
    if(isEmpty(q)){
        printf("\n\nQueue is Empty!!!\n\n");
        return -1;
    }else if(q->front==q->rear){
        data = q->arr[q->rear];
        q->front = q->rear = initialise();
    }else{
        data = q->arr[q->rear];
        q->rear = (q->rear+q->maxSize-1)%(q->maxSize); 
    }
    return data;
}

void display(Queue q){
    printf("\n");
    int i = q.front;
    while(i!=q.rear){
        printf("%d\t",q.arr[i]);
        i = (i+1)%q.maxSize;
    }
    printf("%d\t",q.arr[q.rear]);
    printf("\n");
}
