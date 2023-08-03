#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    char grid[MAX_ROWS * (MAX_COLS + 1)]; // Maximum size of grid

    // Read the grid from stdin
    if (fgets(grid, sizeof(grid), stdin) == NULL) {
        fprintf(stderr, "Error: Unable to read the grid.\n");
        return 1;
    }

    // Display the grid
    printf("The grid:\n");
    printf("%s", grid);

    return 0;
}







