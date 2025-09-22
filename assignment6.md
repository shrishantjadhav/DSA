# Student Record Management in C (Dynamic Memory Allocation)

## 📌 Overview

This program manages student records using **dynamic memory allocation**.  
It supports:
- Creating multiple student records dynamically.
- Assigning random names, classes, cities, and branch.
- Searching records by **Roll Number** or **Name**.
- Printing all records.
- Exiting the program.

---

## 📌 Algorithm

1. Start.  
2. Input the number of student records **n_Svj**.  
3. Dynamically allocate memory for **st_Svj[n_Svj]**.  
4. Assign random values to `name_Svj`, `class_Svj`, `city_Svj`, and fixed branch `branch_Svj`.  
5. Assign **roll numbers** sequentially starting from 1.  
6. Print all student records.  
7. Loop until user chooses to exit:  
   - Option 1: Search by **Roll Number** → Print matching record.  
   - Option 2: Search by **Name** → Print matching record.  
   - Option 3: Print all records.  
   - Option 4: Exit program.  
   - Invalid choice → Prompt again.  
8. Free dynamically allocated memory.  
9. End.

---

## 📌 Pseudocode
```
START

Input number of students (n_Svj)

Allocate st_Svj[n_Svj]

FOR i_Svj = 0 to n_Svj-1
Assign random name_Svj from names array
Assign random class_Svj from classes array
Assign random city_Svj from cities array
Assign branch_Svj = "Computer Engineering"
Assign roll_no_Svj = i_Svj + 1
END FOR

Print all student records

WHILE True
Print menu
Input choice_Svj

vbnet
Copy code
SWITCH choice_Svj
    CASE 1:
        Input target_rollNo_Svj
        FOR i_Svj = 0 to n_Svj-1
            IF st_Svj[i_Svj].roll_no_Svj == target_rollNo_Svj
                Print student record
    CASE 2:
        Input target_name_Svj
        FOR i_Svj = 0 to n_Svj-1
            IF st_Svj[i_Svj].name_Svj == target_name_Svj
                Print student record
    CASE 3:
        Print all student records
    CASE 4:
        Exit program
    DEFAULT:
        Print "Enter correct choice!"
END WHILE

Free st_Svj memory

END
```


---

## 📌 Dry Run Example
```
### Input:
Number of students: 3  

Randomly generated records:

| Roll No | Name   | Class | Branch               | City   |
|---------|--------|-------|--------------------|--------|
| 1       | Abir   | SY    | Computer Engineering | Pune   |
| 2       | Priya  | TY    | Computer Engineering | Nashik |
| 3       | Rohan  | B.TECH| Computer Engineering | Mumbai |
```
### Menu Operations:

1. **Search by Roll No = 2**  
   Output: Priya's record  

2. **Search by Name = Rohan**  
   Output: Rohan's record  

3. **Print all records**  
   Output: Prints all 3 records  

4. **Exit**  
   Program terminates.


## 📌 C Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN_Svj 50
#define CLASS_LEN_Svj 50
#define CITY_LEN_Svj 50
#define BRANCH_LEN_Svj 50

struct Student_Svj{
    char name_Svj[NAME_LEN_Svj];
    char class_Svj[CLASS_LEN_Svj];
    char city_Svj[CITY_LEN_Svj];
    char branch_Svj[BRANCH_LEN_Svj];
    int roll_no_Svj;
};

