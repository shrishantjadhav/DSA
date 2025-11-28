# Assignment 01-03

## Aim
To perform matrix multiplication using both row-major and column-major methods and compare the results.

## Steps Followed
1. Initialized two 2D matrices with random integers for given dimensions.
2. Implemented matrix multiplication using row-major traversal.
3. Implemented matrix multiplication using column-major traversal.
4. Displayed input matrices as well as resultant matrices from both methods for verification.

## Code
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

void fillMatrixRandom(int a[50][50], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] = rand() % 10; 
        }
    }
}

void displayMatrix(int a[50][50], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void matrixMultiplyRowMajor(int A[50][50], int B[50][50], int C[50][50], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            int temp = A[i][k];
            for (int j = 0; j < p; j++) {
                C[i][j] += temp * B[k][j];
            }
        }
    }
}

void matrixMultiplyColumnMajor(int A[50][50], int B[50][50], int C[50][50], int m, int n, int p) {
    for (int j = 0; j < p; j++) {
        for (int k = 0; k < n; k++) {
            int temp = B[k][j];
            for (int i = 0; i < m; i++) {
                C[i][j] += A[i][k] * temp;
            }
        }
    }
}

int main() {
    int m, n, p;
    int A[50][50], B[50][50], C1[50][50] = {0}, C2[50][50] = {0};

    cout<<"Enter dimensions (m n p): ";
    cin>>m>>n>>p;

    fillMatrixRandom(A, m, n);
    fillMatrixRandom(B, n, p);

    cout<<"\nMatrix A:"<<endl;
    displayMatrix(A, m, n);

    cout<<"\nMatrix B:"<<endl;
    displayMatrix(B, n, p);

    matrixMultiplyRowMajor(A, B, C1, m, n, p);
    matrixMultiplyColumnMajor(A, B, C2, m, n, p);

    cout<<"\nResult Matrix C (Row-Major):"<<endl;
    displayMatrix(C1, m, p);

    cout<<"\nResult Matrix C (Column-Major):"<<endl;
    displayMatrix(C2, m, p);

    return 0;
}
```

## Output (Sample)
```
Enter dimensions (m n p): 2 3 2

Matrix A:
1 4 7
2 5 8

Matrix B:
1 4
2 5
3 6

Result Matrix C (Row-Major):
30 72 
36 81 

Result Matrix C (Column-Major):
30 72 
36 81
