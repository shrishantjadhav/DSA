# Fast Transpose of Sparse Matrix using Triplet Representation in C

## 📌 What is a Sparse Matrix?

A **Sparse Matrix** is a 2D matrix in which most of the elements are **zero**.  
Instead of storing all elements, we store only the **non-zero elements** with their **row index, column index, and value** in a **triplet form**.  

The **Fast Transpose** method efficiently computes the transpose by using **counting and indexing**, which is faster than the simple column-wise method.

---

## 📌 Algorithm

1. Start.  
2. Input the number of rows **m_Svj** and columns **n_Svj**.  
3. Allocate dynamic memory for the 2D matrix **mat_Svj[m_Svj][n_Svj]**.  
4. Input matrix elements.  
5. Count the number of non-zero elements **nonZero_Svj**.  
6. Allocate memory for **triplet_Svj** and **trans_Svj** arrays of size `(nonZero_Svj + 1) × 3`.  
7. Store triplet representation:  
   - Header row `[m_Svj, n_Svj, nonZero_Svj]`.  
   - Remaining rows `[row_index, col_index, value]`.  
8. Perform Fast Transpose:  
   - Count number of elements in each column (`total_Svj`).  
   - Determine starting index of each column (`index_Svj`).  
   - Place elements directly at the correct positions in **trans_Svj**.  
9. Print original and transposed triplet representations.  
10. Free all dynamically allocated memory.  
11. End.

---

## 📌 Pseudocode
```
START

Input number of rows (m_Svj) and columns (n_Svj)

Allocate mat_Svj[m_Svj][n_Svj]

Input elements of mat_Svj

Count non-zero elements → nonZero_Svj

Allocate triplet_Svj and trans_Svj [(nonZero_Svj + 1) × 3]

Store triplet:
triplet_Svj[0] = [m_Svj, n_Svj, nonZero_Svj]
k_Svj = 1
For i_Svj = 0 to m_Svj-1:
For j_Svj = 0 to n_Svj-1:
If mat_Svj[i_Svj][j_Svj] != 0:
triplet_Svj[k_Svj] = [i_Svj, j_Svj, mat_Svj[i_Svj][j_Svj]]
k_Svj++

Fast Transpose:

Initialize total_Svj[cols_Svj] = 0

For each element in triplet_Svj:
total_Svj[column_index]++

index_Svj[0] = 1

For i = 1 to cols_Svj-1:
index_Svj[i] = index_Svj[i-1] + total_Svj[i-1]

For each element in triplet_Svj:
pos = index_Svj[column_index]++
trans_Svj[pos] = [column_index, row_index, value]

Print triplet_Svj
Print trans_Svj

Free all memory

END
```

---

## 📌 Dry Run Example

### Input:
Rows = 3, Cols = 3  
Matrix:

0 5 0
3 0 4
0 2 0


### Step 1: Count Non-Zero Elements
Non-zero elements: **5, 3, 4, 2** → count = 4  

### Step 2: Triplet Representation
Row Col Value
3 3 4 ← header
0 1 5
1 0 3
1 2 4
2 1 2


### Step 3: Fast Transpose Triplet Representation
Row Col Value
3 3 4 ← header
1 0 3
0 1 5
2 1 2
1 2 4



**Explanation:**  
- `total_Svj` array counts elements per column: `[1,2,1]`  
- `index_Svj` determines starting positions: `[1,2,4]`  
- Each element from triplet is placed directly in its correct position in `trans_Svj`.

---

## 📌 C Program

