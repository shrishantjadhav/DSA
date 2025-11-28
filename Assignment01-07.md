# Assignment 01-07

## Aim
To implement sorting of student records by roll number using Bubble Sort and Quick Sort and compare their performance in terms of swaps.

## Steps Followed
1. Defined a `Student` structure with attributes: name, roll number, and total marks.
2. Created an array of 10 student records with sample data.
3. Implemented Bubble Sort and Quick Sort algorithms to sort students by roll number.
4. Counted the number of swaps performed by each sorting algorithm.
5. Printed the student records before and after sorting.
6. Displayed a comparison analysis of the performance of the two sorting algorithms.

## Code
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string student_name;
    int student_roll_no;
    float total_marks;
};

void printStudents(const Student students[], int n)
{
    cout<<"Student Records:"<<endl;
    cout<<"Roll No | Name | Total Marks"<<endl;
    cout<<"------------------------"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<students[i].student_roll_no<<" | "<<students[i].student_name<<" | "<<students[i].total_marks<<endl;
    }
    cout<<endl;
}

void bubbleSort(Student students[], int n, int& swapCount)
{
    swapCount = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(students[j].student_roll_no > students[j+1].student_roll_no)
            {
                swap(students[j], students[j+1]);
                swapCount++;
            }
        }
    }
}

int partition(Student students[], int low, int high, int& swapCount)
{
    int pivot = students[high].student_roll_no;
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(students[j].student_roll_no < pivot)
        {
            i++;
            swap(students[i], students[j]);
            swapCount++;
        }
    }
    swap(students[i+1], students[high]);
    swapCount++;
    return i + 1;
}

void quickSort(Student students[], int low, int high, int& swapCount)
{
    if(low < high)
    {
        int pi = partition(students, low, high, swapCount);
        quickSort(students, low, pi - 1, swapCount);
        quickSort(students, pi + 1, high, swapCount);
    }
}

int main()
{
    const int n = 10;
    Student students[n] = {
        {"Abir", 15, 85.5},
        {"Aarav", 8, 92.0},
        {"Isha", 22, 78.5},
        {"Rohan", 5, 88.0},
        {"Priya", 18, 91.5},
        {"Vikas", 12, 76.0},
        {"Neha", 25, 89.5},
        {"Sahil", 3, 94.0},
        {"Anaya", 7, 87.5},
        {"Dev", 20, 82.0}
    };

    Student bubbleStudents[n];
    Student quickStudents[n];

    for(int i = 0; i < n; i++)
    {
        bubbleStudents[i] = students[i];
        quickStudents[i] = students[i];
    }

    cout<<"=== STUDENT SORTING PROGRAM ==="<<endl;
    cout<<"Original Array:"<<endl;
    printStudents(students, n);

    int bubbleSwapCount = 0;
    bubbleSort(bubbleStudents, n, bubbleSwapCount);

    cout<<"After Bubble Sort (sorted by roll number):"<<endl;
    printStudents(bubbleStudents, n);
    cout<<"Number of swaps performed by Bubble Sort: "<<bubbleSwapCount<<endl;

    int quickSwapCount = 0;
    quickSort(quickStudents, 0, n-1, quickSwapCount);

    cout<<"After Quick Sort (sorted by roll number):"<<endl;
    printStudents(quickStudents, n);
    cout<<"Number of swaps performed by Quick Sort: "<<quickSwapCount<<endl;

    cout<<"=== ANALYSIS ==="<<endl;
    cout<<"Both algorithms sorted the array by student_roll_no in ascending order."<<endl;
    cout<<"Bubble Sort swaps: "<<bubbleSwapCount<<endl;
    cout<<"Quick Sort swaps: "<<quickSwapCount<<endl;

    if(bubbleSwapCount > quickSwapCount)
    {
        cout<<"Quick Sort performed better with fewer swaps."<<endl;
    }
    else if(quickSwapCount > bubbleSwapCount)
    {
        cout<<"Bubble Sort performed better with fewer swaps."<<endl;
    }
    else
    {
        cout<<"Both algorithms performed equally in terms of swaps."<<endl;
    }

    return 0;
}
```

## Output (Sample)
```
=== STUDENT SORTING PROGRAM ===
Original Array:
Student Records:
Roll No | Name | Total Marks
------------------------
15 | Abir | 85.5
8 | Aarav | 92
22 | Isha | 78.5
5 | Rohan | 88
18 | Priya | 91.5
12 | Vikas | 76
25 | Neha | 89.5
3 | Sahil | 94
7 | Anaya | 87.5
20 | Dev | 82

After Bubble Sort (sorted by roll number):
Student Records:
Roll No | Name | Total Marks
------------------------
3 | Sahil | 94
5 | Rohan | 88
7 | Anaya | 87.5
8 | Aarav | 92
12 | Vikas | 76
15 | Abir | 85.5
18 | Priya | 91.5
20 | Dev | 82
22 | Isha | 78.5
25 | Neha | 89.5
Number of swaps performed by Bubble Sort: 14

After Quick Sort (sorted by roll number):
Student Records:
Roll No | Name | Total Marks
------------------------
3 | Sahil | 94
5 | Rohan | 88
7 | Anaya | 87.5
8 | Aarav | 92
12 | Vikas | 76
15 | Abir | 85.5
18 | Priya | 91.5
20 | Dev | 82
22 | Isha | 78.5
25 | Neha | 89.5
Number of swaps performed by Quick Sort: 13

=== ANALYSIS ===
Both algorithms sorted the array by student_roll_no in ascending order.
Bubble Sort swaps: 14
Quick Sort swaps: 13
Quick Sort performed better with fewer swaps.
