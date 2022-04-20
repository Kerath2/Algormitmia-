#include <stdio.h>

void imprimirArreglo(int *, int );
int mergeSort(int *,int ,int);

int main(){
  
  int arr[9] ={3,5,2,1,7,19,21,31,12};
  int size = 9;

  
  imprimirArreglo(arr, 9);
  


return 0;
}

void imprimirArreglo(int * arr, int size ){
  for (int i = 0 ; i < size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");

}

int mergeSort(int * arr,int low ,int high){
  
  int mid;
  if(low < high){
    mid = (low + high) / 2;
    
    //divide y conquistaras
    mergeSort(arr, low, mid);
    mergeSort(arr,mid+1,high);
   
    //juntarlo
    
  }
  
  return 0;
}

int merge(int arr[], int l, int m , int h)
