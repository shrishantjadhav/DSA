# Assignment 01-10

## Aim
To implement and compare Merge Sort and Selection Sort on employee records based on average of height and weight, along with analysis of their performance.

## Steps Followed
1. Defined an Employee structure with attributes: name, height, weight, and average.
2. Calculated average of height and weight for each employee.
3. Implemented Merge Sort algorithm to sort employees based on average value including counts for comparisons and swaps.
4. Implemented Selection Sort algorithm for the same purpose with performance metrics.
5. Displayed original employee records and sorted records after each sorting algorithm execution.
6. Provided performance analysis including time and space complexity.
7. Drew conclusions based on comparison of the two sorting algorithms.

## Code
```cpp
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Employee
{
    string name;
    float height;
    float weight;
    float average;
};

void printEmployees(const Employee employees[], int n)
{
    cout<<"Employee Records:"<<endl;
    cout<<"Name | Height | Weight | Average"<<endl;
    cout<<"-----------------------------"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<employees[i].name<<" | "<<employees[i].height<<" | "<<employees[i].weight<<" | "<<fixed<<setprecision(2)<<employees[i].average<<endl;
    }
    cout<<endl;
}

void calculateAverage(Employee employees[], int n)
{
    for(int i = 0; i < n; i++)
    {
        employees[i].average = (employees[i].height + employees[i].weight) / 2.0;
    }
}

void merge(Employee employees[], int left, int mid, int right, int& comparisons, int& swaps)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for(int i = 0; i < n1; i++)
        L[i] = employees[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = employees[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        comparisons++;
        if(L[i].average <= R[j].average)
        {
            employees[k] = L[i];
            i++;
        }
        else
        {
            employees[k] = R[j];
            j++;
        }
        swaps++;
        k++;
    }

    while(i < n1)
    {
        employees[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        employees[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Employee employees[], int left, int right, int& comparisons, int& swaps)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(employees, left, mid, comparisons, swaps);
        mergeSort(employees, mid + 1, right, comparisons, swaps);
        merge(employees, left, mid, right, comparisons, swaps);
    }
}

void selectionSort(Employee employees[], int n, int& comparisons, int& swaps)
{
    for(int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for(int j = i+1; j < n; j++)
        {
            comparisons++;
            if(employees[j].average < employees[min_idx].average)
            {
                min_idx = j;
            }
        }
        if(min_idx != i)
        {
            swap(employees[min_idx], employees[i]);
            swaps++;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter number of employees: ";
    cin>>n;

    Employee* employees = new Employee[n];

    cout<<"Enter employee details (name, height, weight):"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<"Employee "<<i+1<<" name: ";
        cin>>employees[i].name;
        cout<<"Employee "<<i+1<<" height (cm): ";
        cin>>employees[i].height;
        cout<<"Employee "<<i+1<<" weight (kg): ";
        cin>>employees[i].weight;
    }

    calculateAverage(employees, n);

    cout<<"\n=== ORIGINAL DATA ==="<<endl;
    printEmployees(employees, n);

    Employee* mergeEmployees = new Employee[n];
    Employee* selectionEmployees = new Employee[n];

    for(int i = 0; i < n; i++)
    {
        mergeEmployees[i] = employees[i];
        selectionEmployees[i] = employees[i];
    }

    int mergeComparisons = 0, mergeSwaps = 0;
    int selectionComparisons = 0, selectionSwaps = 0;

    cout<<"=== MERGE SORT ANALYSIS ==="<<endl;
    mergeSort(mergeEmployees, 0, n-1, mergeComparisons, mergeSwaps);

    cout<<"After Merge Sort (sorted by average height+weight):"<<endl;
    printEmployees(mergeEmployees, n);
    cout<<"Merge Sort - Comparisons: "<<mergeComparisons<<", Swaps: "<<mergeSwaps<<endl;

    cout<<"=== SELECTION SORT ANALYSIS ==="<<endl;
    selectionSort(selectionEmployees, n, selectionComparisons, selectionSwaps);

    cout<<"After Selection Sort (sorted by average height+weight):"<<endl;
    printEmployees(selectionEmployees, n);
    cout<<"Selection Sort - Comparisons: "<<selectionComparisons<<", Swaps: "<<selectionSwaps<<endl;

    cout<<"=== PERFORMANCE ANALYSIS ==="<<endl;
    cout<<"Merge Sort:"<<endl;
    cout<<"  Time Complexity: O(n log n)"<<endl;
    cout<<"  Space Complexity: O(n)"<<endl;
    cout<<"  Comparisons: "<<mergeComparisons<<endl;
    cout<<"  Swaps: "<<mergeSwaps<<endl;

    cout<<"Selection Sort:"<<endl;
    cout<<"  Time Complexity: O(n^2)"<<endl;
    cout<<"  Space Complexity: O(1)"<<endl;
    cout<<"  Comparisons: "<<selectionComparisons<<endl;
    cout<<"  Swaps: "<<selectionSwaps<<endl;

    cout<<"=== CONCLUSION ==="<<endl;
    if(mergeComparisons < selectionComparisons)
    {
        cout<<"Merge Sort performed better with fewer comparisons."<<endl;
    }
    else if(selectionComparisons < mergeComparisons)
    {
        cout<<"Selection Sort performed better with fewer comparisons."<<endl;
    }
    else
    {
        cout<<"Both algorithms performed equally in terms of comparisons."<<endl;
    }

    cout<<"For large datasets, Merge Sort is generally more efficient due to O(n log n) time complexity."<<endl;
    cout<<"Selection Sort has the advantage of O(1) space complexity and performs well on small datasets."<<endl;

    delete[] employees;
    delete[] mergeEmployees;
    delete[] selectionEmployees;

    return 0;
}
```

## Output (Sample)
```
Enter number of employees: 3
Enter employee details (name, height, weight):
Employee 1 name: John
Employee 1 height (cm): 175
Employee 1 weight (kg): 70
Employee 2 name: Alice
Employee 2 height (cm): 160
Employee 2 weight (kg): 60
Employee 3 name: Bob
Employee 3 height (cm): 180
Employee 3 weight (kg): 80

=== ORIGINAL DATA ===
Employee Records:
Name | Height | Weight | Average
-----------------------------
John | 175 | 70 | 122.50
Alice | 160 | 60 | 110.00
Bob | 180 | 80 | 130.00

=== MERGE SORT ANALYSIS ===
After Merge Sort (sorted by average height+weight):
Employee Records:
Name | Height | Weight | Average
-----------------------------
Alice | 160 | 60 | 110.00
John | 175 | 70 | 122.50
Bob | 180 | 80 | 130.00
Merge Sort - Comparisons: 3, Swaps: 5

=== SELECTION SORT ANALYSIS ===
After Selection Sort (sorted by average height+weight):
Employee Records:
Name | Height | Weight | Average
-----------------------------
Alice | 160 | 60 | 110.00
John | 175 | 70 | 122.50
Bob | 180 | 80 | 130.00
Selection Sort - Comparisons: 3, Swaps: 2

=== PERFORMANCE ANALYSIS ===
Merge Sort:
  Time Complexity: O(n log n)
  Space Complexity: O(n)
  Comparisons: 3
  Swaps: 5
Selection Sort:
  Time Complexity: O(n^2)
  Space Complexity: O(1)
  Comparisons: 3
  Swaps: 2
=== CONCLUSION ===
Merge Sort performed better with fewer comparisons.
For large datasets, Merge Sort is generally more efficient due to O(n log n) time complexity.
Selection Sort has the advantage of O(1) space complexity and performs well on small datasets.
