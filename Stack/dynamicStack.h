#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
    int* ptr;
    int top;
    int size;
}Stack;

int initialise(){
    return -1;
}

void createStack(Stack* s,int n){
    s->size = n;
    s->ptr = (int*)malloc(sizeof(int)*(s->size));
    s->top = initialise();
}

int isEmpty(Stack s){
    if(s.top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack *s){
    if((s->size-1)==s->top){
        return 1;
    }
    return 0;
}

void push(Stack* s,int key){
    if(!isFull(s)){
        (s->top)++;
        s->ptr[s->top] = key;
    }else if(isFull(s)){
        s->ptr = (int *)realloc(s->ptr,(int)((s->size)*1.5));
        (s->top)++;
        s->size = (int)((s->size)*1.5);
        s->ptr[s->top] = key;
    }
}

int pop(Stack* s){
    int key = s->ptr[s->top];
    (s->top)--;
    return key;
}

void display(Stack s){
    printf("\n");
    for(int i=0;i<=s.top;i++){
        printf("%d\t",s.ptr[i]);
    }
    printf("\n");
}


