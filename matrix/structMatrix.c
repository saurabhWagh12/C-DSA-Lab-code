#include"structMatrixHeader.h"

int main(){
  M m1,m2;
  create(&m1);
  create(&m2);
//Addition of two matrices:  
  matrixAdd(&m1,&m2);

//Multiplication of two matrices:
  matrixMultiply(&m1,&m2);

  return 0;
}

