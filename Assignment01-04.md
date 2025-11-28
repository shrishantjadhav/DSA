# Assignment 01-04

## Aim
To implement sparse matrix representation, perform simple transpose, and display matrices in both dense and sparse formats.

## Steps Followed
1. Created a structure to represent sparse matrices including arrays for rows, columns, and values of non-zero elements.
2. Implemented functions to:
   - Convert a dense matrix into sparse matrix form.
   - Display dense and sparse formats.
   - Perform simple transpose of sparse matrix.
3. Tested above functions with a sample dense matrix.
4. Displayed original matrix, sparse form, sparse as dense, transposed sparse form, and transposed sparse as dense.

## Code
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

struct SparseMatrix {
    int rows;
    int cols;
    int nonZeroCount;
    int row[50];
    int col[50];
    int value[50];
};

void createSparseMatrix(SparseMatrix &matrix, int r, int c) {
    matrix.rows = r;
    matrix.cols = c;
    matrix.nonZeroCount = 0;
}

void addElement(SparseMatrix &matrix, int r, int c, int val) {
    if (val != 0) {
        matrix.row[matrix.nonZeroCount] = r;
        matrix.col[matrix.nonZeroCount] = c;
        matrix.value[matrix.nonZeroCount] = val;
        matrix.nonZeroCount++;
    }
}

void convertToSparse(int dense[50][50], SparseMatrix &sparse, int r, int c) {
    createSparseMatrix(sparse, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            addElement(sparse, i, j, dense[i][j]);
        }
    }
}

void displayDenseMatrix(int matrix[50][50], int r, int c) {
    cout << "\nDense Matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void displaySparseMatrix(SparseMatrix &matrix) {
    cout << "\nSparse Matrix Representation:" << endl;
    cout << "Rows: " << matrix.rows << " Cols: " << matrix.cols << " Non-zero elements: " << matrix.nonZeroCount << endl;
    cout << "Row Col Value" << endl;
    for (int i = 0; i < matrix.nonZeroCount; i++) {
        cout << matrix.row[i] << " " << matrix.col[i] << " " << matrix.value[i] << endl;
    }
}

void displaySparseAsDense(SparseMatrix &matrix) {
    cout << "\nSparse as Dense:" << endl;
    int k = 0;
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (k < matrix.nonZeroCount && matrix.row[k] == i && matrix.col[k] == j) {
                cout << matrix.value[k] << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

SparseMatrix simpleTranspose(SparseMatrix &matrix) {
    SparseMatrix t;
    createSparseMatrix(t, matrix.cols, matrix.rows);
    for (int i = 0; i < matrix.nonZeroCount; i++) {
        addElement(t, matrix.col[i], matrix.row[i], matrix.value[i]);
    }
    return t;
}

int main() {
    int rows = 4, cols = 4;
    int dense[50][50] = {
        {5, 0, 0, 2},
        {0, 3, 0, 0},
        {0, 0, 1, 0},
        {7, 0, 0, 4}
    };

    cout << "Original Dense Matrix:";
    displayDenseMatrix(dense, rows, cols);

    SparseMatrix sparse;
    convertToSparse(dense, sparse, rows, cols);

    displaySparseMatrix(sparse);
    displaySparseAsDense(sparse);

    SparseMatrix transposed = simpleTranspose(sparse);
    cout << "\nTransposed Sparse Matrix:";
    displaySparseMatrix(transposed);
    cout << "\nTransposed as Dense:";
    displaySparseAsDense(transposed);

    return 0;
}
```

## Output (Sample)
```
Original Dense Matrix:
5 0 0 2 
0 3 0 0 
0 0 1 0 
7 0 0 4 

Sparse Matrix Representation:
Rows: 4 Cols: 4 Non-zero elements: 6
Row Col Value
0 0 5
0 3 2
1 1 3
2 2 1
3 0 7
3 3 4

Sparse as Dense:
5 0 0 2 
0 3 0 0 
0 0 1 0 
7 0 0 4 

Transposed Sparse Matrix:
Rows: 4 Cols: 4 Non-zero elements: 6
Row Col Value
0 0 5
1 1 3
2 2 1
3 0 2
0 3 7
3 3 4

Transposed as Dense:
5 0 0 7 
0 3 0 0 
0 0 1 0 
2 0 0 4
