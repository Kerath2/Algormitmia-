#include <stdio.h>

int main(){

    int arr[7] = {89,45,68,90,29,34,17};
    int n = 7;

    for (int i = 0 ; i <= n-2  ; i++){
        for (int j = 0; j <= n-2-i ; j++){
            if(arr[j+1] < arr[j]){
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }

    for (int i = 0 ; i < n ; i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}