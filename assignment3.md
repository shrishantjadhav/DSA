# ROW-MAJOR Order
 
## 1. What is "Row-Major" and "Column-Major"?
Ans: -> These are two ways of storing multi-dimensional arrays (especially 2D arrays) in linear memory (RAM).

Since RAM is linear (one-dimensional), when we declare a 2D array like:

    int arr[3][4];  // 3 rows, 4 columns
It needs to be stored linearly in memory.
There are two ways to convert this 2D data into a 1D memory layout:

## Row-Major Order:
Store rows one after another.

```
Example:

arr[3][4] = {
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9,10,11,12}
};
```

## Memory layout (Row-Major):
```
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
```

## Row-Major:
```
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]

Access: *(arr + i * cols + j)
``` 

## Pseudocode 1 — Row-Major Access (default in C/C++)
This access pattern matches how C/C++ stores 2D arrays — by rows. It is cache friendly.

```
1. Start
2. Input m, n, p
3. Allocate A[m][n], B[n][p], C[m][p] using `int **`
4. Fill A and B with values, initialize C to 0
5. // Matrix Multiplication (Row-Major Access Pattern)
6. for i = 0 to m-1
7.     for k = 0 to n-1
8.         temp = A[i][k]
9.         for j = 0 to p-1
10.            C[i][j] += temp * B[k][j]
11. End
12. Output C
13. Free all memory
14. End
```

## Algorithm: Row-Major Matrix Multiplication

```
1. Read integers m, n, p, q
2. Declare matrix A[m][n], B[p][q], C[m][q]
3. For i = 0 to m-1:
       For j = 0 to n-1:
           Read A[i][j]
4. For i = 0 to p-1:
       For j = 0 to q-1:
           Read B[i][j]
5. For i = 0 to m-1:
       For j = 0 to q-1:
           Set C[i][j] = 0
6. For i = 0 to m-1:
       For j = 0 to q-1:
           For k = 0 to n-1:
               C[i][j] += A[i][k] * B[k][j]
7. Print C
Program (Row-Major Order with _Svj variables)
```
## Code: 
```
#include <stdio.h>
#include <stdlib.h>

int main(){
    int m_Svj, n_Svj, p_Svj, q_Svj;
    int **A_Svj, **B_Svj, **C_Svj;

    printf("Enter rows and columns for 1st array:");
    scanf("%d %d", &m_Svj, &n_Svj);

    printf("Enter rows and columns for 2nd array:");
    scanf("%d %d", &p_Svj, &q_Svj); 

    A_Svj = (int**)malloc(sizeof(int*)*m_Svj);
    B_Svj = (int**)malloc(sizeof(int*)*p_Svj);
    C_Svj = (int**)malloc(sizeof(int*)*m_Svj);

    for(int i_Svj=0; i_Svj<m_Svj; i_Svj++){
        A_Svj[i_Svj] = (int*)malloc(sizeof(int)*n_Svj);
    }
    for(int i_Svj=0; i_Svj<p_Svj; i_Svj++){
        B_Svj[i_Svj] = (int*)malloc(sizeof(int)*q_Svj);
    }
    for(int i_Svj=0; i_Svj<m_Svj; i_Svj++){
        C_Svj[i_Svj] = (int*)malloc(sizeof(int)*q_Svj);
    }

    printf("Enter the elements of 1st array:");
    for(int i_Svj= 0; i_Svj<m_Svj; i_Svj++){
        for(int j_Svj=0; j_Svj<n_Svj; j_Svj++){
            scanf("%d", &A_Svj[i_Svj][j_Svj]);
        }
    }

    printf("Enter elements for 2nd array:");
    for(int i_Svj= 0; i_Svj<p_Svj; i_Svj++){
        for(int j_Svj=0; j_Svj<q_Svj; j_Svj++){
            scanf("%d", &B_Svj[i_Svj][j_Svj]);
        }
    }

    for(int i_Svj=0; i_Svj<m_Svj; i_Svj++){
        for(int j_Svj=0; j_Svj<q_Svj; j_Svj++){
            C_Svj[i_Svj][j_Svj] = 0;
        }
    }

    for(int i_Svj=0; i_Svj<m_Svj; i_Svj++){
        for(int j_Svj=0; j_Svj<q_Svj; j_Svj++){
            for(int k_Svj=0; k_Svj<n_Svj; k_Svj++){
                C_Svj[i_Svj][j_Svj] += A_Svj[i_Svj][k_Svj] * B_Svj[k_Svj][j_Svj];
            }
        }
    }

    printf("Printing the resultant array...\n");
    for(int i_Svj=0; i_Svj<m_Svj; i_Svj++){
        for(int j_Svj=0; j_Svj<q_Svj; j_Svj++){
            printf("%d\t", C_Svj[i_Svj][j_Svj]);
        }
        printf("\n");
    }
    for(int i_Svj=0; i_Svj<m_Svj; i_Svj++){
        free(A_Svj[i_Svj]);
        free(B_Svj[i_Svj]);
        free(C_Svj[i_Svj]);
    }
    free(A_Svj);
    free(B_Svj);
    free(C_Svj);
    return 0;
}
```

