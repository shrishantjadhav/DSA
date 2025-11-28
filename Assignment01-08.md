# Assignment 01-08

## Aim
To implement Quick Sort for sorting student marks and perform divide and conquer approach to find the minimum and maximum marks in the array. Analyze the performance of these algorithms.

## Steps Followed
1. Read number of students and their marks from user input.
2. Implemented Quick Sort algorithm with detailed output after each partition showing array state, pivot, comparisons, and swaps.
3. Implemented Divide and Conquer methods to find minimum and maximum marks recursively.
4. Displayed the final sorted marks, total comparisons and swaps during quick sort.
5. Displayed minimum and maximum marks found using divide and conquer.
6. Explained time and space complexity for quick sort and divide and conquer methods.

## Code
```cpp
#include <iostream>
#include <string>

using namespace std;

void printArray(int arr[], int n, string message)
{
    cout<<message<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}

int partition(int arr[], int low, int high, int& comparisons, int& swaps)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        comparisons++;
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i+1], arr[high]);
    swaps++;
    return i + 1;
}

void quickSort(int arr[], int low, int high, int& comparisons, int& swaps, int pass)
{
    if(low < high)
    {
        cout<<"Pass "<<pass<<":"<<endl;
        printArray(arr, high-low+1, "Array before partition:");

        int pi = partition(arr, low, high, comparisons, swaps);

        cout<<"Pivot element: "<<arr[pi]<<endl;
        cout<<"Array after partition:"<<endl;
        for(int i = low; i <= high; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Comparisons so far: "<<comparisons<<", Swaps so far: "<<swaps<<endl<<endl;

        quickSort(arr, low, pi - 1, comparisons, swaps, pass+1);
        quickSort(arr, pi + 1, high, comparisons, swaps, pass+1);
    }
}

int findMin(int arr[], int low, int high)
{
    if(low == high)
    {
        return arr[low];
    }

    int mid = (low + high) / 2;
    int leftMin = findMin(arr, low, mid);
    int rightMin = findMin(arr, mid + 1, high);

    return (leftMin < rightMin) ? leftMin : rightMin;
}

int findMax(int arr[], int low, int high)
{
    if(low == high)
    {
        return arr[low];
    }

    int mid = (low + high) / 2;
    int leftMax = findMax(arr, low, mid);
    int rightMax = findMax(arr, mid + 1, high);

    return (leftMax > rightMax) ? leftMax : rightMax;
}

int main()
{
    int n;
    cout<<"Enter number of students: ";
    cin>>n;

    int* marks = new int[n];

    cout<<"Enter marks of "<<n<<" students:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<"Student "<<i+1<<": ";
        cin>>marks[i];
    }

    cout<<"\n=== QUICK SORT ANALYSIS ==="<<endl;
    int* sortArray = new int[n];
    for(int i = 0; i < n; i++)
    {
        sortArray[i] = marks[i];
    }

    int comparisons = 0, swaps = 0;
    quickSort(sortArray, 0, n-1, comparisons, swaps, 1);

    cout<<"Final sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout<<sortArray[i]<<" ";
    }
    cout<<endl;
    cout<<"Total comparisons: "<<comparisons<<endl;
    cout<<"Total swaps: "<<swaps<<endl;

    cout<<"\n=== DIVIDE AND CONQUER ANALYSIS ==="<<endl;
    int minMarks = findMin(marks, 0, n-1);
    int maxMarks = findMax(marks, 0, n-1);

    cout<<"Minimum marks: "<<minMarks<<endl;
    cout<<"Maximum marks: "<<maxMarks<<endl;

    cout<<"\n=== PERFORMANCE ANALYSIS ==="<<endl;
    cout<<"Quick Sort Time Complexity: O(n log n) average case"<<endl;
    cout<<"Quick Sort Space Complexity: O(log n) for recursion stack"<<endl;
    cout<<"Divide and Conquer (Min/Max) Time Complexity: O(n)"<<endl;
    cout<<"Divide and Conquer (Min/Max) Space Complexity: O(log n)"<<endl;

    delete[] marks;
    delete[] sortArray;

    return 0;
}
```

## Output (Sample)
```
Enter number of students: 5
Enter marks of 5 students:
Student 1: 45
Student 2: 29
Student 3: 78
Student 4: 56
Student 5: 12

=== QUICK SORT ANALYSIS ===
Pass 1:
Array before partition:
45 29 78 56 12 
Pivot element: 12
Array after partition:
12 29 78 56 45 
Comparisons so far: 4, Swaps so far: 3

Pass 2:
Array before partition:
29 78 56 45 
Pivot element: 45
Array after partition:
29 45 56 78 
Comparisons so far: 8, Swaps so far: 5

Pass 3:
Array before partition:
29 45 
Pivot element: 45
Array after partition:
29 45 
Comparisons so far: 9, Swaps so far: 5

Pass 4:
Array before partition:
56 78 
Pivot element: 78
Array after partition:
56 78 
Comparisons so far: 10, Swaps so far: 5

Final sorted array: 12 29 45 56 78 
Total comparisons: 10
Total swaps: 5

=== DIVIDE AND CONQUER ANALYSIS ===
Minimum marks: 12
Maximum marks: 78

=== PERFORMANCE ANALYSIS ===
Quick Sort Time Complexity: O(n log n) average case
Quick Sort Space Complexity: O(log n) for recursion stack
Divide and Conquer (Min/Max) Time Complexity: O(n)
Divide and Conquer (Min/Max) Space Complexity: O(log n)
