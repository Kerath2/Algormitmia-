#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXNUMBER 20

typedef struct Schedule{
  int id;
  int horario;
  int credits;
  int sesionT;
  int sesionTStart;
  int sesionTEnd;
  int sesionP;
  int sesionPStart;
  int sesionPEnd;
  int evaluation;
}Schedule;

void readData(int * L,int *N, Schedule **arr);
void fill_chromosome(int n,int size ,int chromosome[]);
int validate(int *chromosome, int N, int L, Schedule **arr);
void imprimeResultado(int *chromosome, int N,Schedule **arr);

  int main(){

  Schedule ** arr;
  arr = (Schedule**)malloc(sizeof(Schedule*)*MAXNUMBER);
  int L, N;
  readData(&L,&N,arr);
  
  int limit = pow(2,N);
  int chromosome[N];
  int isValid;

  for(int i = 0 ; i< limit ;i++){
    fill_chromosome(i, N ,chromosome);
    isValid = validate(chromosome,N,L,arr);
    if(isValid == 1){
      imprimeResultado(chromosome,N,arr);
      break;
    }
  }



return 0;

}

void readData(int * L,int *N, Schedule **arr){
  FILE * arch = fopen("entrada.txt","r");
  if(arch == NULL){
    printf("Error en la apertura del archivo\n");
    exit(1); 
  }

  fscanf(arch,"%d %d",L,N);
  
  for(int i = 0 ; i < *N; i++){
    arr[i] = (Schedule*)malloc(sizeof(Schedule));
  }
  

  for(int i = 0 ; i < (*N); i++){
    fscanf(arch,"%d %d",&arr[i]->id,&arr[i]->horario);
    fscanf(arch,"%d %d",&arr[i]->credits,&arr[i]->sesionT);
    fscanf(arch,"%d %d",&arr[i]->sesionTStart,&arr[i]->sesionTEnd);
    fscanf(arch,"%d %d",&arr[i]->sesionP,&arr[i]->sesionPStart);
    fscanf(arch,"%d %d",&arr[i]->sesionPEnd,&arr[i]->evaluation);
  }
  /*
  for(int i = 0 ; i < (*N); i++){
    printf("%d %d ",arr[i]->id,arr[i]->horario);
    printf("%d %d ",arr[i]->credits,arr[i]->sesionT);
    printf("%d %d ",arr[i]->sesionTStart,arr[i]->sesionTEnd);
    printf("%d %d ",arr[i]->sesionP,arr[i]->sesionPStart);
    printf("%d %d\n",arr[i]->sesionPEnd,arr[i]->evaluation);
  }
  */
  fclose(arch);
}


void fill_chromosome(int n,int size ,int chromosome[]){
    int i = size - 1,j;
    while (n != 0){
        chromosome[i] = n%2;
        n = n/2;
        i--;
    }
    for (j = 0; j<= i; j++)
        chromosome[j]= 0;


}

int validate(int *chromosome, int N, int L, Schedule **arr){
  int evaluacionSinCruce ,idCursoNoRepetido, horarioTSinCruce , horarioPSincruce;
  for(int i = 0 ; i<N ; i++){
    if(chromosome[i] == 1){
      //variables auxiliares
      int teoriaI = arr[i]->sesionT*10000+arr[i]->sesionTStart*100+arr[i]->sesionTEnd;
      int practicaI = arr[i]->sesionP*1000+arr[i]->sesionPStart*100+arr[i]->sesionPEnd;
      for(int j = i+1 ; j < N ; j++){ // Comprobar que no se elija el curso dos veces
        if(chromosome[j] == 1){
          // variables auxiliares 
          int teoriaJ = arr[j]->sesionT*10000+arr[j]->sesionTStart*100+arr[j]->sesionTEnd;
          int practicaJ = arr[j]->sesionP*1000+arr[j]->sesionPStart*100+arr[j]->sesionPEnd;
          if(arr[i]->id != arr[j]->id)
            idCursoNoRepetido = 1;
          else
            idCursoNoRepetido = -1;
          if(teoriaI != teoriaJ)
            horarioTSinCruce = 1;
          else
            horarioTSinCruce = -1;
          if(practicaI != practicaJ)
            horarioPSincruce =1;
          else
            horarioPSincruce = -1;
          if(arr[i]->evaluation != arr[j]->evaluation)
            evaluacionSinCruce = 1;
          else
            evaluacionSinCruce = -1;
         } 
      }//          
    }
  }

  if(evaluacionSinCruce == 1 && idCursoNoRepetido == 1 && horarioPSincruce == 1 && horarioTSinCruce ==1){
    return 1;
  }else{
    return 0;
  }
  
}


void imprimeResultado(int *chromosome, int N,Schedule **arr){
  printf("El horario que cumple las condiciones 12 <= c <= 20\n");
  for(int i = 0  ; i< N; i++){
    if(chromosome[i] == 1){
      printf("%06d-%04d\n",arr[i]->id,arr[i]->horario);
    }
  }

}
