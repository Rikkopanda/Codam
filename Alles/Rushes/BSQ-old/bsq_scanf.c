#include <stdio.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int x, y;
    char grid[MAX_ROWS][MAX_COLS + 1]; // +1 for null terminator

    // Read grid size (x and y) from stdin
    if (scanf("%d %d", &x, &y) != 2) {
        fprintf(stderr, "Invalid input: Unable to read grid size.\n");
        return 1;
    }

    // Read the grid from stdin
    for (int i = 0; i < y; i++) {
        if (scanf("%s", grid[i]) != 1) {
            fprintf(stderr, "Invalid input: Unable to read grid row.\n");
            return 1;
        }
    }

    // Display the grid
    printf("The grid:\n");
    for (int i = 0; i < y; i++) {
        printf("%s\n", grid[i]);
    }

    return 0;
}