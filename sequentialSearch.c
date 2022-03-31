#include <stdio.h>

int main(){

    int key = 29;
    int arr[7] = {89,45,68,90,29,34,17};
    int n = 7;

    int i = 0;

    while(i < n && arr[i]!= key){
        i = i +1;

    } 
    if (i < n){
        printf("%d\n",i);
    }
    else {
        printf("-1\n");
    }

    return 0;
}
