# Doubly Even Magic Square in C

This program generates a **Doubly Even Magic Square** (size n × n, where n is a multiple of 4) using **Strachey's method**.

---

## Algorithm

1. **Input** the size `n_Svj` of the magic square (must be positive and a multiple of 4).  
2. **Allocate memory** for a 2D array `magic_square_Svj`.  
3. **Fill the matrix** sequentially from `1` to `n_Svj * n_Svj`.  
4. **Modify the matrix** according to Strachey's rule:  
   - For cells **not in the main 4x4 pattern**, replace the value with `(n_Svj * n_Svj + 1) - value`.  
5. **Print the magic square**.  
6. **Compute and display the magic sum**: `n_Svj * (n_Svj * n_Svj + 1) / 2`.  
7. **Free the allocated memory**.

---

## Pseudocode
```
START
INPUT n_Svj
IF n_Svj <= 0 OR n_Svj % 4 != 0 THEN
PRINT "Error"
EXIT
ENDIF

ALLOCATE magic_square_Svj[n_Svj][n_Svj]

num_Svj = 1
FOR i_Svj = 0 TO n_Svj-1
FOR j_Svj = 0 TO n_Svj-1
magic_square_Svj[i_Svj][j_Svj] = num_Svj
num_Svj = num_Svj + 1
ENDFOR
ENDFOR

FOR i_Svj = 0 TO n_Svj-1
FOR j_Svj = 0 TO n_Svj-1
IF cell NOT in main 4x4 pattern THEN
magic_square_Svj[i_Svj][j_Svj] = (n_Svj*n_Svj + 1) - magic_square_Svj[i_Svj][j_Svj]
ENDIF
ENDFOR
ENDFOR

PRINT magic_square_Svj
PRINT magic sum = n_Svj*(n_Svj*n_Svj + 1)/2

FREE memory
END
```


---

## C Program

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n_Svj, i_Svj, j_Svj;
    int **magic_square_Svj;

    printf("Enter even n (multiple of 4): ");
    scanf("%d", &n_Svj);

    if (n_Svj <= 0 || n_Svj % 4 != 0)
    {
        printf("Error: n must be positive and a multiple of 4.\n");
        exit(-1);
    }

    // Allocate memory
    magic_square_Svj = (int **)malloc(n_Svj * sizeof(int *));
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++)
    {
        magic_square_Svj[i_Svj] = (int *)malloc(n_Svj * sizeof(int));
    }

    // Fill matrix with numbers 1 to n^2
    int num_Svj = 1;
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++)
    {
        for (j_Svj = 0; j_Svj < n_Svj; j_Svj++)
        {
            magic_square_Svj[i_Svj][j_Svj] = num_Svj;
            num_Svj++;
        }
    }

    // Modify according to Strachey's rule
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++)
    {
        for (j_Svj = 0; j_Svj < n_Svj; j_Svj++)
        {
            if (!((i_Svj % 4 == 0 && j_Svj % 4 == 0) ||
                  (i_Svj % 4 == 3 && j_Svj % 4 == 3) ||
                  (i_Svj % 4 == 0 && j_Svj % 4 == 3) ||
                  (i_Svj % 4 == 3 && j_Svj % 4 == 0)))
            {
                magic_square_Svj[i_Svj][j_Svj] = (n_Svj * n_Svj + 1) - magic_square_Svj[i_Svj][j_Svj];
            }
        }
    }

    // Print the magic square
    printf("\nMagic Square of size %d (Doubly Even):\n", n_Svj);
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++)
    {
        for (j_Svj = 0; j_Svj < n_Svj; j_Svj++)
        {
            printf("%4d", magic_square_Svj[i_Svj][j_Svj]);
        }
        printf("\n");
    }

    printf("\nMagic Sum = %d\n", n_Svj * (n_Svj * n_Svj + 1) / 2);

    // Free memory
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++)
        free(magic_square_Svj[i_Svj]);
    free(magic_square_Svj);

    return 0;
}
```
## Dry Run Example

Input:

`` n_Svj = 4 ``


### Step 1: Fill matrix sequentially (1 to 16)
```
 1   2   3   4
  5   6   7   8
  9  10  11  12
  13  14  15  16
