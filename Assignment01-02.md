# Assignment 01-02

## Aim
To create a Magic Square of order n, where n is a positive odd integer, and verify the magic sum properties.

## Steps Followed
1. Take input from the user for the order `n` of the magic square.
2. Validate that `n` is positive and odd.
3. Dynamically allocate a 2D array for the magic square.
4. Initialize the matrix with zeros.
5. Use the Siamese method (or De la Loubere's method) to fill the magic square:
   - Start from the middle of first row.
   - Place numbers from 1 to `n*n`.
   - Move up and right to place next number.
   - If the new cell is already filled, move down one cell instead.
6. Display the filled magic square.
7. Calculate and display the magic sum.
8. Deallocate the dynamic memory.

## Code
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int** ans_magicSquare = NULL;
    int ans_n, ans_num;
    int ans_row, ans_col, ans_nextRow, ans_nextCol;
    int ans_i, ans_j;

    cout << "Enter the value of n: ";
    cin >> ans_n;

    if (ans_n <= 0 || ans_n % 2 == 0)
    {
        cout << "Error: n must be positive Odd Number." << endl;
        return -1;
    }

    ans_magicSquare = new int*[ans_n];

    if (ans_magicSquare == NULL)
    {
        cout << "Memory allocation failed." << endl;
        return -2;
    }

    for (ans_i = 0; ans_i < ans_n; ans_i++)
    {
        ans_magicSquare[ans_i] = new int[ans_n];
        if (ans_magicSquare[ans_i] == NULL)
        {
            cout << "Memory allocation failed." << endl;
            return -3;
        }
    }

    for (ans_i = 0; ans_i < ans_n; ans_i++)
    {
        for (ans_j = 0; ans_j < ans_n; ans_j++)
        {
            ans_magicSquare[ans_i][ans_j] = 0;
        }
    }

    ans_row = 0;
    ans_col = ans_n / 2;

    for (ans_num = 1; ans_num <= ans_n * ans_n; ans_num++)
    {
        ans_magicSquare[ans_row][ans_col] = ans_num;

        ans_nextRow = ans_row - 1;
        ans_nextCol = ans_col + 1;

        if (ans_nextRow < 0)
            ans_nextRow = ans_n - 1;
        if (ans_nextCol == ans_n)
            ans_nextCol = 0;

        if (ans_magicSquare[ans_nextRow][ans_nextCol] != 0)
        {
            ans_nextRow = (ans_row + 1) % ans_n;
            ans_nextCol = ans_col;
        }

        ans_row = ans_nextRow;
        ans_col = ans_nextCol;
    }

    cout << "\nMagic Square:" << endl;
    for (ans_i = 0; ans_i < ans_n; ans_i++)
    {
        for (ans_j = 0; ans_j < ans_n; ans_j++)
        {
            cout << setw(4) << ans_magicSquare[ans_i][ans_j];
        }
        cout << endl;
    }

    cout << "Magic Sum: " << ans_n * (ans_n * ans_n + 1) / 2 << endl;

    for (ans_i = 0; ans_i < ans_n; ans_i++)
        delete[] ans_magicSquare[ans_i];
    delete[] ans_magicSquare;

    return 0;
}
```

## Output (Sample)
```
Enter the value of n: 3

Magic Square:
   8   1   6
   3   5   7
   4   9   2
Magic Sum: 15
