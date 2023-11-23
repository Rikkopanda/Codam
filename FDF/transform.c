#include <stdio.h>
#include <stdlib.h>

// function to multiply two matrices
void multiplyMatrices(int **first,
                      int **second,
                      int **result,
                      int r1, int c1, int r2, int c2) {

   // Initializing elements of matrix mult to 0.
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         result[i][j] = 0;
      }
   }

   // Multiplying first and second matrices and storing it in result
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}

// function to display the matrix
void display(int **result, int row, int column) {

   printf("\nOutput Matrix:\n");
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("%d  ", result[i][j]);
         if (j == column - 1)
            printf("\n");
      }
   }
}

void transform(int **xyz, int **T, int **result) {

   multiplyMatrices(xyz, T, result, 1, 3, 3, 3);

   // display the result
   T = result;
   display(T, 1, 3);
}

int main(void)
{
    int **xyz;
    int i;
    int **T;
    int **result;
    {
    xyz = malloc(sizeof(int *) * 1);
    xyz[0] = malloc(sizeof(int) * 3);
    }
    {
    T = malloc(sizeof(int *) * 3);
    i = -1;
    while (++i < 3)
        T[i] = malloc(sizeof(int) * 3);
    }
    {
    result = malloc(sizeof(int *) * 1);
    result[0] = malloc(sizeof(int) * 3);
    }
    // xyz[0] = (int){1, 2 ,3};
    xyz[0][0] = 1;
    xyz[0][1] = 2;
    xyz[0][2] = 3;
    // T[0] = (int){1, -1, 0};
    // T[1] = (int){-1, 1, 0};
    // T[2] = (int){0, 0, 1};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            T[i][j] = (i == j) ? 3 : 1; // Example values, change as needed
        }
    }
    display(xyz, 1, 3);
    display(T, 3, 3);
    transform(xyz, T, result);
}