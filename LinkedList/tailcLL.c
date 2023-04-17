#include"DLLwithTail.h"
int main(){
    Node* tail = NULL;
    // insertEnd(&tail,12);
    // display(tail);
    // insertEnd(&tail,11);
    // display(tail);
    // insertEnd(&tail,10);
    // display(tail);
    // insertEnd(&tail,9);
    // display(tail);
    insertStart(&tail,12);
    display(tail);
    insertStart(&tail,9);
    display(tail);
    insertStart(&tail,8);
    display(tail);
    insertStart(&tail,7);
    display(tail);
    insertStart(&tail,6);
    display(tail);

    insertAtPos(&tail,1234,3);
    display(tail);
    insertAtPos(&tail,1234,2);
    display(tail);
   
    deleteFromPos(&tail,4);
    display(tail);
    deleteFromPos(&tail,5);
    display(tail);

    // deleteEnd(&tail);
    // display(tail);
    // deleteEnd(&tail);
    // display(tail);

    return 0;
}