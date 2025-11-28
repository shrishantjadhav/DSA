# Assignment 01-06

## Aim
To create a student record management system that stores and searches student details including roll number, name, city, class, branch, division, and age.

## Steps Followed
1. Defined a `Student` structure containing all required attributes.
2. Initialized an array of 20 students with random data for various attributes.
3. Created functions to print student details and to search for a student by class, division, name, and roll number.
4. Provided a menu-driven interface to search for a student or display all records.
5. Handled user input and implemented searching logic accordingly.

## Code
```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Student
{
    int roll;
    string name;
    string city;
    string className;
    string branch;
    string div;
    int age;
};

void printStudent(const Student& s)
{
    cout<<"Roll: "<<s.roll<<" | Name: "<<s.name<<" | City: "<<s.city
        <<" | Class: "<<s.className<<" | Branch: "<<s.branch
        <<" | Div: "<<s.div<<" | Age: "<<s.age<<endl;
}

void searchStudent(Student students[], int n, string targetClass, string targetDiv, string targetName, int targetRoll)
{
    cout<<"\nSearching for: Class="<<targetClass<<", Division="<<targetDiv
        <<", Name="<<targetName<<", Roll="<<targetRoll<<endl;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (students[i].className == targetClass &&
            students[i].div == targetDiv &&
            students[i].name == targetName &&
            students[i].roll == targetRoll)
        {
            cout<<"\nSTUDENT FOUND:"<<endl;
            printStudent(students[i]);
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout<<"\nSTUDENT NOT FOUND"<<endl;
    }
}

void printAllStudents(Student students[], int n)
{
    cout<<"\nAll Student Records ("<<n<<"):"<<endl;
    for (int i = 0; i < n; i++)
    {
        printStudent(students[i]);
    }
}

int main()
{
    const int n = 20;
    Student students[n];

    string names[] = {"Abir","Aarav","Isha","Rohan","Priya","Vikas","Neha","Sahil","Anaya","Dev","Kriti",
                     "Mira","Kabir","Tanvi","Yash","Riya","Arjun","Asha","Nikhil","Pooja","Kunal",
                     "Vishal","Amir","Sharukh","Salman","Mrunal","Kirti","Raj","Sneha","XYZ"};

    string cities[] = {"Amravati","Akola","Nagar","Pune","Mumbai","Nashik","Nagpur","Aurangabad","Thane","Satara","Solapur","Kolhapur","Nanded"};

    string classes[] = {"FE","SE","TE","BE"};

    string branches[] = {"COMP","IT","AIDS","ENTC","MECH","CIVIL","AIML","IOT"};

    string divs[] = {"A","B","C","D"};

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        students[i].roll = i + 1;
        students[i].name = names[rand() % (sizeof(names)/sizeof(names[0]))];
        students[i].city = cities[rand() % (sizeof(cities)/sizeof(cities[0]))];
        students[i].className = classes[rand() % (sizeof(classes)/sizeof(classes[0]))];
        students[i].branch = branches[rand() % (sizeof(branches)/sizeof(branches[0]))];
        students[i].div = divs[rand() % (sizeof(divs)/sizeof(divs[0]))];
        students[i].age = 18 + (rand() % 5);
    }

    printAllStudents(students, n);

    string targetClass, targetDiv, targetName;
    int targetRoll;
    int choice;

    do
    {
        cout<<"\n--- MENU ---"<<endl;
        cout<<"1) Search Student"<<endl;
        cout<<"2) Print All Records"<<endl;
        cout<<"0) Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"\nEnter Class (FE/SE/TE/BE): ";
                cin>>targetClass;
                cout<<"Enter Division (A/B/C/D): ";
                cin>>targetDiv;
                cout<<"Enter Name: ";
                cin>>targetName;
                cout<<"Enter Roll Number: ";
                cin>>targetRoll;

                searchStudent(students, n, targetClass, targetDiv, targetName, targetRoll);
                break;

            case 2:
                printAllStudents(students, n);
                break;

            case 0:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice."<<endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
```

## Output (Sample)
```
All Student Records (20):
Roll: 1 | Name: Priya | City: Pune | Class: TE | Branch: MECH | Div: D | Age: 20
Roll: 2 | Name: Kabir | City: Aurangabad | Class: SE | Branch: COMP | Div: A | Age: 22
Roll: 3 | Name: Isha | City: Mumbai | Class: FE | Branch: IT | Div: B | Age: 21
...

--- MENU ---
1) Search Student
2) Print All Records
0) Exit
Enter choice: 1

Enter Class (FE/SE/TE/BE): TE
Enter Division (A/B/C/D): D
Enter Name: Priya
Enter Roll Number: 1

STUDENT FOUND:
Roll: 1 | Name: Priya | City: Pune | Class: TE | Branch: MECH | Div: D | Age: 20

Exiting...
