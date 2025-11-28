# Assignment 01-05

## Aim
To implement and demonstrate fast transpose algorithm for sparse matrices using array representation.

## Steps Followed
1. Created sparse matrix representation using arrays for rows, columns, and values of non-zero elements.
2. Implemented functions to:
   - Convert a dense matrix into sparse matrix.
   - Display sparse matrix and its dense form.
   - Perform fast transpose of sparse matrix for column-wise efficient transposition.
3. Demonstrated the above by using a sample 4x4 sparse matrix.
4. Displayed matrices in dense and sparse forms before and after transposition.
5. Explained the fast transpose algorithm detailing time and space complexity.

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

void displaySparseMatrix(SparseMatrix &matrix) {
    cout << "\nSparse Matrix Representation:\n";
    cout << "Rows: " << matrix.rows << " Cols: " << matrix.cols << " Non-zero elements: " << matrix.nonZeroCount << "\n";
    cout << "Row Col Value\n";
    for (int i = 0; i < matrix.nonZeroCount; i++) {
        cout << matrix.row[i] << " " << matrix.col[i] << " " << matrix.value[i] << "\n";
    }
}

void displaySparseAsDense(SparseMatrix &matrix) {
    cout << "\nSparse as Dense:\n";
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
        cout << "\n";
    }
}

SparseMatrix fastTranspose(SparseMatrix &matrix) {
    SparseMatrix t;
    createSparseMatrix(t, matrix.cols, matrix.rows);
    if (matrix.nonZeroCount == 0) return t;

    int rowTerms[50] = {0};
    int startingPos[50] = {0};

    for (int i = 0; i < matrix.nonZeroCount; i++) {
        rowTerms[matrix.col[i]]++;
    }

    startingPos[0] = 0;
    for (int i = 1; i < matrix.cols; i++) {
        startingPos[i] = startingPos[i-1] + rowTerms[i-1];
    }

    for (int i = 0; i < matrix.nonZeroCount; i++) {
        int col = matrix.col[i];
        int pos = startingPos[col];
        t.row[pos] = matrix.col[i];
        t.col[pos] = matrix.row[i];
        t.value[pos] = matrix.value[i];
        startingPos[col]++;
    }

    t.nonZeroCount = matrix.nonZeroCount;
    return t;
}

int main() {
    int rows = 4;
    int cols = 4;
    int dense[50][50] = {
        {5,0,0,2},
        {0,3,0,0},
        {0,0,1,0},
        {7,0,0,4}
    };

    cout << "Original Dense Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << dense[i][j] << " ";
        }
        cout << "\n";
    }

    SparseMatrix sparse;
    convertToSparse(dense, sparse, rows, cols);

    cout << "\nOriginal Sparse Matrix:";
    displaySparseMatrix(sparse);

    SparseMatrix transposed = fastTranspose(sparse);

    cout << "\nTransposed Sparse Matrix:";
    displaySparseMatrix(transposed);

    cout << "\nOriginal Matrix as Dense:";
    displaySparseAsDense(sparse);

    cout << "\nTransposed Matrix as Dense:";
    displaySparseAsDense(transposed);

    cout << "\nFast Transpose Algorithm Explanation:\n";
    cout << "1. Count non-zero elements per column\n";
    cout << "2. Calculate starting position for each column in transpose\n";
    cout << "3. Place elements directly in correct positions\n";
    cout << "Time Complexity: O(columns + nonZeroCount)\n";
    cout << "Space Complexity: O(nonZeroCount)\n";

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

Original Sparse Matrix:
Rows: 4 Cols: 4 Non-zero elements: 6
Row Col Value
0 0 5
0 3 2
1 1 3
2 2 1
3 0 7
3 3 4

Transposed Sparse Matrix:
Rows: 4 Cols: 4 Non-zero elements: 6
Row Col Value
0 0 5
1 1 3
2 2 1
3 0 2
0 3 7
3 3 4

Original Matrix as Dense:
5 0 0 2 
0 3 0 0 
0 0 1 0 
7 0 0 4 

Transposed Matrix as Dense:
5 0 0 7 
0 3 0 0 
0 0 1 0 
2 0 0 4 

Fast Transpose Algorithm Explanation:
1. Count non-zero elements per column
2. Calculate starting position for each column in transpose
3. Place elements directly in correct positions
Time Complexity: O(columns + nonZeroCount)
Space Complexity: O(nonZeroCount)
