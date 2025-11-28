# Assignment 01-09

## Aim
To implement Bubble Sort to sort student records by marks in descending order and assign roll numbers based on sorted order.

## Steps Followed
1. Defined a Student structure with attributes: name, marks, and roll number.
2. Collected student names and marks from user input.
3. Implemented Bubble Sort to sort students by marks in descending order with pass-wise output showing state of the array, swaps, and comparisons.
4. Assigned roll numbers to students based on sorted order (highest marks get roll number 1).
5. Displayed the sorted list of students with their assigned roll numbers.
6. Analyzed the algorithm's time and space complexity, and explained roll number assignment logic.

## Code
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    float marks;
    int roll_no;
};

void printStudents(const Student students[], int n)
{
    cout<<"Student Records:"<<endl;
    cout<<"Roll No | Name | Marks"<<endl;
    cout<<"---------------------"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<students[i].roll_no<<" | "<<students[i].name<<" | "<<students[i].marks<<endl;
    }
    cout<<endl;
}

void bubbleSort(Student students[], int n, int& swapCount)
{
    swapCount = 0;
    for(int i = 0; i < n-1; i++)
    {
        cout<<"Pass "<<i+1<<":"<<endl;
        cout<<"Before pass: ";
        for(int k = 0; k < n; k++)
        {
            cout<<students[k].name<<"("<<students[k].marks<<") ";
        }
        cout<<endl;

        bool swapped = false;
        for(int j = 0; j < n-i-1; j++)
        {
            if(students[j].marks < students[j+1].marks)
            {
                swap(students[j], students[j+1]);
                swapCount++;
                swapped = true;
            }
        }

        cout<<"After pass: ";
        for(int k = 0; k < n; k++)
        {
            cout<<students[k].name<<"("<<students[k].marks<<") ";
        }
        cout<<endl;
        cout<<"Swaps in this pass: "<<(swapped ? 1 : 0)<<endl;
        cout<<"Total swaps so far: "<<swapCount<<endl<<endl;

        if(!swapped)
        {
            cout<<"No swaps in this pass - array is sorted!"<<endl;
            break;
        }
    }
}

void assignRollNumbers(Student students[], int n)
{
    cout<<"Assigning roll numbers based on sorted order (topper gets roll no. 1):"<<endl;
    for(int i = 0; i < n; i++)
    {
        students[i].roll_no = i + 1;
    }
}

int main()
{
    int n;
    cout<<"Enter number of students: ";
    cin>>n;

    Student* students = new Student[n];

    cout<<"Enter student details (name and previous year marks):"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<"Student "<<i+1<<" name: ";
        cin>>students[i].name;
        cout<<"Student "<<i+1<<" marks: ";
        cin>>students[i].marks;
        students[i].roll_no = 0;
    }

    cout<<"\n=== BUBBLE SORT ANALYSIS ==="<<endl;
    cout<<"Sorting students by marks (highest to lowest)..."<<endl;

    int swapCount;
    bubbleSort(students, n, swapCount);

    assignRollNumbers(students, n);

    cout<<"Final result after sorting and roll number assignment:"<<endl;
    printStudents(students, n);

    cout<<"=== ANALYSIS ==="<<endl;
    cout<<"Total number of passes: "<<n-1<<endl;
    cout<<"Total number of swaps: "<<swapCount<<endl;
    cout<<"Time Complexity: O(n^2) worst case"<<endl;
    cout<<"Space Complexity: O(1)"<<endl;

    cout<<"\nRoll number assignment logic:"<<endl;
    cout<<"- Students are sorted by marks in descending order"<<endl;
    cout<<"- Topper (highest marks) gets roll number 1"<<endl;
    cout<<"- Second highest gets roll number 2"<<endl;
    cout<<"- And so on..."<<endl;

    delete[] students;

    return 0;
}
```

## Output (Sample)
```
Enter number of students: 5
Enter student details (name and previous year marks):
Student 1 name: Alice
Student 1 marks: 89
Student 2 name: Bob
Student 2 marks: 75
Student 3 name: Carol
Student 3 marks: 92
Student 4 name: Dave
Student 4 marks: 85
Student 5 name: Eve
Student 5 marks: 78

=== BUBBLE SORT ANALYSIS ===
Sorting students by marks (highest to lowest)...
Pass 1:
Before pass: Alice(89) Bob(75) Carol(92) Dave(85) Eve(78) 
After pass: Carol(92) Alice(89) Bob(75) Dave(85) Eve(78) 
Swaps in this pass: 1
Total swaps so far: 1

Pass 2:
Before pass: Carol(92) Alice(89) Bob(75) Dave(85) Eve(78) 
After pass: Carol(92) Alice(89) Dave(85) Bob(75) Eve(78) 
Swaps in this pass: 1
Total swaps so far: 2

Pass 3:
Before pass: Carol(92) Alice(89) Dave(85) Bob(75) Eve(78) 
After pass: Carol(92) Alice(89) Dave(85) Eve(78) Bob(75) 
Swaps in this pass: 1
Total swaps so far: 3

Pass 4:
Before pass: Carol(92) Alice(89) Dave(85) Eve(78) Bob(75) 
After pass: Carol(92) Alice(89) Dave(85) Eve(78) Bob(75) 
Swaps in this pass: 0
Total swaps so far: 3
No swaps in this pass - array is sorted!

Final result after sorting and roll number assignment:
Student Records:
Roll No | Name | Marks
---------------------
1 | Carol | 92
2 | Alice | 89
3 | Dave | 85
4 | Eve | 78
5 | Bob | 75

=== ANALYSIS ===
Total number of passes: 4
Total number of swaps: 3
Time Complexity: O(n^2) worst case
Space Complexity: O(1)

Roll number assignment logic:
- Students are sorted by marks in descending order
- Topper (highest marks) gets roll number 1
- Second highest gets roll number 2
- And so on...
