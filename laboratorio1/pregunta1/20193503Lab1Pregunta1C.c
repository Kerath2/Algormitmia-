//Pregunta 1 a,b
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define MAXNUMBER 15
typedef struct Chanel{
    int id;
    char name[30];
    double investment;
    double roas;
    int remembrance;
}Chanel;


void readData(int *, int *, Chanel **);
void fill_chromosome(int n,int size ,int chromosome[]);
int validate( double *,double* income,int *chromosome, int N,int P,Chanel **arr);
void copyChromosome(int *winnerChromosome,int *chromosome, int n);
void showResults(int *winnerChromosome,int N, Chanel **arr);


int main(){
  int P, N;
//Arreglo de estrcuturas chanel
Chanel ** arr;
  
  arr = (Chanel**)malloc(sizeof(Chanel*)*MAXNUMBER);
  //Lectura de datos
  readData(&P, &N, arr);
  
  int chromosome[N], winnerChromosome[N];
  int limit = pow(2,N);
  
  int isValid;
  double income, higherIncome = 0;
  double spent;
    //validacion
  for(int i = 0 ; i < limit ; i++){
    fill_chromosome(i, N, chromosome);    
    isValid = validate(&spent,&income,chromosome,N,P,arr);
   
    if(isValid == 1 && higherIncome<= income){
      higherIncome = income;
      copyChromosome(winnerChromosome, chromosome,  N);
    }

  }
    //impresion de resultado
  printf("El máximo ingreso por ventas es de %.2lf dolares con una inversion total en publicidad de %.2lf\n",higherIncome,spent);
  showResults(winnerChromosome,N, arr);

  free(arr);
  return 0;
}




void readData(int *P, int *N, Chanel **arr){
  FILE * arch = fopen("entrada.txt","r");
  if(arch == NULL){
    printf("Error en la apertura del archivo\n");
    exit(1);
  }
  fscanf(arch,"%d %d",P,N);

  for(int i = 0 ; i< *N ; i++){
    arr[i] =(Chanel*) malloc(sizeof(Chanel));
  }
  for(int i = 0 ; i < *N; i++){
    fscanf(arch,"%d %s %lf %lf %d",&arr[i]->id,arr[i]->name,&arr[i]->investment,&arr[i]->roas,&arr[i]->remembrance);

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


int validate( double *spent,double * income,int *chromosome, int N,int P,Chanel **arr){
  (*income) = 0;
  int totalSpent = 0;
  for(int i = 0 ; i< N ; i++){
    if(chromosome[i] == 1){
      (*income) += arr[i]->roas*arr[i]->investment;
      totalSpent += arr[i]->investment; 
    }
  }

  if(totalSpent <= P){
    *spent = totalSpent;
    return 1;
  }else{
    return -1;
  }
}

void copyChromosome(int *winnerChromosome,int *chromosome, int n){
    for (int i = 0 ; i< n ; i++){
        winnerChromosome[i] = chromosome[i];
    }
}



void showResults(int *winnerChromosome,int N,Chanel** arr){
  printf("Los canales de publicidad que se deben de elegir para obtener el máximo ingreso total son:\n");
  double ingreso;
  for(int i = 0 ; i< N; i++){
    if(winnerChromosome[i] == 1){
      ingreso = arr[i]->roas*arr[i]->investment;
      printf("-canal %d - %s, ingreso = %.2lf dolares con una inversion publicitaria de %.2lf dolares\n",arr[i]->id,arr[i]->name,ingreso,arr[i]->investment);
    }
  }
}

