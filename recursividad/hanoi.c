#include <stdio.h>

void hanoi(int , int , int, int );

int main(){
  int torre1 = 1;
  int torre2 = 2;
  int torre3 = 3;
  int n = 4;
  
  hanoi(n,torre1,torre2,torre3);


return 0;
}

void hanoi(int n, int ori, int des, int aux){
  if (n == 1){
    printf("Mueva el disco %d desde la torre %d hasta la torre %d \n",n,ori,des);
  }
  else {
    hanoi(n-1,ori,aux,des);
    printf("Mueva el disco %d desde la torre %d hasta la torre %d \n",n,ori,des);
    
    hanoi(n-1,aux,des,ori);
  }
  

}
