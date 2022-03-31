#include <stdio.h>
#include <math.h>


typedef struct punto{
    int x;
    int y;
} Punto; 


int main(){

   Punto arrPuntos[4];

    arrPuntos[0].x = 1;
    arrPuntos[0].y = 4;
    arrPuntos[1].x = 0;
    arrPuntos[1].y = 0;
    arrPuntos[2].x = 39;
    arrPuntos[2].y = 20;
    arrPuntos[3].x = 0;
    arrPuntos[3].y = -5;

    int n = 4;
    double dmenor = 1000;
    int d,i1,i2;

    for (int i = 1 ; i <= n-1 ; i++ ){
        for(int j = i +1 ; j <= n ; j++){
            d = (arrPuntos[i].x - arrPuntos[j].x)^2 + (arrPuntos[i].y - arrPuntos[j].y)^2;
            if (d < dmenor){
                dmenor = d;
                i1 = i;
                i2 = j;
            }
        }
    }

    printf("%d %d\n",i1,i2);


    return 0;
}
