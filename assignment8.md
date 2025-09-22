# Quick Sort of Student Marks in C

## 📌 Overview

This program demonstrates **Quick Sort** on dynamically allocated array of **student marks**.  
- It prints the array before sorting, during each swap, and after sorting.  
- Dynamic memory allocation is used for storing marks.  


---

## 📌 Algorithm

1. Start  
2. Input `size_Svj` (number of marks).  
3. Allocate memory for `marks_Svj[size_Svj]`.  
4. Generate random marks in the range 0–99.  
5. Print the array before sorting.  
6. Call `quickSort_Svj` with parameters: `marks_Svj, start_Svj = 0, end_Svj = size_Svj-1, size_Svj`.  
7. In `quickSort_Svj`:
   - If `start_Svj < end_Svj`:
     - Call `partition_Svj` to find pivot index.  
     - Recursively sort left and right subarrays.  
8. In `partition_Svj`:
   - Select pivot as last element.  
   - Place elements smaller than pivot to the left, larger to the right.  
   - Swap elements using `swap_Svj`.  
   - Return pivot index.  
9. In `swap_Svj`:
   - Swap two elements.  
   - Print current array state.  
10. Print sorted array.  
11. Free allocated memory.  
12. End.

---

## 📌 Pseudocode
```
START

Input size_Svj
Allocate marks_Svj[size_Svj]

FOR i_Svj = 0 to size_Svj-1
marks_Svj[i_Svj] = random number % 100
END FOR

Print marks_Svj (Before Sorting)

CALL quickSort_Svj(marks_Svj, 0, size_Svj-1, size_Svj)

FUNCTION quickSort_Svj(marks_Svj, start_Svj, end_Svj, size_Svj)
IF start_Svj < end_Svj
pivotIdx_Svj = partition_Svj(marks_Svj, start_Svj, end_Svj, size_Svj)
quickSort_Svj(marks_Svj, start_Svj, pivotIdx_Svj-1, size_Svj)
quickSort_Svj(marks_Svj, pivotIdx_Svj+1, end_Svj, size_Svj)
END IF
END FUNCTION

FUNCTION partition_Svj(marks_Svj, start_Svj, end_Svj, size_Svj)
pivot_Svj = marks_Svj[end_Svj]
idx_Svj = start_Svj - 1
FOR j_Svj = start_Svj to end_Svj-1
IF marks_Svj[j_Svj] <= pivot_Svj
idx_Svj++
swap_Svj(marks_Svj[j_Svj], marks_Svj[idx_Svj])
END IF
END FOR
idx_Svj++
swap_Svj(marks_Svj[idx_Svj], marks_Svj[end_Svj])
RETURN idx_Svj
END FUNCTION

FUNCTION swap_Svj(a_Svj, b_Svj)
Swap values
Print current array
END FUNCTION

Print marks_Svj (After Sorting)

Free marks_Svj

END
```
---

## 📌 Dry Run Example

### Input:
Number of marks = 5  
Random marks generated: `45, 78, 12, 90, 56`

### Sorting Steps (Quick Sort):

1. Pivot = 56  
   - Partition: `[45, 12, 56, 90, 78]`  
2. Left subarray `[45, 12]` pivot = 12  
   - Partition: `[12, 45]`  
3. Right subarray `[90, 78]` pivot = 78  
   - Partition: `[78, 90]`  

### Output:

Before quick sort:  
`45 78 12 90 56`  

During sorting (after each swap):  
45 78 12 90 56
45 12 78 90 56
12 45 78 90 56
12 45 78 90 56
12 45 56 90 78
12 45 56 78 90



After quick sort:  
`12 45 56 78 90`

---

## 📌 C Program

```c
#include <stdio.h>
#include<stdlib.h>

void quickSort_Svj(int* marks_Svj, int start_Svj, int end_Svj, int size_Svj);
int partition_Svj(int* marks_Svj, int start_Svj, int end_Svj, int size_Svj);
void swap_Svj(int* a_Svj, int* b_Svj, int* marks_Svj, int size_Svj);

int main(){
    int size_Svj, i_Svj, start_Svj = 0;
    int* marks_Svj;

    printf("Enter the number of student marks to be sorted: ");
    scanf("%d" , &size_Svj);

    marks_Svj = (int*)malloc(sizeof(int) * size_Svj);
    if (marks_Svj == NULL){
        printf("memory allocation failed");
    }

    for(i_Svj=0; i_Svj<size_Svj; i_Svj++){
        marks_Svj[i_Svj] = rand() % 100 ;
    }

    printf("\nbefore quick sort:\n");
    for(i_Svj=0; i_Svj<size_Svj; i_Svj++){
        printf("%d\t", marks_Svj[i_Svj]);
    }

    printf("\n\n--- Sorting Steps ---\n");
    quickSort_Svj(marks_Svj, start_Svj, size_Svj-1, size_Svj );

    printf("\nAfter quick sort\n");
    for(i_Svj=0; i_Svj<size_Svj; i_Svj++){
        printf("%d\t", marks_Svj[i_Svj]);
    }

    free(marks_Svj);
    marks_Svj = NULL;
    return 0;
}

void quickSort_Svj(int* marks_Svj, int start_Svj, int end_Svj, int size_Svj){
    int pivotIdx_Svj;

    if(start_Svj < end_Svj){
        pivotIdx_Svj = partition_Svj(marks_Svj, start_Svj, end_Svj, size_Svj);
        quickSort_Svj(marks_Svj, start_Svj, pivotIdx_Svj - 1, size_Svj);
        quickSort_Svj(marks_Svj, pivotIdx_Svj +  1, end_Svj, size_Svj);
    }
}

int partition_Svj(int* marks_Svj, int start_Svj, int end_Svj, int size_Svj){
    int pivot_Svj = marks_Svj[end_Svj];
    int j_Svj, idx_Svj = start_Svj - 1;

    for(j_Svj=start_Svj; j_Svj<end_Svj; j_Svj++){
        if(marks_Svj[j_Svj] <= pivot_Svj){
            idx_Svj++;
            swap_Svj(&marks_Svj[j_Svj], &marks_Svj[idx_Svj], marks_Svj, size_Svj);
        }
    }
    idx_Svj++;
    swap_Svj(&marks_Svj[idx_Svj], &marks_Svj[end_Svj], marks_Svj, size_Svj);
    return idx_Svj;
}

void swap_Svj(int* a_Svj, int* b_Svj, int* marks_Svj, int size_Svj){
    int temp_Svj = *a_Svj;
    *a_Svj = *b_Svj;
    *b_Svj = temp_Svj;

    for (int i_Svj = 0; i_Svj < size_Svj; i_Svj++) {
        printf("%d\t", marks_Svj[i_Svj]);
    }
    printf("\n");
}
```