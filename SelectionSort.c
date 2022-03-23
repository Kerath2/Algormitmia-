#include <stdio.h>


int main(){
    
    int arr[7] = {89,45,68,90,29,34,17};
    int n = 7;
    for (int i = 0 ; i <= n - 2 ; i++){
        int min = i;
        for (int j = i+1 ; j < n ; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        int aux = arr[i];
        arr[i] = arr[min];
        arr[min] = aux;
    }

    for (int i = 0 ; i < n ; i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}