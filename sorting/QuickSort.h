#include<stdio.h>

int partition(int arr[],int si,int ei){
    //Last element taken as pivot element:
    int pivot = arr[ei];
    int i = si-1;
    for(int j=si;j<ei;j++){
        if(arr[j]<=pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;
    int temp = arr[ei];
    arr[ei] = arr[i];
    arr[i] = temp;

    return i;
}

void quickSort(int arr[],int si,int ei){
    if(si<ei){
        int pivotIndex = partition(arr,si,ei);

        quickSort(arr,si,pivotIndex-1);
        quickSort(arr,pivotIndex+1,ei);

    }else{
        return ;
    }

}
