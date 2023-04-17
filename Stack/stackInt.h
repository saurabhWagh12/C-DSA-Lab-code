#include<stdio.h>
#include<stdlib.h>

typedef struct StackInt{
   int size; 
   int *a;
   int top;
}StackInt;

int initialiseInt(){
    return -1;
}

void displayInt(StackInt* s){
    printf("\n");

    for(int i=0;i<=s->top;i++){
        printf("%d\t",s->a[i]);
    }
    printf("\n");
}

void createInt(StackInt *st){
    st->top = initialiseInt();
    printf("Enter size of stackInt : ");
    scanf("%d",&st->size);
    st->a = (int*)malloc((st->size)*sizeof(int));
}

int isEmptyInt(StackInt *st){
    if(st->top==-1){
        return 1;
    }
    return 0;
}

int isFullInt(StackInt *st){
    if((st->top)==(st->size)){
        return 1;
    }else{
        return 0;
    }

}

int popInt(StackInt *st){
    int last;
    if(isEmptyInt(st)){
        // printf("StackInt is empty⛔");
        return -1;
    }else{
        last = st->a[st->top];
        (st->top)--;
        // st->a = realloc(st->a,n);
         return last;
    }
}

void pushInt(StackInt *st,int n){
    if(isFullInt(st)){
        // printf("StackInt is full❌");
        return;
    }else{
        (st->top)++;
        st->a[st->top] = n;
    }
}
