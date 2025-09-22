# Bubble Sort of Student Marks in C

## 📌 Overview

This program sorts student records based on their **last year marks** in descending order using **Bubble Sort**.  
- The program prints the array after each swap to show the sorting process.  
- Dynamic memory allocation is used for storing student records.  


---

## 📌 Algorithm

1. Start  
2. Input `n_Svj` (number of students).  
3. Allocate memory for `st_Svj[n_Svj]`.  
4. Assign random **names** and **marks** to each student.  
5. Assign roll numbers sequentially.  
6. Call `bubbleSort_Svj(st_Svj, n_Svj)`.  
7. In `bubbleSort_Svj`:
   - Compare adjacent students' `last_year_marks_Svj`.  
   - Swap if left student has lower marks than right.  
   - After each swap, print the current array.  
8. Print final sorted list with name, marks, and roll number.  
9. Free allocated memory.  
10. End.

---

## 📌 Pseudocode
```
START

Input n_Svj
Allocate st_Svj[n_Svj]

FOR i_Svj = 0 to n_Svj-1
Assign random name_Svj
Assign random last_year_marks_Svj
Assign roll_no_Svj = i_Svj + 1
END FOR

CALL bubbleSort_Svj(st_Svj, n_Svj)

FUNCTION bubbleSort_Svj(st_Svj, n_Svj)
FOR i_Svj = 0 to n_Svj-1
FOR j_Svj = 0 to n_Svj-i_Svj-2
IF st_Svj[j_Svj].last_year_marks_Svj < st_Svj[j_Svj+1].last_year_marks_Svj
Swap st_Svj[j_Svj] and st_Svj[j_Svj+1]
Print current array
END IF
END FOR
END FOR
Print final sorted array
END FUNCTION

Free st_Svj

END
```

---

## 📌 Dry Run Example

### Input:
```
Number of students = 5  
Randomly assigned marks:  
Abir: 45, Aarav: 78, Isha: 12, Rohan: 90, Priya: 56
```

### Sorting Steps:

1. Compare Abir(45) & Aarav(78) → swap → `[78, 45, 12, 90, 56]`  
2. Compare 45 & 12 → no swap  
3. Compare 12 & 90 → swap → `[78, 45, 90, 12, 56]`  
4. Compare 12 & 56 → swap → `[78, 45, 90, 56, 12]`  
5. Next pass: Compare 78 & 45 → no swap, 45 & 90 → swap → `[78, 90, 45, 56, 12]`  
6. Repeat until array is sorted: `[90, 78, 56, 45, 12]`  

### Output:
```
Final Sorted List:  
Name: Rohan || Marks Obtained: 90 || Roll No: 4
Name: Aarav || Marks Obtained: 78 || Roll No: 2
Name: Priya || Marks Obtained: 56 || Roll No: 5
Name: Abir || Marks Obtained: 45 || Roll No: 1
Name: Isha || Marks Obtained: 12 || Roll No: 3

```
---

## 📌 C Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50

struct student_Svj{
    char name_Svj[NAME_LEN];
    int last_year_marks_Svj;
    int roll_no_Svj;
};

void bubbleSort_Svj(struct student_Svj* st_Svj, int n_Svj);

int main(){

    int n_Svj, i_Svj;
    printf("Enter the total no. of students in your class: ");
    scanf("%d", &n_Svj);

    struct student_Svj* st_Svj = (struct student_Svj*)malloc(sizeof(struct student_Svj) * n_Svj);
    if(st_Svj == NULL){
        printf("memory allocation failed");
        exit (-1);
    }

    const char* names_Svj[] = { "Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil","Anaya","Dev","Kriti",
        "Mira","Kabir","Tanvi","Yash","Riya","Arjun","Asha","Nikhil","Pooja","Kunal", "Vishal","Amir","Sharukh","Salman","Mrunal","Kirti" };
    int name_size_Svj = sizeof(names_Svj) / sizeof(names_Svj[0]);
    
    for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
        strcpy(st_Svj[i_Svj].name_Svj, names_Svj[rand() % name_size_Svj]);
        st_Svj[i_Svj].last_year_marks_Svj = rand() % 100;
        st_Svj[i_Svj].roll_no_Svj = i_Svj + 1;
    }

    bubbleSort_Svj(st_Svj, n_Svj);
    
    free(st_Svj);
    return 0;
}

void bubbleSort_Svj(struct student_Svj* st_Svj, int n_Svj){
    int i_Svj, j_Svj;
    struct student_Svj temp_Svj;
    for(i_Svj=0; i_Svj<n_Svj-1; i_Svj++){
        for(j_Svj=0; j_Svj<n_Svj-i_Svj-1; j_Svj++){
            if(st_Svj[j_Svj].last_year_marks_Svj < st_Svj[j_Svj+1].last_year_marks_Svj){
                temp_Svj = st_Svj[j_Svj];
                st_Svj[j_Svj] = st_Svj[j_Svj+1];
                st_Svj[j_Svj+1] = temp_Svj;
                for (int k_Svj = 0; k_Svj < n_Svj; k_Svj++) {
                    printf("Name: %s | Marks: %d |\n", st_Svj[k_Svj].name_Svj, st_Svj[k_Svj].last_year_marks_Svj);
                }
                printf("-------------------------------------------------\n");
            }
        }
    }
    for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
        printf("\nName: %s || Marks Obtained: %d || Roll No: %d\n\n",
               st_Svj[i_Svj].name_Svj, st_Svj[i_Svj].last_year_marks_Svj, st_Svj[i_Svj].roll_no_Svj);
    }
}
```