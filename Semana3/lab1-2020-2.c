#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Worker{
  double failure;
  int salary;
}Worker;

int readDataFromFile(int totalWorkers, Worker * workers);
void minimizeLosses(int minWorkers, int maxWorkers, int readWorkers, int budget, Worker* workers);

void displayCombinations(int index,int budgetSpent,double minAverageFailure,int readWorkers,int** workerCombinations);
int main(){
  int totalWorkers = 12;
  Worker * workers = (Worker*)malloc(sizeof(Worker)*totalWorkers);

  int readWorkers = readDataFromFile(totalWorkers,workers);
  printf("Se han encontardo %d obreros\n",readWorkers);

  int minWorkers, maxWorkers;
  printf("Ingresar cantidad min y max de obreros: ");
  scanf("%d %d",&minWorkers,&maxWorkers);

  int budget;
  printf("Ingresar presupuesto: ");
  scanf("%d",&budget);

  minimizeLosses(minWorkers,maxWorkers,readWorkers,budget,workers);

  free(workers);

  return 0;
}

int readDataFromFile(int totalWorkers, Worker * workers){
  int readWorkers = totalWorkers;
  FILE * arch = fopen("entrada.txt","r");

  for(int i = 0 ; i< totalWorkers ; i++){
    int assigned = fscanf(arch,"%lf %d",&workers[i].failure,&workers[i].salary); 
    if(assigned < 2){
      readWorkers = i;
      break;
    }
  }

  fclose(arch);
  return readWorkers;
  
}

void minimizeLosses(int minWorkers, int maxWorkers, int readWorkers, int budget, Worker* workers){
  int budgetSpent;
  int index;

  double minAverageFailure = INFINITY;
  
  int totalCombinations = pow(2,readWorkers);
  int** workerCombinations = (int**)malloc(sizeof(int*)*totalCombinations);

  for(int i = 0 ; i< totalCombinations ; i++){
    workerCombinations[i] = (int*)malloc(sizeof(int)*readWorkers);
    for(int j  = 0 ; j< readWorkers; j++){
      workerCombinations[i][j] = 0;

    }

    int temp = i;
    int j = 0;
    while(temp>0){
      workerCombinations[i][j] = temp%2;
      temp /= 2;
      j++;
    }

    int currentBudget = 0;
    int currentWorkers = 0;
    double currentAverageFailure = 0;

    for(int j = 0 ; j < readWorkers; j++){
      currentBudget += workerCombinations[i][j]*workers[j].salary;
      currentWorkers += workerCombinations[i][j];
      currentAverageFailure += workerCombinations[i][j]*workers[j].failure;

    }
    currentAverageFailure /= currentWorkers;
    
    if((currentWorkers>=minWorkers) && (currentWorkers<=maxWorkers
        ) && (currentBudget<=budget) && (currentAverageFailure<minAverageFailure)){
      minAverageFailure = currentAverageFailure;
      budgetSpent = currentBudget;
      index = i;
    }

  }



  displayCombinations(index,budgetSpent,minAverageFailure,readWorkers,workerCombinations);

  free(workerCombinations);
}


void displayCombinations(int index,int budgetSpent,double minAverageFailure,int readWorkers,int** workerCombinations){
  printf("Obreros: ");
  for(int i = 0 ; i< readWorkers; i++){
    printf("%d ",(i+1));
  }

  printf("\nSeleccion: ");
  for(int i = 0; i< readWorkers; i++){
    printf("%d ",workerCombinations[index][i]);
  }

  printf("\ncosto Total: %d , fallas promedio %.2f\n",budgetSpent,minAverageFailure);
}