```c
#include <stdio.h>
#include <stdlib.h>

// Fast Transpose of a sparse matrix (triplet representation)
void fastTranspose(int **triplet_Svj, int **trans_Svj) {
    int rows_Svj = triplet_Svj[0][0], cols_Svj = triplet_Svj[0][1], terms_Svj = triplet_Svj[0][2];
    int i_Svj, j_Svj;

    int *total_Svj = (int *)calloc(cols_Svj, sizeof(int));
    int *index_Svj = (int *)malloc(cols_Svj * sizeof(int));

    trans_Svj[0][0] = cols_Svj;
    trans_Svj[0][1] = rows_Svj;
    trans_Svj[0][2] = terms_Svj;

    for (i_Svj = 1; i_Svj <= terms_Svj; i_Svj++)
        total_Svj[triplet_Svj[i_Svj][1]]++;

    index_Svj[0] = 1;
    for (i_Svj = 1; i_Svj < cols_Svj; i_Svj++)
        index_Svj[i_Svj] = index_Svj[i_Svj - 1] + total_Svj[i_Svj - 1];

    for (i_Svj = 1; i_Svj <= terms_Svj; i_Svj++) {
        j_Svj = index_Svj[triplet_Svj[i_Svj][1]]++;
        trans_Svj[j_Svj][0] = triplet_Svj[i_Svj][1];
        trans_Svj[j_Svj][1] = triplet_Svj[i_Svj][0];
        trans_Svj[j_Svj][2] = triplet_Svj[i_Svj][2];
    }

    free(total_Svj);
    free(index_Svj);
}

int main() {
    int m_Svj, n_Svj, i_Svj, j_Svj, k_Svj = 1;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m_Svj, &n_Svj);

    int **mat_Svj = (int **)malloc(m_Svj * sizeof(int *));
    for (i_Svj = 0; i_Svj < m_Svj; i_Svj++)
        mat_Svj[i_Svj] = (int *)malloc(n_Svj * sizeof(int));

    printf("Enter matrix elements:\n");
    for (i_Svj = 0; i_Svj < m_Svj; i_Svj++)
        for (j_Svj = 0; j_Svj < n_Svj; j_Svj++)
            scanf("%d", &mat_Svj[i_Svj][j_Svj]);

    int nonZero_Svj = 0;
    for (i_Svj = 0; i_Svj < m_Svj; i_Svj++)
        for (j_Svj = 0; j_Svj < n_Svj; j_Svj++)
            if (mat_Svj[i_Svj][j_Svj] != 0)
                nonZero_Svj++;

    int **triplet_Svj = (int **)malloc((nonZero_Svj + 1) * sizeof(int *));
    int **trans_Svj   = (int **)malloc((nonZero_Svj + 1) * sizeof(int *));
    for (i_Svj = 0; i_Svj <= nonZero_Svj; i_Svj++) {
        triplet_Svj[i_Svj] = (int *)malloc(3 * sizeof(int));
        trans_Svj[i_Svj]   = (int *)malloc(3 * sizeof(int));
    }

    triplet_Svj[0][0] = m_Svj;
    triplet_Svj[0][1] = n_Svj;
    triplet_Svj[0][2] = nonZero_Svj;

    k_Svj = 1;
    for (i_Svj = 0; i_Svj < m_Svj; i_Svj++) {
        for (j_Svj = 0; j_Svj < n_Svj; j_Svj++) {
            if (mat_Svj[i_Svj][j_Svj] != 0) {
                triplet_Svj[k_Svj][0] = i_Svj;
                triplet_Svj[k_Svj][1] = j_Svj;
                triplet_Svj[k_Svj][2] = mat_Svj[i_Svj][j_Svj];
                k_Svj++;
            }
        }
    }

    fastTranspose(triplet_Svj, trans_Svj);

    printf("\nOriginal Triplet Representation:\n");
    for (i_Svj = 0; i_Svj <= nonZero_Svj; i_Svj++)
        printf("%d\t%d\t%d\n", triplet_Svj[i_Svj][0], triplet_Svj[i_Svj][1], triplet_Svj[i_Svj][2]);

    printf("\nFast Transpose Triplet Representation:\n");
    for (i_Svj = 0; i_Svj <= nonZero_Svj; i_Svj++)
        printf("%d\t%d\t%d\n", trans_Svj[i_Svj][0], trans_Svj[i_Svj][1], trans_Svj[i_Svj][2]);

    for (i_Svj = 0; i_Svj < m_Svj; i_Svj++)
        free(mat_Svj[i_Svj]);
    free(mat_Svj);

    for (i_Svj = 0; i_Svj <= nonZero_Svj; i_Svj++) {
        free(triplet_Svj[i_Svj]);
        free(trans_Svj[i_Svj]);
    }
    free(triplet_Svj);
    free(trans_Svj);

    return 0;
}
```