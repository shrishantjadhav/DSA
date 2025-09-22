# String Operations in C (Without Inbuilt Functions)

## 🖥 Program Code

```c
#include <stdio.h>

void main() {
    char name_Svj[] = "Shrishant";
    char str_Svj[] = "jadhav";
    int len_Svj = sizeof(name_Svj) / sizeof(name_Svj[0]);
    int str_len_Svj = (sizeof(str_Svj) / sizeof(str_Svj[0]))-1;
    printf("Length of the string %s is: %d", name_Svj, len_Svj-1);

    char copy_Svj[20];
    for (int i_Svj = 0; i_Svj < len_Svj; i_Svj++) {
        copy_Svj[i_Svj] = name_Svj[i_Svj];
    }
    printf("\nThe copied string is: %s", copy_Svj);

    char rev_Svj[20];
    int i_Svj;
    int j_Svj = 0;
    for (i_Svj = len_Svj-2; i_Svj >=0; i_Svj--) {
        rev_Svj[j_Svj] = name_Svj[i_Svj];
        j_Svj++;
    }
    rev_Svj[j_Svj] = '\0';  // Null terminate the reversed string
    printf("\nThe reversed string is: %s", rev_Svj);

    int x_Svj = 0;
    int y_Svj = 0;
    while (name_Svj[x_Svj] != '\0') {
        x_Svj++;
    }
    while (str_Svj[y_Svj] != '\0') {
        name_Svj[x_Svj] = str_Svj[y_Svj];
        x_Svj++;
        y_Svj++;
    }
    name_Svj[x_Svj] = '\0';  // Null terminate the concatenated string
    printf("\nconcatenated string is %s", name_Svj);
}
```
## 📝 Algorithm Explanation

1. **Length Calculation**:
   - Initialize a counter and iterate through the string until the null terminator (`'\0'`) is encountered, incrementing the counter for each character.
    - Using the formula `sizeof(name_Svj) / sizeof(name_Svj[0])` to calculate the length of the string array.
    -Where the name_Svj is the string whose length is to be calculated divided by the size of a single character in the array.

2. **String Copy**:
    - Create a new character array to hold the copied string. 
    - Use a loop which will iterate through each character of the original string and copy it to the new array.
    - Ensure to copy the null terminator at the end of the string.
    - print the copied string.

3. **String Reversal**:
    - Create a new character array to hold the reversed string.
    - Use a loop to iterate through the original string from the last character to the first, copying each character to the new array.
    - Add a null terminator at the end of the reversed string.
    - print the reversed string.

4. **String Concatenation**:
    - Find the end of the first string by iterating through it until the null terminator is found.
    - Start copying characters from the second string to the end of the first string.
    - Add a null terminator at the end of the concatenated string.
    - print the concatenated string.

## Dry run
    -Input: "Shrishant", "jadhav"

    1. **Length Calculation**:
       - Initialize `len_Svj` to 0.
       - Iterate through "Shrishant":
     ```c
         - 'S' -> len_Svj = 1
         - 'h' -> len_Svj = 2
         - 'r' -> len_Svj = 3
         - 'i' -> len_Svj = 4
         - 's' -> len_Svj = 5
         - 'h' -> len_Svj = 6
         - 'a' -> len_Svj = 7
         - 'n' -> len_Svj = 8
         - 't' -> len_Svj = 9
         - '\0' -> Stop iteration.
    ```
       - Final length: 9
         - Output: "Length of the string Shrishant is: 9"

    2. **String Copy**:
        - Initialize `copy_Svj` as an empty array.
        - Iterate through "Shrishant":
        - Copy each character to `copy_Svj`.
    ```c
        - 'S' -> copy_Svj[0] = 'S'
        - 'h' -> copy_Svj[1] = 'h'
        - 'r' -> copy_Svj[2] = 'r'
        - 'i' -> copy_Svj[3] = 'i'
        - 's' -> copy_Svj[4] = 's'
        - 'h' -> copy_Svj[5] = 'h'
        - 'a' -> copy_Svj[6] = 'a'
        - 'n' -> copy_Svj[7] = 'n'
        - 't' -> copy_Svj[8] = 't'
        - '\0' -> copy_Svj[9] = '\0' (null terminator)
    ```
        - Final copied string: "Shrishant"
          - Output: "The copied string is: Shrishant"

    3. **String reversal**
        - Initialize `rev_Svj` as an empty array.
        - Iterate through "Shrishant" from the end to the beginning:
    ```c
        - 't' -> rev_Svj[0] = 't'
        - 'n' -> rev_Svj[1] = 'n'
        - 'a' -> rev_Svj[2] = 'a'
        - 'h' -> rev_Svj[3] = 'h'
        - 's' -> rev_Svj[4] = 's'
        - 'i' -> rev_Svj[5] = 'i'
        - 'r' -> rev_Svj[6] = 'r'
        - 'h' -> rev_Svj[7] = 'h'
        - 'S' -> rev_Svj[8] = 'S'
        - '\0' -> rev_Svj[9] = '\0' (null terminator)
    ```
        - Final reversed string: "tnahsirhS"
          - Output: "The reversed string is: tnahsirhS"

    4. **String Concatenation**:    
        - Start with "Shrishant" and find its end.
        - Append "jadhav" to the end of "Shrishant":
    ```c
        - 'S' -> name_Svj[0] = 'S'
        - 'h' -> name_Svj[1] = 'h'
        - 'r' -> name_Svj[2] = 'r'
        - 'i' -> name_Svj[3] = 'i'
        - 's' -> name_Svj[4] = 's'
        - 'h' -> name_Svj[5] = 'h'
        - 'a' -> name_Svj[6] = 'a'
        - 'n' -> name_Svj[7] = 'n'
        - 't' -> name_Svj[8] = 't'
        - '\0' -> Stop iteration.
        
        - Now append "jadhav":
        - 'j' -> name_Svj[9] = 'j'
        - 'a' -> name_Svj[10] = 'a'
        - 'd' -> name_Svj[11] = 'd'
        - 'h' -> name_Svj[12] = 'h'
        - 'a' -> name_Svj[13] = 'a'
        - 'v' -> name_Svj[14] = 'v'
        - '\0' -> name_Svj[15] = '\0' (null terminator)
    ```
        - Final concatenated string: "Shrishantjadhav"
          - Output: "concatenated string is Shrishantjadhav"