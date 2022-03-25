/* Solución elaborada por Gerardo Miguel  Tacay Terrazos
Datos de entrada:
4
23
7 17 14 19
9 12 11 8
8 6 10 12
18 7 15 11
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 4

typedef struct block{
    int weight;
    char name[3];
}Block;


void fillBlocks(Block** arr, int * maxWeight, int * N ){
    FILE * arch;
    arch = fopen("datos.txt","r");

    if(arch == NULL){
        printf("Error en la apertura del archio con los datos\n");
        exit(1);
    }

    fscanf(arch,"%d %d", N, maxWeight);

    for(int i = 0 ; i < *N * 4; i++){
        arr[i] = (Block*)malloc(sizeof(Block));
        fscanf(arch,"%d",&arr[i]->weight);
    }

    for(int i = 0 ; i < *N * 4; i++){
        if( i < *N*2){
           arr[i]->name[0] = 'I';
        }else{
            arr[i]->name[0] = 'D';
        }
        if(i<*N || (i >= *N*2 && i <*N*3)){
            arr[i]->name[1] = 'A';
        }else{
            arr[i]->name[1] = 'B';
        }

        arr[i]->name[2] = (i%*N + 1) +48; //48 es el codiog ascii de 0 
        
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

int validate(int chromosome[], Block ** arr, int totalBlocks, int requiredWeight){
    int weight = 0;

    
    for(int i = 0; i<totalBlocks; i++){
       if (chromosome[i] == 1){
           weight  = weight + arr[i]->weight;
       }
    }
    
    if(weight == requiredWeight){
       
        return 1;
    }


    return -1;
    
}

void printResults(int chromosome[],int totalBlocks,Block ** arr){
   for(int i = 0 ; i < totalBlocks ; i++){
       if(chromosome[i] == 1){
           printf("%dk ",arr[i]->weight);
       }
       
   }

    printf(" Ubicaciones: ");
   for(int i = 0; i < totalBlocks ; i++){
       if(chromosome[i] == 1){
           for(int j = 0 ; j<3; j++){
               printf("%c",arr[i]->name[j]);
           }
           printf(" ");
       }
   }
   printf("\n");
}



int main(){
    Block ** arr;
    arr = (Block**)malloc(sizeof(Block*)*MAX_N*4);
   
   int requiredWeight, N;

   fillBlocks(arr,&requiredWeight,&N);

    int totalBlocks = N * 4;
    
    int chromosome[totalBlocks], limit = pow(2,totalBlocks);
    int isValid,leastoneResult=0,resultsCount = 0;

    for(int i = 0 ; i < limit ; i++){
        fill_chromosome(i,totalBlocks,chromosome);
        isValid = validate(chromosome, arr, totalBlocks,requiredWeight);

        if(isValid == 1){
            resultsCount ++;
            leastoneResult = 1;
            printf("Resultado %d :",resultsCount);
            printResults(chromosome,totalBlocks,arr);
        }
    }



    return 0;
}
  
