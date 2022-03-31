#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CANTMAX 16

typedef struct cliente{
  int id;
  int quantity;
  double porcentage;
}Cliente;

void  fillArr(Cliente ** arr, int *T, int * P , int *N ){
  FILE * arch;
  arch = fopen("datos.txt","r");
  if(arch == NULL){
  printf("Error en la apertura del archivo");
  exit(1);
  }
  
  fscanf(arch,"%d %d %d",T, P ,N);

  for (int i = 0; i < *N ; i++){
    arr[i] = (Cliente*)malloc(sizeof(Cliente));
    fscanf(arch,"%d %d %lf",&arr[i]->id,&arr[i]->quantity,&arr[i]->porcentage);
  }

  
}

int validate(int * chromosome, Cliente ** arr,int N,int T,int P){
  int totalActions=0;

  for(int i = 0 ; i< N ; i++){
    if(chromosome[i] == 1) {
        totalActions += arr[i]->quantity;
    } 
  }

  if (totalActions <= T)
    return 1;

  return -1;

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

double calculateComission(Cliente ** arr ,int * chromosome, int N , int P){
  double total = 0;
  for (int i = 0 ; i < N ; i++){
    if( chromosome[i] == 1){
        total += (arr[i]->quantity* arr[i]->porcentage);
    }
  }
  return total;
}

void copyChromosome(int *winnerChromosome,int * chromosome,int N){
    for (int i = 0  ; i < N; i++){
      winnerChromosome[i] = chromosome[i];
    }
} 
void  printResults(int * winnerChromosome,Cliente **arr,int N, int P){
    printf("Clientes que se deben elegir para obtener la mejor ganancia son: \n");
    double ganancia;
    for(int i = 0 ; i < N ; i++){
      if(winnerChromosome[i] == 1){
        ganancia = arr[i]->porcentage*arr[i]->quantity*P;
        printf("-El cliente %d otorga una ganancia de %.2lf por comprar %d acciones\n",arr[i]->id,ganancia,arr[i]->quantity);         
      }
    }

}

void printOneResult(int * chromosome,int N,Cliente ** arr, int P){
  double ganancia;
  for(int i = 0 ; i < N ; i++) {
    if(chromosome[i] == 1){
        ganancia = arr[i]->porcentage*arr[i]->quantity*P;
        printf("-El cliente %d otorga una ganancia de %.2lf por comprar %d acciones\n",arr[i]->id,ganancia,arr[i]->quantity);         
    }
  }
}


int main(){
   Cliente ** arr;
   arr = (Cliente**)malloc(sizeof(Cliente*)*CANTMAX);
   int T,P,N; 

   fillArr(arr,&T,&P,&N);
   int chromosome[N], limit = pow(2,N), isValid, winnerChromosome[N];
   double maxComission = -1, comission;

   for(int i = 0 ; i < limit ; i++){
      fill_chromosome(i,N,chromosome);      
      isValid = validate(chromosome,arr,N,T,P);
      if(isValid == 1){
        comission = calculateComission(arr,chromosome,N,P);
        if(comission > maxComission){
          maxComission = comission;
          copyChromosome(winnerChromosome,chromosome,N); 
        }
      }
   }
    
   int counter = 0;

   for(int i = 0 ; i< limit ; i++){
      fill_chromosome(i,N,chromosome);
      isValid = validate(chromosome,arr,N,T,P);
      if(isValid == 1){
        comission = calculateComission(arr,chromosome,N,P);
        if(fabs(comission-maxComission)<1){
          counter++;
          printf("Resultado %d\n",counter);
          printOneResult(chromosome,N,arr,P);
        }
      }
   } 

  printf("%d",counter);
  return 1;
}
