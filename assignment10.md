# Employee Records Sorting using Selection Sort and Merge Sort in C

## 📌 Overview

This program demonstrates sorting employee records based on the **average of height and weight**.  
It uses **Selection Sort** and **Merge Sort** algorithms and dynamically allocates memory for employee records.  

Each employee has the following details:  
- Name  
- Height  
- Weight  
- Average of Height and Weight  

---

## 📌 Algorithm

**Selection Sort Algorithm**  
1. Traverse the array to find the minimum average value.  
2. Swap it with the first unsorted element.  
3. Repeat for all elements until sorted.  

**Merge Sort Algorithm**  
1. Divide the array into two halves.  
2. Recursively sort the left and right halves.  
3. Merge the two sorted halves to form the final sorted array.  

---

## 📌 Pseudocode
```
START

Input number of employees: n

Allocate memory for n employees

FOR i = 0 to n-1
Input Name, Height, Weight
Calculate Average = (Height + Weight)/2
END FOR

PRINT all employee details

// SELECTION SORT
FOR i = 0 to n-1
Find employee with minimum average in remaining array
Swap with current employee
END FOR
PRINT sorted employee details

// MERGE SORT
FUNCTION mergeSort(start, end)
IF start < end
mid = (start + end)/2
mergeSort(start, mid-1)
mergeSort(mid+1, end)
merge(start, mid, end)
END IF
END FUNCTION
PRINT sorted employee details

Free allocated memory

END
```


---

## 📌 Dry Run Example

### Input:
```
Number of employees: 3
Employee Details:
Name: Abir, Height: 160, Weight: 70
Name: Aarav, Height: 150, Weight: 80
Name: Isha, Height: 170, Weight: 60
```


### Step 1: Calculate Average
```
Abir → (160+70)/2 = 115
Aarav → (150+80)/2 = 115
Isha → (170+60)/2 = 115
```

### Step 2: Selection Sort
- Array is already sorted based on average → No swaps required.  

### Step 3: Merge Sort
- Divide array into halves  
- Merge sorted halves → Array remains the same  

### Output:
```
Name: Abir || Height: 160 || Weight: 70 || Average: 115
Name: Aarav || Height: 150 || Weight: 80 || Average: 115
Name: Isha || Height: 170 || Weight: 60 || Average: 115
```

---

## 📌 C Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50

struct employee_Svj{
    char name_Svj[NAME_LEN];
    int height_Svj;
    int weight_Svj;
    int average_Svj;
};

void selectionSort_Svj(struct employee_Svj*, int);
void mergeSort_Svj(struct employee_Svj*, int, int);
void merge_Svj(struct employee_Svj*, int, int, int);

int main(){
    int n_Svj, i_Svj, start_Svj = 0;
    int* avg_Svj;

    printf("Enter the number of employee details you want: ");
    scanf("%d", &n_Svj);

    const char* names_Svj[] = { "Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil","Anaya","Dev","Kriti",
        "Mira","Kabir","Tanvi","Yash","Riya","Arjun","Asha","Nikhil","Pooja","Kunal", "Vishal","Amir","Sharukh","Salman","Mrunal","Kirti" };
    int name_size_Svj = sizeof(names_Svj) / sizeof(names_Svj[0]);

    struct employee_Svj* emp_Svj = (struct employee_Svj*)malloc(sizeof(struct employee_Svj) * n_Svj);
    avg_Svj = (int*)malloc(sizeof(int) * n_Svj);

    for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
        strcpy(emp_Svj[i_Svj].name_Svj, names_Svj[rand() % name_size_Svj]);
        emp_Svj[i_Svj].height_Svj = rand() % (180 - 150 + 1) + 150;
        emp_Svj[i_Svj].weight_Svj = rand() % (100 - 60 + 1) + 60;
        emp_Svj[i_Svj].average_Svj = (emp_Svj[i_Svj].height_Svj + emp_Svj[i_Svj].weight_Svj) / 2;
    }

    printf("\nOriginal Employee Records:\n");
    for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
        printf("Name: %s || Height: %d || Weight: %d || Average: %d\n",
               emp_Svj[i_Svj].name_Svj, emp_Svj[i_Svj].height_Svj, emp_Svj[i_Svj].weight_Svj, emp_Svj[i_Svj].average_Svj);
    }

    printf("\n------- SELECTION SORT ----------\n");
    selectionSort_Svj(emp_Svj, n_Svj);

    printf("\n--------- MERGE SORT -----------\n");
    mergeSort_Svj(emp_Svj, start_Svj, n_Svj);
    for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
        printf("Name: %s || Height: %d || Weight: %d || Average: %d\n",
               emp_Svj[i_Svj].name_Svj, emp_Svj[i_Svj].height_Svj, emp_Svj[i_Svj].weight_Svj, emp_Svj[i_Svj].average_Svj);
    }

    free(emp_Svj);
    free(avg_Svj);
    return 0;
}

