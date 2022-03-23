/* Solución elaborada por Gerardo Tacay
Datos de entrada Precios:
10 10 10 5
15 10 10 10
10 20 10 5
10 10 5 10 
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

typedef struct pricesblock{
    int price;
    char name[3];
}BlockPrices;


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

void fillBlocksPrices(BlockPrices ** arrPrices){
    FILE * arch = fopen("precios.txt","r");
    if(arch==NULL){
        printf("Error en la apertura del archivo de precios\n");        
    }
    for (int i = 0; i< MAX_N *4; i++){
        arrPrices[i] = (BlockPrices*)malloc(sizeof(BlockPrices));
        fscanf(arch,"%d",&arrPrices[i]->price);
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

int calulatePrice(int *chromosome, BlockPrices ** arrPrices, int totalBlocks){
    int price = 0;
    for(int i = 0;i < totalBlocks ; i++){
        if(chromosome[i] == 1){
            price += arrPrices[i]->price;
        }
    }

    return price;
    
}

void copyChromosome(int *winnerChromosome,int *chromosome, int n){
    for (int i = 0 ; i< n ; i++){
        winnerChromosome[i] = chromosome[i];
    }
}

void printfResults(int maxPrice, Block ** arr,int totalBlocks, int winnerChromosome[]){
    printf("Ganancia: %d Resultado :",maxPrice);
    for(int i = 0 ; i < totalBlocks ; i++){
        if(winnerChromosome[i]==1){
            printf("%dk ",arr[i]->weight);
        }
    }
    printf("Ubicaciones :");
    for(int i = 0 ; i < totalBlocks ; i++){
        if(winnerChromosome[i]==1){
            for(int j = 0 ; j < 3 ; j++){
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
    
    BlockPrices ** arrPrices;
    arrPrices = (BlockPrices**)malloc(sizeof(BlockPrices*)*MAX_N*4);

   int requiredWeight, N;

    fillBlocks(arr,&requiredWeight,&N);
    fillBlocksPrices(arrPrices);

    int totalBlocks = N * 4;
    
    int chromosome[totalBlocks], limit = pow(2,totalBlocks);
    int isValid,leastoneResult=0,resultsCount = 0;
    int price = 0, maxPrice = -1,winnerChromosome[totalBlocks]; 

    for(int i = 0; i<limit; i++){
        fill_chromosome(i,totalBlocks,chromosome);
        isValid = validate(chromosome, arr, totalBlocks,requiredWeight);

        if(isValid == 1){
            resultsCount ++;
            leastoneResult = 1;
            price = calulatePrice(chromosome,arrPrices,totalBlocks);
            if(price > maxPrice){
                copyChromosome(winnerChromosome,chromosome,totalBlocks);
                maxPrice = price;
            }
        }
    }

    printfResults(maxPrice,arr,totalBlocks,winnerChromosome);



    return 0;
}
  
