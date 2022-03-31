#include <stdio.h>
#include <stdlib.h>


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

int main(){
  Point *List = pointList(List);
  Point *ResulstList = pointList(ResulstList);
  List = ReadData(List);

  List = imprimeLista(List);

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
  
  return List;
}