void selectionSort_Svj(struct employee_Svj* emp_Svj, int n_Svj){
    int i_Svj, j_Svj, minIndex_Svj;
    struct employee_Svj temp_Svj;

    for(i_Svj=0; i_Svj<n_Svj-1; i_Svj++){
        minIndex_Svj = i_Svj;
        for(j_Svj=i_Svj+1; j_Svj<n_Svj; j_Svj++){
            if(emp_Svj[j_Svj].average_Svj < emp_Svj[minIndex_Svj].average_Svj){
                minIndex_Svj = j_Svj;
            }
        }
        temp_Svj = emp_Svj[i_Svj];
        emp_Svj[i_Svj] = emp_Svj[minIndex_Svj];
        emp_Svj[minIndex_Svj] = temp_Svj;
    }

    for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
        printf("Name: %s || Height: %d || Weight: %d || Average: %d\n",
               emp_Svj[i_Svj].name_Svj, emp_Svj[i_Svj].height_Svj, emp_Svj[i_Svj].weight_Svj, emp_Svj[i_Svj].average_Svj);
    }
}

void mergeSort_Svj(struct employee_Svj* emp_Svj, int start_Svj, int end_Svj){
    int mid_Svj = (start_Svj + end_Svj) / 2;

    if(start_Svj < end_Svj){
        mergeSort_Svj(emp_Svj, start_Svj, mid_Svj-1);
        mergeSort_Svj(emp_Svj, mid_Svj+1, end_Svj);
        merge_Svj(emp_Svj, start_Svj, mid_Svj, end_Svj);
    }
}

void merge_Svj(struct employee_Svj* emp_Svj, int start_Svj, int mid_Svj, int end_Svj){
    int i_Svj, j_Svj, k_Svj;
    int len1_Svj = mid_Svj - start_Svj + 1;
    int len2_Svj = end_Svj - mid_Svj;

    struct employee_Svj* left_Svj = (struct employee_Svj*)malloc(len1_Svj * sizeof(struct employee_Svj));
    struct employee_Svj* right_Svj = (struct employee_Svj*)malloc(len2_Svj * sizeof(struct employee_Svj));

    k_Svj = start_Svj;
    for (i_Svj = 0; i_Svj < len1_Svj; i_Svj++) left_Svj[i_Svj] = emp_Svj[k_Svj++];
    k_Svj = mid_Svj + 1;
    for (j_Svj = 0; j_Svj < len2_Svj; j_Svj++) right_Svj[j_Svj] = emp_Svj[k_Svj++];

    i_Svj = j_Svj = 0;
    k_Svj = start_Svj;
    while(i_Svj < len1_Svj && j_Svj < len2_Svj){
        if(left_Svj[i_Svj].average_Svj <= right_Svj[j_Svj].average_Svj) emp_Svj[k_Svj++] = left_Svj[i_Svj++];
        else emp_Svj[k_Svj++] = right_Svj[j_Svj++];
    }

    while(i_Svj < len1_Svj) emp_Svj[k_Svj++] = left_Svj[i_Svj++];
    while(j_Svj < len2_Svj) emp_Svj[k_Svj++] = right_Svj[j_Svj++];

    free(left_Svj);
    free(right_Svj);
}
```