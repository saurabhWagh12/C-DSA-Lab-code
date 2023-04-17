#include"Stack.h"
int k=0;

void infixToPostfix(char A[],char B[],Stack* s){
    for(int i=0;A[i]!='\0';i++){
        if(A[i]=='+'||A[i]=='-'||A[i]=='*'||A[i]=='/'){
            checkPriority();
        }else{
            B[k] = A[i];
            k++;
        }
    }

}

int main(){
    Stack s;
    char A[20],B[20];
    printf("Enter Expression : ");
    scanf("%s",A);
    create(&s);

    infixToPostfix(A,B,&s);
    printf("\n");
        printf("%s",B);

    // create(&s);
    // push(&s,10);
    // push(&s,11);
    // push(&s,12);
    // push(&s,13);
    // push(&s,15);
    // push(&s,16);
    // display(&s);
    // printf("\t%d",s.top);




  return 0;
}