# Column-Major Order:
Store columns one after another.
Memory layout (Column-Major):
```
[1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12]
```
## 2. Where is it used?
Programming languages:

C, C++ → Row-Major

Fortran, MATLAB, R → Column-Major

Image processing

Numerical computing

Graphics & OpenGL

Cache-optimized matrix algorithms

## 3. Why is it Important?
Performance: Accessing data in the same order it's stored improves CPU cache performance.

Pointer arithmetic changes based on layout.

Important in interoperability between different languages (e.g., C ↔ MATLAB).

Affects algorithm efficiency, especially matrix operations.

## 4. Diagram: Visualizing Layouts
2D Array arr[3][4]:
markdown
```
      Col0 Col1 Col2 Col3
Row0   1    2    3    4
Row1   5    6    7    8
Row2   9   10   11   12
```

## Column-Major:
```
[1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12]

Access: *(arr + j * rows + i)
```

## Pseudocode 2 — Column-Major Access Simulation
This is a simulated column-major pattern. We don’t change storage — only the loop and access pattern. This causes strided memory access in C and is typically slower.

```
1. Start
2. Input m, n, p
3. Allocate A[m][n], B[n][p], C[m][p] using `int **`
4. Fill A and B with values, initialize C to 0
5. // Matrix Multiplication (Column-Major Access Simulation)
6. for j = 0 to p-1
7.     for k = 0 to n-1
8.         temp = B[k][j]
9.         for i = 0 to m-1
10.            C[i][j] += A[i][k] * temp
11. End
12. Output C
13. Free all memory
14. End
```
```
Input:
    A matrix of size m x n
    B matrix of size n x p
    (Both stored column-wise)
Output:
    C matrix of size m x p, where C = A × B
 ```
## Algorithm:
```
1. Read integers m, n, p
2. Declare A[n][m], B[p][n], C[p][m]   // Stored column-wise
3. For j = 0 to n-1:
       For i = 0 to m-1:
           Read A[j][i]
4. For j = 0 to p-1:
       For i = 0 to n-1:
           Read B[j][i]
5. For j = 0 to p-1:
       For i = 0 to m-1:
           Set C[j][i] = 0
6. For j = 0 to p-1:
       For i = 0 to m-1:
           For k = 0 to n-1:
               C[j][i] = C[j][i] + A[k][i] * B[j][k]
7. For i = 0 to m-1:
       For j = 0 to p-1:
           Print C[j][i]
```

## Code:
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, p, q;
    int *A, *B, *C;

    printf("Enter rows and columns for 1st array: ");
    scanf("%d %d", &m, &n);

    printf("Enter rows and columns for 2nd array: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    // Allocate memory as 1D arrays (column-major)
    A = (int*)malloc(sizeof(int) * m * n);
    B = (int*)malloc(sizeof(int) * p * q);
    C = (int*)malloc(sizeof(int) * m * q);

    // Input first matrix (column-major storage)
    printf("Enter the elements of 1st array (column by column):\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            scanf("%d", &A[j * m + i]);  // column-major
        }
    }

    // Input second matrix (column-major storage)
    printf("Enter elements for 2nd array (column by column):\n");
    for (int j = 0; j < q; j++) {
        for (int i = 0; i < p; i++) {
            scanf("%d", &B[j * p + i]);  // column-major
        }
    }

    // Multiply matrices
    for (int j = 0; j < q; j++) {
        for (int i = 0; i < m; i++) {
            C[j * m + i] = 0;
            for (int k = 0; k < n; k++) {
                C[j * m + i] += A[k * m + i] * B[j * p + k];
            }
        }
    }

    // Print result (row by row for clarity)
    printf("Resultant Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", C[j * m + i]);
        }
        printf("\n");
    }

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}
```