#include"Stack.h"
void parenthesisMatching(){
    Stack s;
    create(&s);
    char str[20] = {'(','(','a','+','b',')','*','(','a','+','c',')','\0'};
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            push(&s,'(');
        }else if(str[i]==')'){
             if(!isEmpty(&s)){
                pop(&s);
             }else{
                printf("Brackets not matched check!!!");
               return;
             }
        }
    }
    if(!isEmpty(&s)==0){
        printf("All brackets are matched"); return;
    }
    else{
        printf("Brackets not matched check!!!"); return;
    }
}
int main(){
    parenthesisMatching();
    return 0;
}