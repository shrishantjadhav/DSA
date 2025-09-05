/*Write a program to perform string operations without using inbuilt library and functions*/

#include <stdio.h>
#include <string.h>

void main() {
    char name[] = "Shrishant";
    char str[] = "jadhav";
    int len = sizeof(name) / sizeof(name[0]);
    int str_len = (sizeof(str) / sizeof(str[0]))-1;
    printf("Length of the string %s is: %d", name, len-1);

    char copy[20];
    for (int i = 0; i < len; i++) {
        copy[i] = name[i];
    }
    printf("\nThe copied string is: %s", copy);

    char rev[20];
    int i;
    int j=0;
    for (i = len-2; i >=0; i--) {
        rev[j] = name[i];
        j++;
    }
    
    printf("\nThe reversed string is: %s", rev);

    int x = 0;
    int y = 0;
    while (name[x] != '\0') {
        x++;
    }
    while (str[y] != '\0') {
        name[x] = str[y];
        x++;
        y++;
    }
    printf("\nconcatenated string is %s", name);
}