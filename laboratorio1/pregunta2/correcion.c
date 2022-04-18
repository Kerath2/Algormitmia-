#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define  MAX_COURSES 20


typedef struct Course{
  int id;
  int credits;
  int schedule;
  int teorySesion;
  int sesionHourStart;
  int sesionHourEnd;
  int practiceSesion;
  int practiceHourStart;
  int practiceHourEnd;
  int evaluation;
} Course;

void ReadData(int*, int*, Course**);
void fill_chromosome(int ,int  ,int *);
int validate(int *, int , int , int * , Course **);
int main(){
  Course ** arr = malloc(sizeof(Course*)*MAX_COURSES);
  int N, L;
  ReadData(&N,&L,arr);
  
  // Prueba de lectura
  /*
  for (int i = 0; i< N ; i++){
    printf("%d %d ", arr[i]->id ,arr[i]->schedule );
    printf("%d %d ", arr[i]->credits ,arr[i]->teorySesion );
    printf("%d %d ", arr[i]->sesionHourStart ,arr[i]->sesionHourEnd );
    printf("%d %d ", arr[i]->practiceSesion ,arr[i]->practiceHourStart );
    printf("%d %d \n", arr[i]->practiceHourEnd ,arr[i]->evaluation );
  }
  */
  
  int chromosome[N];
  int limit = pow(2,N);
  int valid, totalCredits;
  for (int i = 0 ; i< limit ; i++){
    fill_chromosome(i,N,chromosome);
    valid = validate(chromosome,N,L,&totalCredits,arr);
  }

  return 0;
}

void ReadData(int* N, int* L, Course** arr){
  FILE * arch = fopen("entrada.txt","r");
  if(arch == NULL){
    printf("Error en la apertura del archivo\n");
    exit(1);
  }
  
  fscanf(arch,"%d %d",L,N);

  for (int i = 0 ;i< *N ; i++){
    arr[i] = malloc(sizeof(Course));
    fscanf(arch,"%d %d",&arr[i]->id,&arr[i]->schedule);
    fscanf(arch,"%d %d",&arr[i]->credits,&arr[i]->teorySesion);
    fscanf(arch,"%d %d",&arr[i]->sesionHourStart,&arr[i]->sesionHourEnd);
    fscanf(arch,"%d %d",&arr[i]->practiceSesion,&arr[i]->practiceHourStart);
    fscanf(arch,"%d %d",&arr[i]->practiceHourEnd,&arr[i]->evaluation);
  }

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
int validate(int *chromosome, int N, int L, int * totalCredits, Course ** arr){
  int RepeatId = 0, creditsCounter;
  for(int i = 0; i < N; i++){
    if(chromosome[i] == 1){
      for(int j = i+1 ; j < N ; j++ ){
        if(chromosome[j]==1){
          // Ver si hay repetidos (idHorario)
          if(arr[i]->id == arr[j]->id)
            RepeatId = 1;

        }
      }
      // Contador para que no se pase el numero limite de creditos
      creditsCounter++;
    }
  }

}
