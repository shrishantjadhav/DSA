#include <stdio.h>
#include <stdlib.h> // for malloc(), free(), exit()

int main(void)
{
    //varaible declarations
    int** magic_square = NULL;
    int n,num;
    int row, col, next_row, next_col;
    int i, j;

    //Code

    //1: Read n. If n <= 0 or n is even → stop with error (works only for odd n).
    printf("Enter the value of n : ");
    scanf("%d", &n);

    if (n <= 0 || n % 2 == 0)
    {
        printf("Error: n must be positive Odd Number.");
        exit(-1);
    }

    //2. Dynamically allocate an n × n matrix and initialize every cell to 0.
    magic_square =(int**)malloc(sizeof(int*) * n);

    if (magic_square == NULL)
    {
        printf("Memory allocation failed. \n");
        exit(-2);
    }

    for (i = 0; i < n; i++)
    {
        magic_square[i] = (int*)malloc(sizeof(int) * n);
        if (magic_square[i] == NULL)
        {
            printf("Memory allcoation failed. \n");
            exit(-3);
        }
    }
    //initlialize all the cells to 0
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            magic_square[i][j] = 0;
        }
    }

    //3. Set row = 0 and col = n / 2 (top row, middle column).
    row = 0;
    col = n / 2;

    //4. For num from 1 to n*n:
    for (num = 1; num <= n * n; num++)
    {
        //4a. Place num at matrix[row][col].
        magic_square[row][col] = num;

        // 4b. Compute tentative next position: next_row = row - 1 (move up), next_col = col + 1 (move right).
        next_row = row - 1;
        next_col = col + 1;

        //4c. Wrap around the edges: if next_row < 0 → next_row = n - 1; if next_col == n → next_col = 0.
        if (next_row < 0)
            next_row = n - 1;
        if (next_col == n)
            next_col = 0;

        //4d. If matrix[next_row][next_col] != 0 (occupied), then instead move down one from the current cell:
            //next_row = (row + 1) % n;
            //next_col = col.
        if (magic_square[next_row][next_col] != 0)
        {
            next_row = (row + 1) % n;
            next_col = col;
        }

        //4e. Update row = next_row; col = next_col.
        row = next_row;
        col = next_col;
     }

    //5. Print the matrix and the magic sum.
     for (int i = 0; i < n; i++) 
     {
       for (int j = 0; j < n; j++) 
       {
            printf("%4d", magic_square[i][j]);
       }
        printf("\n");
     }

     printf("Magic Sum : %d\n\n", n*(n * n + 1) / 2);

    //6. Free all dynamically allocated memory.
     for (i = 0; i < n; i++)
         free(magic_square[i]);
     free(magic_square);

     return(0);
}