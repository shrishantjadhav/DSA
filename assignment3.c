#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 32
#define DIV_LEN 10
#define BRANCH_LEN 32
#define CITY_LEN 15
#define CLASS_LEN 32


typedef struct Student {
    int roll;
    char name[NAME_LEN];
    char div[DIV_LEN];
    char branch[BRANCH_LEN];
    char classs[CLASS_LEN];
    char city[CITY_LEN];
}Student;

int main(void) {

    int n, i;
    int choice;
    printf("Enter the number of records you want: ");
    scanf("%d", &n);

    Student* st = NULL;
    st = (Student*)malloc(sizeof(Student) * n);
    if (st == NULL) {
        printf("Memory allocation failed!");
        exit(-1);
    }

    const char* names[] = { "Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil","Anaya","Dev","Kriti",
        "Mira","Kabir","Tanvi","Yash","Riya","Arjun","Asha","Nikhil","Pooja","Kunal", "Vishal","Amir","Sharukh","Salman","Mrunal","Kirti" };
    const int name_size = (int)(sizeof(names) / sizeof(names[0]));

    const char* cities[] = { "Amravati","Akola","Nagar","Pune","Mumbai","Nashik","Nagpur","Aurangabad","Thane","Satara","Solapur","Kolhapur","Nanded" };
    const int city_size = (int)(sizeof(cities) / sizeof(cities[0]));

    const char* branches[] = { "COMP","IT","AIDS","ENTC","MECH","CIVIL", "AIML", "IOT" };
    const int branch_size = (int)(sizeof(branches) / sizeof(branches[0]));

    const char* division[] = { "A","B","C","D" };
    const int div_size = (int)(sizeof(division) / sizeof(division[0]));

    const char* classes[] = { "FE","SE","TE","BE" };
    const int class_size = (int)(sizeof(classes) / sizeof(classes[0]));

    for (i = 0; i < n; i++) {
        strcpy(st[i].name, names[rand() % name_size]);
        strcpy(st[i].classs, classes[rand() % class_size]);
        strcpy(st[i].div, division[rand() % div_size]);
        strcpy(st[i].city, cities[rand() % city_size]);
        strcpy(st[i].branch, branches[rand() % branch_size]);
        st[i].roll = i + 1;
    }
    printf("\n\n---------------------All records---------------------\n\n");
    for (i = 0; i < n; i++) {
        printf("\n\nRoll No: %d | Name: %s | Class: %s | Branch: %s | Division: %s | City: %s", st[i].roll, st[i].name, st[i].classs, st[i].branch, st[i].div, st[i].city);
    }

    while (choice != 0) {
        printf("\n\n1)Search by name: \n2)Search by roll no. \n3)Print all records \n0)Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
            exit(0);
            break;

            case 1:
            char targetName[NAME_LEN];
            printf("Enter the name you want to search (*case sensitive*): ");
            scanf("%s", &targetName);
            for (i = 0; i < n; i++) {
                if (strcmp(st[i].name, targetName) == 0) {
                    printf("\n\nRoll No: %d | Name: %s | Class: %s | Branch: %s | Division: %s | City: %s", st[i].roll, st[i].name, st[i].classs, st[i].branch, st[i].div, st[i].city);
                }

            }
            break;

            case 2:
            int targetNo;
            printf("Enter the number you want to search: ");
            scanf("%d", &targetNo);
            for (i=0; i<n; i++){
                if (st[i].roll == targetNo){
                    printf("\n\nRoll No: %d | Name: %s | Class: %s | Branch: %s | Division: %s | City: %s", st[i].roll, st[i].name, st[i].classs, st[i].branch, st[i].div, st[i].city);
                }
            }
            break;

            case 3:
            for(i=0; i<n; i++){
                 printf("\n\nRoll No: %d | Name: %s | Class: %s | Branch: %s | Division: %s | City: %s", st[i].roll, st[i].name, st[i].classs, st[i].branch, st[i].div, st[i].city);
            }
            break;

            default:
            printf("Enter correct choice.");
            break;

        }
    }
    free(st);
    return 0;

}