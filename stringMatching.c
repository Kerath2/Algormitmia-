#include <stdio.h>

int main(){


    char text[12] = {'l','a',' ','v','a','c','a',' ','l','o','l','a'};
    int n = 12;

    char pattern[4] = {'v','a','c','a'};
    int m =  4;

    for (int i = 0 ; i < n-m ; i++){
        int j = 0;
        
        while(j < m && pattern[j] == text[i+j]){
            j = j+1;

        } 
        if (j == m ){
            printf("%d\n",i);
        }
    }

    printf("-1");

    return 0;
}