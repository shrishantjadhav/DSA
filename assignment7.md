# Student Record Sorting in C (Bubble Sort & Quick Sort)

## 📌 Overview

This program demonstrates sorting of **student records** using **Bubble Sort** and **Quick Sort** algorithms.  
Each student record contains:
- Name
- Roll Number
- Total Marks  

The program dynamically allocates memory for student records and performs sorting by **Roll Number**.  


---

## 📌 Algorithm

1. Start  
2. Input the number of student records `n_Svj`.  
3. Allocate memory dynamically for `st_Svj[n_Svj]`.  
4. Assign random **name_Svj**, **roll_no_Svj**, and **total_marks_Svj** to each student.  
5. Print all student records before sorting.  
6. Perform **Bubble Sort**:
   - Compare adjacent records by `student_roll_no_Svj`.
   - Swap if necessary.
   - Count the number of swaps.  
7. Print records after Bubble Sort.  
8. Perform **Quick Sort**:
   - Choose pivot (last element).
   - Partition array into smaller and larger elements.
   - Recursively sort subarrays.  
9. Print records after Quick Sort.  
10. Free dynamically allocated memory.  
11. End.

---

## 📌 Pseudocode
```
START

Input n_Svj
Allocate st_Svj[n_Svj]

FOR i_Svj = 0 to n_Svj-1
st_Svj[i_Svj].student_name_Svj = random name
st_Svj[i_Svj].student_roll_no_Svj = random/assigned roll number
st_Svj[i_Svj].total_marks_Svj = random marks
END FOR

Print all records (Before Sorting)

CALL bubbleSort_Svj(st_Svj, n_Svj)
Print all records (After Bubble Sort)

CALL quickSort_Svj(st_Svj, 0, n_Svj-1)
Print all records (After Quick Sort)

Free memory

END
```
---

## 📌 Dry Run Example

### Input:  
### Number of records: 5  

### Randomly generated records:
```
| Roll No | Name  | Total Marks |
|---------|-------|-------------|
| 10      | Abir  | 75          |
| 3       | Priya | 62          |
| 7       | Rohan | 89          |
| 1       | Isha  | 54          |
| 5       | Neha  | 70          |
```
### Bubble Sort:

- Compare adjacent roll numbers:
  - Swap if left > right
- Number of swaps = 4
- Sorted order after Bubble Sort:
```
| Roll No | Name  | Total Marks |
|---------|-------|-------------|
| 1       | Isha  | 54          |
| 3       | Priya | 62          |
| 5       | Neha  | 70          |
| 7       | Rohan | 89          |
| 10      | Abir  | 75          |
```
### Quick Sort:

- Pivot = last element
- Partition array around pivot
- Recursively sort left and right
- Final sorted order (same as Bubble Sort)

---

## 📌 C Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN_Svj 50

struct student_Svj {
    char student_name_Svj[NAME_LEN_Svj];
    int student_roll_no_Svj;
    int total_marks_Svj;
};

void bubbleSort_Svj(struct student_Svj*, int);
void quickSort_Svj(struct student_Svj*, int, int);
int partition_Svj(struct student_Svj*, int, int);
void swapping_Svj(struct student_Svj*, struct student_Svj*);