```


### Step 2: Modify according to Strachey's rule
**Cells at the corners of 4x4 pattern remain the same; others are replaced by (16+1 - value) = 17 - value.**
```
 1  16  15   4
 12   6   7   9
  8  10  11   5
 13   3   2  16
```

### Step 3: Magic sum

`Magic Sum = n_Svj*(n_Svj*n_Svj + 1)/2 = 4*(16+1)/2 = 34`


**All rows, columns, and diagonals sum to 34.**

# Magic Square for odd numbers.


# Magic Square 

## 📌 Introduction
This program generates an **Odd-Order Magic Square** using the **Siamese method**.  
A magic square is an `n × n` matrix (where `n` is odd) filled with numbers `1` to `n²` such that:
- The sum of numbers in each row, each column, and both diagonals is the same (**Magic Constant**).

---

## ⚙️ Step-by-Step Algorithm
1. **Input `n_Svj`**  
   - If `n_Svj <= 0` or `n_Svj` is even → Stop with error.  
   - Works only for **positive odd integers**.

2. **Dynamic Allocation**  
   - Allocate memory for an `n_Svj × n_Svj` matrix.  
   - Initialize all elements to **0**.

3. **Starting Position**  
   - Place `1` at:  
     `row_Svj = 0` (top row), `col_Svj = n_Svj / 2` (middle column).

4. **Placement Rule (Siamese Method)**  
   For each number `num_Svj` from `1 → n_Svj²`:
   - Place at current `(row_Svj, col_Svj)`.
   - Compute tentative next position:  
     `next_row_Svj = row_Svj - 1`, `next_col_Svj = col_Svj + 1`.
   - **Wrap Around**:  
     - If `next_row_Svj < 0 → next_row_Svj = n_Svj - 1`.  
     - If `next_col_Svj == n_Svj → next_col_Svj = 0`.
   - **Occupied Cell Rule**:  
     If the target cell is already filled → move **down** one row instead:  
     `next_row_Svj = (row_Svj + 1) % n_Svj`, `next_col_Svj = col_Svj`.
   - Update `row_Svj = next_row_Svj`, `col_Svj = next_col_Svj`.

5. **Output**  
   - Print the `n_Svj × n_Svj` magic square.
   - Print the **Magic Constant**:  
     `M = n_Svj * (n_Svj² + 1) / 2`.

6. **Free Memory**  
   - Release dynamically allocated memory.

---

## 🖥️ C Code

```c
#include <stdio.h>
#include <stdlib.h> // for malloc(), free(), exit()

