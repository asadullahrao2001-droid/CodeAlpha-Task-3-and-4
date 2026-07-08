#include <iostream>
using namespace std;

const int SIZE = 9;

// Function to check whether a number can be placed safely
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
    // Check row
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[row][i] == num)
            return false;
    }

    // Check column
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[i][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

// Function to solve Sudoku using Backtracking
bool solveSudoku(int grid[SIZE][SIZE])
{
    int row = -1;
    int col = -1;
    bool emptyCell = false;

    // Find an empty cell
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                emptyCell = true;
                break;
            }
        }

        if (emptyCell)
            break;
    }

    // If no empty cell found, Sudoku is solved
    if (!emptyCell)
        return true;

    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

// Function to print Sudoku
void printGrid(int grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int grid[SIZE][SIZE];

    cout << "========== Sudoku Solver ==========\n";
    cout << "Enter the Sudoku puzzle (9x9).\n";
    cout << "Use 0 for empty cells.\n\n";

    // Input Sudoku
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << "\nOriginal Sudoku:\n";
    printGrid(grid);

    if (solveSudoku(grid))
    {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    }
    else
    {
        cout << "\nNo solution exists!" << endl;
    }

    return 0;
}