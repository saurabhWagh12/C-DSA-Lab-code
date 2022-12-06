#include<stdio.h>
#include<stdlib.h>

typedef struct Matrix{
    int **m;
    int r, c;
}M;

void initialise(M* m,int row,int col){
    m->r = row;
    m->c = col;

    m->m=(int**)malloc(row*sizeof(int));

    for(int i=0;i<row;i++){
        m->m[i] = (int*)malloc(col*sizeof(int)); 
    }
}

void display(M* matrix){
    for(int i=0;i<matrix->r;i++){
        for(int j=0;j<matrix->c;j++){
            printf("%d\t",matrix->m[i][j]);
        }
        printf("\n");
    }
}

void scaningMatrix(M* matrix){
    printf("Enter elements of matrix:\n");
    for(int i=0;i<matrix->r;i++){
        for(int j=0;j<matrix->c;j++){
            scanf("%d",&matrix->m[i][j]);
        }
    }
}

void create(M* matrix){
    printf("Enter number of rows and columns respectively:\n");
    int row,col;
    scanf("%d%d",&row,&col);
    initialise(matrix,row,col);
    // matrix->r = row;
    // matrix->c = col;
    // matrix->m=(int**)malloc(row*sizeof(int));

    // for(int i=0;i<row;i++){
    //     matrix->m[i] = (int*)malloc(col*sizeof(int)); 
    // }
    scaningMatrix(matrix);
}


void matrixAdd(M* m1,M* m2){
    M m3;
    initialise(&m3,m1->r,m1->c);
    // m3.m = (int**)malloc(m1->r*sizeof(int));

    // for(int i=0;i<m1->r;i++){
    //     m3.m[i] = (int*)malloc(m1->c*sizeof(int));
    // }
    // m3.r = m1->r;
    // m3.c = m1->c;

    if(m1->c==m2->c && m1->r==m2->r){
        for(int i=0;i<m1->r;i++){
            for(int j=0;j<m1->c;j++){
                m3.m[i][j] = m1->m[i][j]+m2->m[i][j];
            }

        }
    }else{
        printf("ERROR❌!!!");
    }        
    printf("Matrix after addition:\n");
    display(&m3);
}

void matrixMultiply(M* m1,M* m2){
    M m3;
    int sum=0;
    initialise(&m3,m1->r,m2->c);

    // m3.m = (int**)malloc(m1->r*sizeof(int));
    // for(int i=0;i<m1->r;i++){
    //     m3.m[i] = (int*)malloc(m2->c*sizeof(int));
    // }
    // m3.c = m2->c; m3.r = m1->r;
    
    if(m1->c==m2->r){
        for(int i=0;i<m1->r;i++){
            for(int j=0;j<m1->c;j++){
                sum=0;
                for(int k=0;k<m2->r;k++){
                    sum+=m1->m[i][k]*(m2->m[k][j]);
                }
                m3.m[i][j] = sum;
            }
        }
    }else{
        printf("ERROR❌!!!");
    } 

    printf("Matrix after multiplication:\n");
    display(&m3);
}



