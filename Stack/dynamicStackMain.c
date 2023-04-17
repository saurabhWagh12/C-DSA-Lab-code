#include"dynamicStack.h"
int main(){
    Stack s;
    createStack(&s,3);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    printf("top pointer: %d &  current(alloted) size of stack: %d",s.top,s.size);
    display(s);
    push(&s,4);
    push(&s,5);
    printf("top pointer: %d &  current(alloted) size of stack: %d",s.top,s.size);
    display(s);
    push(&s,5);
    printf("top pointer: %d &  current(alloted) size of stack: %d",s.top,s.size);
    display(s);
    push(&s,10);
    printf("top pointer: %d &  current(alloted) size of stack: %d",s.top,s.size);
    display(s);
    pop(&s);
    pop(&s);
    display(s);
    printf("top pointer: %d &  current(alloted) size of stack: %d",s.top,s.size);
    return 0;
}