#include<stdio.h>
void swap(int* a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
int partition(int a[],int l,int h){
    int p = l;
    int i = l+1,j=h;
    int pivot=a[p];

    while(i<=j){
        while(i<=h && a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&a[i],&a[j]);
        }
    }

     if(i>j){
        swap(&a[p],&a[j]);
    }
    return j;
}

void quickSort(int a[],int l,int h){
  if(l<h){ 
        int pivotIndex = partition(a,l,h);
        quickSort(a,l,pivotIndex-1);
        quickSort(a,pivotIndex+1,h);
    }
}

void merge(int a[],int l,int mid,int h){
   int i = l,j=mid+1,k=l;
   int b[50];
   
   while(i<=mid && j<=h){
    if(a[i]>a[j]){
        b[k] = a[j];
        k++;j++;
    }
    if(a[j]>a[i]){
        b[k] = a[i];
        i++;
        k++;
    }
   }
   while(i<=mid){
    b[k]=a[i];
    i++;
    k++;
   }
   while(j<=h){
    b[k] = a[j];
    j++;
    k++;
   }

   for(int m=l;m<=h;m++){
    a[m] = b[m];
   }
}

void mergeSort(int a[],int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}

void printing(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

int main(){
    int arr[] = {14,6,34,11,100,43,30};
  
    quickSort(arr,0,6);
    printf("Sorted using Quick Sort:\n");
    printing(arr,7);

    int a[] = {14,60,3,11,10,143,20};

    mergeSort(a,0,6);
    printf("\n\nSorted using Merge Sort:\n\n");
    printing(a,7);




    return 0;
}