#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXPROJECTS 12

typedef struct Project {
  int id;
  int cost;
  int gain;
  int numberPredecesors;
  int predecesors[3];
}Project;

void ReadData(int *, int *, Project*);


int main(){
  int N , P;
  Project * arr = (Project*)malloc(sizeof(Project)*MAXPROJECTS);
  ReadData(&N, &P, arr);      
  
  return 0;
}

void ReadData(int * N, int * P, Project* arr){
  FILE * arch;
  arch = fopen("entrada.txt","r");
  if(arch == NULL){
    printf("Error en la apertura del archivo\n");
    exit(1);
  }
  fscanf(arch,"%d %d",N,P);
  
  for(int i = 0 ; i < *N ; i++){
    fscanf(arch,"%d %d %d %d",&arr->id,&arr->cost,&arr->gain,&arr->numberPredecesors);
    
     
  
  
}