int main(void)
{
    int** magic_square_Svj = NULL;
    int n_Svj, num_Svj;
    int row_Svj, col_Svj, next_row_Svj, next_col_Svj;
    int i_Svj, j_Svj;

    // Step 1: Input
    printf("Enter the value of n : ");
    scanf("%d", &n_Svj);

    if (n_Svj <= 0 || n_Svj % 2 == 0)
    {
        printf("Error: n must be positive Odd Number.");
        exit(-1);
    }

    // Step 2: Allocate memory
    magic_square_Svj = (int**)malloc(sizeof(int*) * n_Svj);
    if (magic_square_Svj == NULL) { printf("Memory allocation failed.\n"); exit(-2); }

    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++)
    {
        magic_square_Svj[i_Svj] = (int*)malloc(sizeof(int) * n_Svj);
        if (magic_square_Svj[i_Svj] == NULL) { printf("Memory allocation failed.\n"); exit(-3); }
    }

    // Initialize matrix with 0
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++)
        for (j_Svj = 0; j_Svj < n_Svj; j_Svj++)
            magic_square_Svj[i_Svj][j_Svj] = 0;

    // Step 3: Starting position
    row_Svj = 0;
    col_Svj = n_Svj / 2;

    // Step 4: Fill magic square
    for (num_Svj = 1; num_Svj <= n_Svj * n_Svj; num_Svj++)
    {
        magic_square_Svj[row_Svj][col_Svj] = num_Svj;

        next_row_Svj = row_Svj - 1;
        next_col_Svj = col_Svj + 1;

        if (next_row_Svj < 0) next_row_Svj = n_Svj - 1;
        if (next_col_Svj == n_Svj) next_col_Svj = 0;

        if (magic_square_Svj[next_row_Svj][next_col_Svj] != 0)
        {
            next_row_Svj = (row_Svj + 1) % n_Svj;
            next_col_Svj = col_Svj;
        }

        row_Svj = next_row_Svj;
        col_Svj = next_col_Svj;
    }

    // Step 5: Print result
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++) {
        for (j_Svj = 0; j_Svj < n_Svj; j_Svj++) {
            printf("%4d", magic_square_Svj[i_Svj][j_Svj]);
        }
        printf("\n");
    }

    printf("Magic Sum : %d\n", n_Svj * (n_Svj * n_Svj + 1) / 2);

    // Step 6: Free memory
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++)
        free(magic_square_Svj[i_Svj]);
    free(magic_square_Svj);

    return 0;
}

## 💻 C Code 

*(Same as shared earlier — includes `_Svj` suffix on all variables.)*



## 🔎 Dry Run Example 1 (n_Svj = 3)

Initial Setup:  
- Start at `(row_Svj = 0, col_Svj = 1)` (top middle).  
- Empty 3×3 matrix initialized to `0`.

### Step Table
| Step | Number | Position (row_Svj, col_Svj) | Tentative Move | Wrap Applied? | Occupied? | Final Position |
|------|---------|-----------------------------|----------------|---------------|-----------|----------------|
| 1    | 1       | (0,1)                      | (-1,2) → (2,2) | Wrap row      | No        | (0,1) |
| 2    | 2       | (2,2)                      | (1,3) → (1,0)  | Wrap col      | No        | (2,2) |
| 3    | 3       | (1,0)                      | (0,1)          | —             | Yes       | (1,0) |
| 4    | 4       | (2,0)                      | (1,1)          | —             | No        | (2,0) |
| 5    | 5       | (1,1)                      | (0,2)          | —             | No        | (1,1) |
| 6    | 6       | (0,2)                      | (-1,3) → (2,0) | Wrap row/col  | Yes       | (0,2) |
| 7    | 7       | (1,2)                      | (0,3) → (0,0)  | Wrap col      | No        | (1,2) |
| 8    | 8       | (0,0)                      | (-1,1) → (2,1) | Wrap row      | No        | (0,0) |
| 9    | 9       | (2,1)                      | —              | —             | No        | (2,1) |

---

### 📜 Code Tracing (n_Svj = 3)

1. Place **1** at `(0,1)` → tentative `(−1,2)` → wrap to `(2,2)`.  
2. Place **2** at `(2,2)` → tentative `(1,3)` → wrap `(1,0)`.  
3. Place **3** at `(1,0)` → tentative `(0,1)` but occupied → move down `(2,0)`.  
4. Place **4** at `(2,0)` → tentative `(1,1)`.  
5. Place **5** at `(1,1)` → tentative `(0,2)`.  
6. Place **6** at `(0,2)` → tentative `(−1,3)` → wrap `(2,0)` but occupied → move down `(1,2)`.  
7. Place **7** at `(1,2)` → tentative `(0,3)` → wrap `(0,0)`.  
8. Place **8** at `(0,0)` → tentative `(−1,1)` → wrap `(2,1)`.  
9. Place **9** at `(2,1)` → Done.  

Final Square (Magic Sum = 15):

