#include <stdio.h>
#include <stdlib.h>

#define MAXROWS 10

void readData(int *,int *,int **);
int recursiveExplorer(int ,int ,int , int ,int ,int **,int );
  int main(){
  int **terrain = (int**)malloc(sizeof(int*)*MAXROWS);
  int nRows, nCols;

  readData(&nRows,&nCols,terrain);
 
  int startX;  
  int startY;

  printf("Ingrese las cordenadas x y: ");
  scanf("%d %d",&startX,&startY);

  int direction;
  printf("Ingrese la direccion 0-arriba 1-derecha 2-abajo 3-izquierda: ");
  scanf("%d",&direction);

  int unitsFound = recursiveExplorer(startX,startY,direction,nRows,nCols,terrain,1);

  printf("Se encontraron %d unidades!\n",unitsFound);
  return 0;
}
void readData(int *nRows,int *nCols,int ** terrain){
  FILE * arch  = fopen("entrada.txt","r");
  if(arch == NULL){
    printf("Erorr en la apertura del archivo\n");
    exit(1);
  }
  fscanf(arch,"%d %d",nRows,nCols);
  for (int i = 0 ; i < *nRows ; i++){
    terrain[i] = (int*)malloc(sizeof(int*)*(*nCols));
    for (int j = 0 ; j < *nCols; j++){
      fscanf(arch,"%d",&terrain[i][j]); 
    }
  }
}

int recursiveExplorer(int x,int y,int direction,
    int nRows,int nCols,int **terrain,int firstCall){
  
  //Condicion de parada
  if((x < 0) || (x>=nRows) || (y < 0) || (y>=nCols)){
    return 0;
  }

  int unitsFound = 0;
  int nextX, nextY;

  switch (direction) {
    case 0: //arriba
    case 2: //abajo
      if(firstCall == 1){
        //Leer columna
        for(int i = 0 ; i < nRows; i++){
          unitsFound += (terrain[i][y] == 1) ? 1: 0;
        }
      }
        //Leer fila sin volver a repetir 
        for(int i = 0; i< nCols;i++){
          if(i == y) continue;
          unitsFound += (terrain[x][i] == 1) ? 1 : 0;
        }
      
    break;
    case 1: //derecha
    case 3: //izquierda
      if(firstCall == 1){
        //Leer fila
        for(int i = 0 ; i < nCols; i++){
          unitsFound += (terrain[x][i] == 1) ? 1: 0;
        }
      }
        //Leer columna sin volver a repetir 
        for(int i = 0; i< nRows;i++){
          if(i == x) continue;
          unitsFound += (terrain[i][y] == 1) ? 1 : 0;
        }
    break;
  }
  

  switch (direction) {
    case 0://arriba
      nextX = x-1;
      nextY = y;
    break;
    case 1://derecha
      nextX = x;
      nextY = y+1;
    break;
    case 2://abajo
      nextX = x+1;
      nextY = y;
    break;
    case 3://izquierda
      nextX = x;
      nextY = y-1;
    break;
  }
  return unitsFound + recursiveExplorer(nextX,nextY,
      direction,nRows,nCols,terrain,0);
}




