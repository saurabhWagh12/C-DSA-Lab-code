#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
   int size; 
   char *a;
   int top;
}Stack;

int initialise(){
    return -1;
}

void display(Stack* s){
    printf("\n");

    for(int i=0;i<=s->top;i++){
        printf("%d\t",s->a[i]);
    }
    printf("\n");
}

void create(Stack *st){
    st->top = initialise();
    printf("Enter size of stack : ");
    scanf("%d",&st->size);
    st->a = (char*)malloc((st->size)*sizeof(char));
}

int isEmpty(Stack *st){
    if(st->top==-1){
        return 1;
    }
    return 0;
}

int isFull(Stack *st){
    if((st->top)==(st->size)){
        return 1;
    }else{
        return 0;
    }

}

char pop(Stack *st){
    char last;
    if(isEmpty(st)){
        // printf("Stack is empty⛔");
        return -1;
    }else{
        last = st->a[st->top];
        (st->top)--;
        // st->a = realloc(st->a,n);
         return last;
    }
}

void push(Stack *st,char n){
    if(isFull(st)){
        // printf("Stack is full❌");
        return;
    }else{
        (st->top)++;
        st->a[st->top] = n;
    }
}
