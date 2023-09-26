#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;


bool UsedInRow(int grid[9][9], int prow, int number)
{
   for (int col = 0; col < 9; col++)
       if (grid[prow][col] == number)
           return true;
   return false;
}

bool UsedInCol(int grid[9][9], int pcol, int number) {
   for (int row = 0; row < 9; row++)
       if (grid[row][pcol] == number)
           return true;
else 
    return false;
}

bool UsedInBox(int grid[9][9], int boxBeginRow, int boxBeginCol, int number) {
   bool tf = false;
   for (int row = 0; row < 3; row++)
       for (int col = 0; col < 3; col++)
           if (grid[row+boxBeginRow][col+boxBeginCol] == number)
               tf = true;
   return tf;
}

bool isGridSafe(int grid[9][9], int prow, int pcol, int number) {
   return !UsedInRow(grid, prow, number) && !UsedInCol(grid, pcol, number) &&
          !UsedInBox(grid, prow - prow % 3 , pcol - pcol % 3, number);
}

bool isEmptyLocation(int grid[9][9], int &row, int &col)
{
   for (row = 0; row < 9; row++)
       for (col = 0; col < 9; col++)
           if (grid[row][col] == 0)
               return true;
   return false;
}

bool SolveSudoku(int grid[9][9])
{
   int row, col;
   if (!isEmptyLocation(grid, row, col))
      return true;
   for (int num = 1; num <= 9; num++)
   {
       if (isGridSafe(grid, row, col, num))
       {
           grid[row][col] = num;
           if (SolveSudoku(grid))
               return true;
           grid[row][col] = 0;
       }
   }
   return false;
}

void printResult(int result[9][9]) {
   for (int row = 0; row < 9; row++)
   {
       for (int col = 0; col < 9; col++)
           cout<< result[row][col]<<"  ";
       cout<<endl;
   }
}

int main()
{
   int grid[9][9] = {{1, 0, 0, 0, 0, 0, 0, 0, 3},
                     {0, 4, 0, 0, 8, 9, 0, 2, 0},
                     {0, 0, 2, 0, 0, 3, 9, 5, 0},
                     {0, 0, 0, 4, 1, 0, 5, 0, 0},
                     {0, 0, 0, 0, 2, 0, 0, 0, 0},
                     {0, 0, 5, 0, 3, 7, 0, 0, 0},
                     {0, 3, 4, 8, 0, 0, 6, 0, 0},
                     {0, 2, 0, 6, 7, 0, 0, 3, 0},
                     {6, 0, 0, 0, 0, 0, 0, 0, 9}}; 
if (SolveSudoku(grid) == true)
         printResult(grid);
   else
       cout<<"No solution found"<<endl;
   return 0;
}