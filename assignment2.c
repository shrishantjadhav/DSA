/*Goal: Fill an n × n matrix (n odd) with numbers 1..n² so every row, column, and both diagonals sum to the same magic sum = n(n²+1)/2*.
 */

#include <stdio.h>
#include<stdlib.h>

int main(){

    int** magic_square = NULL;
    int n,i,j, num;
    int rows, cols, next_row, next_col;
    printf("Enter the number of rows and columns: ");
    scanf("%d", &n);

    if (n<0 || n%2 ==0){
        printf("Enter an odd positive number:");
        exit(-1);
    }

    magic_square = (int**)malloc(sizeof(int*)*n);
    if (magic_square == NULL){
        printf("memory allocation failed");
        exit(0);
    }
    for(i=0; i<n;i++){
        magic_square[i] = (int*)malloc(sizeof(int)*(n));
        if (magic_square[i]==NULL){
            printf("Mamory allocation failed");
            exit(0);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            magic_square[i][j] = 0;
        }
    }

    rows = 0;
    cols = n/2;

    for(num= 1; num<=n*n; num++){
        magic_square[rows][cols] = num;

        next_row = rows-1;
        next_col = cols+1;
        
        if(next_row < 0){
            next_row = n-1;
        }
        if(next_col == n){
            next_col = 0;
        }

        if(magic_square[next_row][next_col] != 0){
            next_row = (rows + 1) % 2;
            next_col = cols;
        }

        rows = next_row;
        cols = next_col;
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%4d", magic_square[i][j]);
        }
        printf("\n");
    }
    printf("magic sum: %d", n*(n*n+1)/2);

    for(i=0; i<n; i++){
        free(magic_square[i]);
    }
    free(magic_square);
    return 0;
}