int main(){
    int n_Svj, i_Svj;
    int choice_Svj;

    printf("Enter the number of student records you want: ");
    scanf("%d", &n_Svj);

    struct Student_Svj* st_Svj = (struct Student_Svj*)malloc(sizeof(struct Student_Svj) * n_Svj);
    if(st_Svj == NULL){
        printf("Memory allocation failed!!");
    }

    const char* names_Svj[] = { "Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil","Anaya","Dev","Kriti",
        "Mira","Kabir","Tanvi","Yash","Riya","Arjun","Asha","Nikhil","Pooja","Kunal", "Vishal","Amir","Sharukh","Salman","Mrunal","Kirti" };
    int name_size_Svj = sizeof(names_Svj) / sizeof(names_Svj[0]);

    const char* classes_Svj[] = { "SY","TY","B.TECH" };
    int class_size_Svj = sizeof(classes_Svj) / sizeof(classes_Svj[0]);

    const char* cities_Svj[] = { "Amravati","Akola","Nagar","Pune","Mumbai","Nashik","Nagpur","Aurangabad","Thane","Satara","Solapur","Kolhapur","Nanded" };
    int city_size_Svj = sizeof(cities_Svj) / sizeof(cities_Svj[0]);
    
    const char* branches_Svj = "Computer Engineering";
    
    for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
        strcpy(st_Svj[i_Svj].name_Svj, names_Svj[rand() % name_size_Svj]);
        strcpy(st_Svj[i_Svj].class_Svj, classes_Svj[rand() % class_size_Svj]);
        strcpy(st_Svj[i_Svj].city_Svj, cities_Svj[rand() % city_size_Svj]);
        strcpy(st_Svj[i_Svj].branch_Svj, branches_Svj);
        st_Svj[i_Svj].roll_no_Svj = i_Svj + 1;
    }

    printf("\n-----------------ALL RECORDS-----------------\n\n");
    for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
        printf("Name: %s || Roll No: %d || Class: %s || Branch: %s || City: %s\n\n", 
               st_Svj[i_Svj].name_Svj, st_Svj[i_Svj].roll_no_Svj, st_Svj[i_Svj].class_Svj, st_Svj[i_Svj].branch_Svj, st_Svj[i_Svj].city_Svj);
    }

    while (1){

        printf("\n----------FIND BY----------\n\n");
        printf(" 1)Roll No\n 2)Name\n 3)Print all records\n 4)Exit\n ");
        printf("\n------------------------------\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice_Svj);
        
        switch(choice_Svj){
            case 1:
            {
                int target_rollNo_Svj;
                printf("\nEnter the roll number you want to search: ");
                scanf("%d", &target_rollNo_Svj);
                for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
                    if (st_Svj[i_Svj].roll_no_Svj == target_rollNo_Svj){
                        printf("Name: %s || Roll No: %d || Class: %s || Branch: %s || City: %s\n\n", 
                               st_Svj[i_Svj].name_Svj, st_Svj[i_Svj].roll_no_Svj, st_Svj[i_Svj].class_Svj, st_Svj[i_Svj].branch_Svj, st_Svj[i_Svj].city_Svj);
                    }
                }
            }
            break;

            case 2:
            {
                char target_name_Svj[NAME_LEN_Svj];
                printf("Enter the name you want to search (case sensitive!!): ");
                scanf("%s", target_name_Svj);

                for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
                    if(strcmp(st_Svj[i_Svj].name_Svj, target_name_Svj) == 0){
                        printf("Name: %s || Roll No: %d || Class: %s || Branch: %s || City: %s\n\n", 
                               st_Svj[i_Svj].name_Svj, st_Svj[i_Svj].roll_no_Svj, st_Svj[i_Svj].class_Svj, st_Svj[i_Svj].branch_Svj, st_Svj[i_Svj].city_Svj);
                    }
                }
            }
            break;

            case 3:
            for(i_Svj=0; i_Svj<n_Svj; i_Svj++){
                printf("Name: %s || Roll No: %d || Class: %s || Branch: %s || City: %s\n\n", 
                       st_Svj[i_Svj].name_Svj, st_Svj[i_Svj].roll_no_Svj, st_Svj[i_Svj].class_Svj, st_Svj[i_Svj].branch_Svj, st_Svj[i_Svj].city_Svj);
            }
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("\n\nEnter correct choice!\n");
        }
    }

    free(st_Svj);
    return 0;
}
```