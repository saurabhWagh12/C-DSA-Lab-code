#include"Stack.h"
#include"stackInt.h"

int isOparand(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/' ){
        return 0;
    }else if(c=='('|| c==')'){
        return 2;
    }
    else{
        return 1;
    }
}

int presedence(char s){
    if(s=='+'||s=='-'){
        return 2;
    }else if(s=='*'||s=='/'){
        return 3;
    }else if(s=='(' ||s==')'){
        return 1;
    }
}

int number(char n){
    
    switch (n)
    {
    case 'A':
        return 1;
        break;
    case 'B':
        return 2;
        break;
    case 'C':
        return 3;
        break;
    case 'D':
        return 4;
        break;
    case 'E':
        return 5;
        break;    

    default:
    return 0;
        break;
    }

}

int evaluationOfPostfix(char B[]){
    StackInt st;
    printf("\n\n");
    createInt(&st);

    int first,second,ans;
    for(int i=0;B[i]!='\0';i++){
        if(isOparand(B[i])==1){
            int ch = number(B[i]);
            pushInt(&st,ch);
        }else if(isOparand(B[i])==0){
            switch(B[i])
            {
            case '+':
                first = popInt(&st);
                second = popInt(&st);
                ans = first+second;
                pushInt(&st,ans);
                break;

            case '-':
                first = popInt(&st);
                second = popInt(&st);
                ans = second-first;
                pushInt(&st,ans);
                break;

            case '*':
                first = popInt(&st);
                second = popInt(&st);
                ans = first*second;
                pushInt(&st,ans);
                break;

            case '/':
                first = popInt(&st);
                second = popInt(&st);
                ans = second/first;
                pushInt(&st,ans);
                break;           
            
            default:
                break;
            }
        }
    }

    return popInt(&st);
}

void convert(char A[]){
    Stack s;
    create(&s);
    char B[21];
    int i=0,j=0;
    while(A[i]!='\0'){
        if(isOparand(A[i])==1){
            B[j++] = A[i++];
        }

        else if(isOparand(A[i])==2){
            
            if(A[i]=='('){
                push(&s,A[i++]);
            }
            else if(A[i]=')'){
                while(s.a[s.top]!='('){
                        char t = pop(&s);
                        B[j++] = t;
                }
                pop(&s);
                i++;         
            }
            else if(A[i]='('){
                push(&s,A[i]);
                i++; 
            }

        }else if(isOparand(A[i]==0)){
            if(isEmpty(&s) && isOparand(A[i])==0){
                push(&s,A[i++]);
            }
            else{
                    if(presedence(A[i])>presedence(s.a[s.top])){
                        push(&s,A[i++]);
                    }
                    else{
                        char t = pop(&s);
                        B[j++] = t;
                    }
            }

        }
    }

        while(s.top!=-1){
            B[j++] = pop(&s);
        }
        B[j] = '\0';

    for(int k=0;k<j;k++){
        printf("%c",B[k]);
    }

    printf("\nFinal ans is : %d\n",evaluationOfPostfix(B));
}

int main(){
    
    char A[20];
    printf("Enter infix Expression : ");
    scanf("%s",A);
    convert(A);


    return 0;
}