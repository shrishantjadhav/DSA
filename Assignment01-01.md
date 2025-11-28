# Assignment 01-01

## Aim
To implement basic string operations including finding string length, copying a string, reversing a string, and concatenating two strings using character arrays in C++.

## Steps Followed
1. Created functions to calculate the length of a string (`getLength`).
2. Developed a function to copy one string into another (`copyString`).
3. Implemented a function to reverse a string in place (`reverseString`).
4. Wrote a function to concatenate two strings (`concatenateString`).
5. Tested all functions in the `main` by performing string operations on sample strings and printing the results.

## Code
```cpp
#include <iostream>
using namespace std;

int getLength(char ans_str[])
{
    int ans_length = 0;
    while (ans_str[ans_length] != '\0')
    {
        ans_length++;
    }
    return ans_length;
}

void copyString(char ans_destination[], char ans_source[])
{
    int ans_i = 0;
    while (ans_source[ans_i] != '\0')
    {
        ans_destination[ans_i] = ans_source[ans_i];
        ans_i++;
    }
    ans_destination[ans_i] = '\0';
}

void reverseString(char ans_str[])
{
    int ans_length = getLength(ans_str);
    int ans_start = 0;
    int ans_end = ans_length - 1;

    while (ans_start < ans_end)
    {
        char ans_temp = ans_str[ans_start];
        ans_str[ans_start] = ans_str[ans_end];
        ans_str[ans_end] = ans_temp;
        ans_start++;
        ans_end--;
    }
}

void concatenateString(char ans_destination[], char ans_source[])
{
    int ans_destLength = getLength(ans_destination);
    int ans_i = 0;

    while (ans_source[ans_i] != '\0')
    {
        ans_destination[ans_destLength + ans_i] = ans_source[ans_i];
        ans_i++;
    }
    ans_destination[ans_destLength + ans_i] = '\0';
}

int main()
{
    char ans_str1[] = "Hello";
    char ans_str2[] = "World";
    char ans_result[50];

    cout<<"String 1: "<<ans_str1<<endl;
    cout<<"Length: "<<getLength(ans_str1)<<endl;

    cout<<"String 2: "<<ans_str2<<endl;
    cout<<"Length: "<<getLength(ans_str2)<<endl;

    copyString(ans_result, ans_str1);
    cout<<"Copied string: "<<ans_result<<endl;

    reverseString(ans_str1);
    cout<<"Reversed string: "<<ans_str1<<endl;

    char ans_concat1[] = "Hi";
    char ans_concat2[] = "There";
    char ans_concatResult[50];

    copyString(ans_concatResult, ans_concat1);
    concatenateString(ans_concatResult, ans_concat2);
    cout<<"Concatenated: "<<ans_concatResult<<endl;

    return 0;
}
```

## Output
```
String 1: Hello
Length: 5
String 2: World
Length: 5
Copied string: Hello
Reversed string: olleH
Concatenated: HiThere
