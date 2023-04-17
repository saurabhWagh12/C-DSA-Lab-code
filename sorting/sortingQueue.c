#include"queue.h"
#include"oppositeQueue.h"
#include"QuickSort.h"


int main(){
    Queue q;
    create(&q,5);
    push(&q,1);
    push(&q,3);
    push(&q,5);
    push(&q,7);
    display(q);
    push(&q,9);
    push(&q,11);
    display(q);

    printf("%d",pop(&q));
    display(q);

    QueueOppo q2;
    createOppo(&q2,5);
    pushOppo(&q2,10);
    pushOppo(&q2,8);
    pushOppo(&q2,6);
    pushOppo(&q2,4);
    displayOppo(q2);
    pushOppo(&q2,2);
    pushOppo(&q2,0);
    displayOppo(q2);

    printf("%d",popOppo(&q2));
    displayOppo(q2);
    
    printf("before Sorting (array):");
    int arr[100],k=0;
    while(!isEmpty(q)){
        arr[k] = pop(&q);
        k++;
    }
    while(!isEmptyOppo(q2)){
        arr[k] = popOppo(&q2);
        k++;
    }
    printf("\n");
    for(int i=0;i<k;i++){
        printf("%d\t",arr[i]);
    } 
    
    printf("\n\nAfter Sorting(array):\n");
    quickSort(arr,0,k-1);

    for(int i=0;i<k;i++){
        printf("%d\t",arr[i]);
    } 



  return 0;
}