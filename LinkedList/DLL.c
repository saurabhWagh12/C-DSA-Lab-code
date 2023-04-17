#include"doublelyLL.h"

int main(){
    Node* head= NULL;
    int choice,key,pos;
    printf("\n******MENU******\n");
    printf("1)Insert at start:\n2)Insert at End:\n3)Delete from start:\n4)Delete from end:\n5)Display list:\n6)Print Reverse:\n7)Sort List:\n8)insert at specified position:\n9)delete from specified position:\n10)reverse list:\n11)Exit\n");
    printf("\n\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1://Insert at start:
                    printf("Enter key you want to insert:");
                    scanf("%d",&key);
                    insertStart(&head,key);
            break;
            case 2://Insert at end:
                    printf("Enter key you want to insert:");
                    scanf("%d",&key);
                    insertEnd(&head,key);
            break;
            case 3://Delete from start:
                    deleteStart(&head);
            break;
            case 4://Delete from end:
                    deleteEnd(&head);
            break;
            case 5://Display list:
                    display(head);
            break;
            case 6://Print Reverse:
                    printReverse(head);
            break;
            case 7://Sorting list
                    sortDLL(&head);
            break;
            case 11://exit
                    exit(0);
            break;
            case 10:
                reverse(&head);
            break;
            case 8:
                printf("Enter key you want to insert and its position respectively:");
                scanf("%d%d",&key,&pos);
                insertAtPos(&head,key,pos);
            break;
            case 9:
                printf("Enter position of node you want to delete:");
                scanf("%d",&pos);
                deleteFromPos(&head,pos);
            break;
            default:printf("\nPlease Enter valid choice\n");
            break;
        }
    }
    

    return 0;
}