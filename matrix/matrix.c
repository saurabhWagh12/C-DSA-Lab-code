#include"matrixop.h"
int main(){
    int a[r][c],b[r][c],n;

    printf("Enter 1 to add matrix\nEnter 2 to Multiply matrix\nEnter 3 to find transpose of matrix\n:");
    scanf("%d",&n);
    switch (n)
    {
    case 1://Addition
        matrixInput(a);
        matrixInput(b);
        matrixAdd(a,b);
        break;

    case 2://Multiplication
        matrixInput(a);
        matrixInput(b);
        matrixMultiply(a,b);
        break;

    case 3://Transpose
        matrixInput(a);
        matrixTranspose(a);
        break;

    default:printf("Please make a correct choice!!!");
        break;
    }

    return 0;
}