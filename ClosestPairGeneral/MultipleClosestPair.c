//Devuelve todos los pares de puntos que tengan la mínima distancia.
//En la entrada no se deben repetir los puntos.
//Falta implementar una funcion que elimine la lista y libere la memoria.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1000000
#define EPSILON 0.000000001

typedef struct point{
  int x;
  int y;
  struct point *next;
}Point;

Point *pointList(Point  *List){
  List = NULL;
  return List;
} 

Point *agregarPunto(Point * List, int x , int y){
  Point  * nuevoPunto, *aux;
  nuevoPunto = (Point*)malloc(sizeof(Point));
  nuevoPunto->x = x;
  nuevoPunto->y = y;
  nuevoPunto->next = NULL;

  if(List == NULL){
    List = nuevoPunto;
  }else{
    aux = List;
    while(aux->next != NULL){
      aux = aux->next;
    }
    aux->next = nuevoPunto;
  }
  return List;
}

Point *imprimeLista(Point * List){
  Point * aux = List; 
  while(List != NULL){
    printf("%d %d\n",List->x,List->y);
    List = List->next;
  }
  List = aux;

  return List;
}

Point * ReadData(Point *);
Point * CalcularTamaño(Point *, int *);
Point *CalcularMenorDistancia(Point *,double *,int);
Point *LLenarPuntosConMenorDistancia(Point * , Point *, double, int);
Point *imprimeResultados(Point *, int );

int main(){
  Point *List = pointList(List); //Lista donde se almacenaran todos los puntos que se leen.
  Point *ResulstList = pointList(ResulstList); //Lista con los resultados.
  int size, sizeResults;
  double menorDistancia;

  List = ReadData(List);
  List = CalcularTamaño(List, &size);  
//  List = imprimeLista(List);
  List = CalcularMenorDistancia(List,&menorDistancia,size); 
  ResulstList = LLenarPuntosConMenorDistancia(ResulstList,List,menorDistancia,size);
//  ResulstList = imprimeLista(ResulstList);
  ResulstList = CalcularTamaño(ResulstList,&sizeResults);
  ResulstList = imprimeResultados(ResulstList,sizeResults);
  return 0;
}

Point * ReadData(Point * List){
  
  FILE * arch;
  int x , y; 
  arch = fopen("entrada.txt","r");
  if(arch == NULL){
    printf("Error en la apertura del archivo\n");
  }
 
  
  while(1){
    fscanf(arch,"%d %d",&x,&y);
    if(feof(arch)) break;
    
    List = agregarPunto(List, x,y);
  }
  
  fclose(arch);
  return List;
}

Point * CalcularTamaño(Point * List, int * size){
  Point * aux = List;
  *size = 0;
  while(List != NULL){
    (*size)++;
    List = List->next;
  }

  return aux;
}

Point *CalcularMenorDistancia(Point * List,double * menorDistancia, int size){
  Point *aux = List;
  double distancia;
  
//Copiandolo en  arreglo etático para aplicar el algoritmo. 
  Point  arrAux[size];
  
  for(int i = 0 ; i< size ; i++){
    arrAux[i].x = List->x;
    arrAux[i].y = List->y;
    List = List->next;
  }
//
  
  
  //Algoritmo de ClosestPair
  *menorDistancia = INF;
  for(int i = 0 ; i < size - 1 ; i++){
    for(int j = i+1 ; j < size ; j++){
      distancia = sqrt(pow(arrAux[i].x - arrAux[j].x,2) + pow(arrAux[i].y - arrAux[j].y,2));  
      if(distancia < *menorDistancia){
        *menorDistancia = distancia;
      }
    }
  }
  
  printf("La menor distancia entres los puntos es %.2lf\n",*menorDistancia);

  return aux;
} 

Point *LLenarPuntosConMenorDistancia(Point * ResultsList,Point * List , double menorDistancia,int size){
  
  //Copiandolo en  arreglo estático
  Point arrAux[size];
  
  for(int i = 0 ; i< size ; i++){
    arrAux[i].x = List->x;
    arrAux[i].y = List->y;
    List = List->next;
  }
  
  //Algoritmo de ClosestPair
  double distancia;
  for(int i = 0 ; i < size - 1 ; i++){
    for(int j = i+1 ; j < size ; j++){
      distancia = sqrt(pow(arrAux[i].x - arrAux[j].x,2) + pow(arrAux[i].y - arrAux[j].y,2));  
      if(fabs((double)distancia - (double)menorDistancia)< EPSILON ){
        ResultsList = agregarPunto(ResultsList, arrAux[i].x, arrAux[i].y); 
        ResultsList = agregarPunto(ResultsList, arrAux[j].x, arrAux[j].y); 
      }
    }
  }
    

  return ResultsList;
}

Point * imprimeResultados(Point * ResultsList, int sizeResults){
  Point *aux = ResultsList;

  printf("Las parejas de puntos con la menor distancia son las siguientes:\n");

  for(int i = 0 ; i< sizeResults ; i++){
    printf("(%d , %d)\n",ResultsList->x,ResultsList->y);
    ResultsList = ResultsList->next;
    if(i%2 != 0)
      printf("\n");
  }

  return ResultsList;
}