int main() {
    int n_Svj, i_Svj;
    int start_Svj = 0; 

    printf("Enter the number of records you want: ");
    scanf("%d", &n_Svj);

    struct student_Svj* st_Svj = (struct student_Svj*)malloc(sizeof(struct student_Svj) * n_Svj);

    if (st_Svj == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }

    char const* names_Svj[] = { "Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil","Anaya","Dev",
                            "Kriti","Mira","Kabir","Tanvi","Yash","Riya","Arjun","Asha","Nikhil","Pooja",
                            "Kunal","Vishal","Amir","Sharukh","Salman","Mrunal","Kirti" };
    int name_size_Svj = sizeof(names_Svj) / sizeof(names_Svj[0]);

    int const roll_no_Svj[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 19, 11, 12, 14, 16, 13, 15, 18, 17};
    int roll_size_Svj = sizeof(roll_no_Svj) / sizeof(roll_no_Svj[0]);

    // Fill student records
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++) {
        strcpy(st_Svj[i_Svj].student_name_Svj, names_Svj[rand() % name_size_Svj]);
        st_Svj[i_Svj].student_roll_no_Svj = roll_no_Svj[i_Svj % roll_size_Svj];
        st_Svj[i_Svj].total_marks_Svj = rand() % 100;
    }

    // Print before sorting
    printf("\n---- Before Sorting ----\n");
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++) {
        printf("Name: %s || Roll no: %d || Total marks: %d\n",
               st_Svj[i_Svj].student_name_Svj, st_Svj[i_Svj].student_roll_no_Svj, st_Svj[i_Svj].total_marks_Svj);
    }

    printf("\n---- After Bubble Sort ----\n");
    bubbleSort_Svj(st_Svj, n_Svj);

    printf("\n---- After Quick Sort ----\n");
    quickSort_Svj(st_Svj, start_Svj, n_Svj-1);
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++) {
        printf("Name: %s || Roll No: %d || Total marks: %d\n",
               st_Svj[i_Svj].student_name_Svj, st_Svj[i_Svj].student_roll_no_Svj, st_Svj[i_Svj].total_marks_Svj);
    }
    free(st_Svj);
    return 0;
}

void bubbleSort_Svj(struct student_Svj* st_Svj, int n_Svj) {
    int i_Svj, j_Svj, count_Svj = 0;
    struct student_Svj temp_Svj;

    for (i_Svj = 0; i_Svj < n_Svj - 1; i_Svj++) {
        for (j_Svj = 0; j_Svj < n_Svj - i_Svj - 1; j_Svj++) {
            if (st_Svj[j_Svj].student_roll_no_Svj > st_Svj[j_Svj+1].student_roll_no_Svj) {
                temp_Svj = st_Svj[j_Svj];
                st_Svj[j_Svj] = st_Svj[j_Svj+1];
                st_Svj[j_Svj+1] = temp_Svj;
                count_Svj++;
            }
        }
    }

    printf("Number of swaps: %d\n", count_Svj);
    for (i_Svj = 0; i_Svj < n_Svj; i_Svj++) {
        printf("Name: %s || Roll No: %d || Total marks: %d\n",
               st_Svj[i_Svj].student_name_Svj, st_Svj[i_Svj].student_roll_no_Svj, st_Svj[i_Svj].total_marks_Svj);
    }
}

void quickSort_Svj(struct student_Svj* st_Svj, int start_Svj, int size_Svj){
    int i_Svj;
    if(start_Svj < size_Svj){
        int pivotIdx_Svj = partition_Svj(st_Svj, start_Svj, size_Svj);
        quickSort_Svj(st_Svj, start_Svj, pivotIdx_Svj-1);
        quickSort_Svj(st_Svj, pivotIdx_Svj+1, size_Svj);
    }
}

int partition_Svj(struct student_Svj* st_Svj, int start_Svj, int size_Svj){
    int idx_Svj = start_Svj-1;
    int pivot_Svj = st_Svj[size_Svj].student_roll_no_Svj;
    for(int j_Svj= start_Svj; j_Svj<size_Svj; j_Svj++){
        if(st_Svj[j_Svj].student_roll_no_Svj <= pivot_Svj){
            idx_Svj++;
            swapping_Svj(&st_Svj[idx_Svj], &st_Svj[j_Svj]);
        }
    }
    idx_Svj++;
    swapping_Svj(&st_Svj[idx_Svj], &st_Svj[size_Svj]);
    return idx_Svj;
}

void swapping_Svj(struct student_Svj* a_Svj, struct student_Svj* b_Svj){
    struct student_Svj temp_Svj = *a_Svj;
    *a_Svj = *b_Svj; 
    *b_Svj = temp_Svj;
}
```