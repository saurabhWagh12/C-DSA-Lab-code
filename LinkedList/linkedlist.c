#include"linkedList.h"
int main(){
    Node* head = NULL;
    int choice,key,pos;    
     printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n 1.Insert in begining\n 2.Insert at last\n 3.Insert at sepcific location\n 4.Delete from Beginning\n 5.Delete from last\n 6.Delete node at specified location\n 7.Search for an element\n 8.Display\n 9.reverse linked list\n 10.Exit\n");   
    while(1)   
    {  
    
        printf("\nEnter your choice?\n");         
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  // 1.Insert in begining
                printf("\nEnter key you want to insert: ");
                scanf("%d",&key);
                if(head == NULL){
                    addNode(&head,key);
                }else{
                    addNodeAtBeg(&head,key);
                }
            break;

            case 2: //2.Insert at last
                printf("\nEnter key you want to insert: ");
                scanf("%d",&key);
                if(head == NULL){
                    addNode(&head,key);
                }else{
                    addNodeEnd(&head,key);
                }
            break; 

            case 3: //3.Insert at any specific location
                printf("Enter Position and key respectively : ");
                scanf("%d %d",&pos,&key);
                if(pos==1){
                    addNodeAtBeg(&head,key);
                }else{ 
                     insertAtPos(&head,pos,key);
                }
            break;  

            case 4:  
            if(head==NULL){
                printf("\nList is Empty!!!\n");
            }else{
                deleteFirstNode(&head);
            }
                 
            break;  

            case 5:  
            if(head==NULL){
                printf("\nList is Empty!!!\n");
            }else{
                deleteLastNode(&head);
            }
             
            break; 

            case 6:  //Delete from specific Position
            printf("Enter position of element you want to delete:");
            scanf("%d",&pos); 
               deleteFromPos(&head,pos);   
            break; 

            case 7://Searching
            printf("\nEnter key you want to search: ");
            scanf("%d",&key);
            if(head==NULL){
                printf("\nList is Empty\n");
            }else{
                if(search(&head,key)){
                    continue;
                }else{
                    printf("\nKey Not Found!!!\n");
                }
            }
            break; 

            case 8:  //Display
                displayList(head);
            break; 

            case 9://Reverse
                reverse(&head);
            break;

            case 10:  
            exit(0);  
            break; 

            default:  
            printf("Please enter valid choice..");  
        }  
    }  
    return 0;
}