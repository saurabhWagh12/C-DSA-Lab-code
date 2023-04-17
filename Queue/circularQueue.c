// #include"circularQueue.h"
#include"circularQueueInt.h"
#include<stdio.h>

void checkPalindrome(){
    printf("Enter String: ");
    char ch[20],str[20];
    scanf("%s",ch);
    for(int i=0;ch[i]!='\0';i++){
        if(ch[i]>64 && ch[i]<91){
            str[i] = ch[i]+32;
        }else{
            str[i] = ch[i];
        }
    }

    Queue q;
    createQueue(&q,20);

    for(int i=0;ch[i]!='\0';i++){
        enQueEnd(&q,str[i]);
    }
    int count=0;
    for(int i=0;ch[i]!='\0';i++){
        count++;
    }

    if(q.front!=q.rear){
    for(int i=0;i<count/2;i++){
        char a = deQueStart(&q);
        char b = deQueEnd(&q);
        if(a!=b){
            printf("\n\nNot a palindrome!!!\n\n");
            return;
        }
    }
    printf("\n\nString is a palindrome\n\n");
    }else{
            printf("\n\nNot a palindrome!!!\n\n");
    }
}

void historyOfBrowser(){
    Queue q;
    int limit=6,choice;
    createQueue(&q,6);
    int i=0;
    printf("\n*****TAB MANAGEMENT*****\n Enter 1 to add New Tab:\n Enter 2 to remove Last Tab Added:\n Enter 3 to display tabs Number:\n Enter 4 to exit:\n(LIMIT:6)\n\n");
    while(1){
        printf("Enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            i++;
            if(!isFull(&q)){
                enQueEnd(&q,i);
            }else if(isFull(&q)){
                deQueStart(&q);
                enQueEnd(&q,i);
            }
            break;

        case 2:
            deQueEnd(&q);
            // i--;
        break;

        case 3:
            display(q);
        break;      

        case 4:
        exit(0);
        break;
        
        default:
            break;
        }
    }
}

void dequeueImplementation(){
    Queue q;
    createQueue(&q,5);

    enQueEnd(&q,1);
    enQueEnd(&q,2);
    enQueEnd(&q,3);
    display(q);
    enQueStart(&q,4);
    enQueStart(&q,5);
    display(q);
    deQueEnd(&q);
    deQueEnd(&q);
    display(q);
    deQueStart(&q);
    display(q);

}

int main(){
    // dequeueImplementation();
    // Checking palindrome
    // while(1)
    // checkPalindrome();
    historyOfBrowser();
    
    return 0;
}
