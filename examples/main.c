#include <stdio.h>
#include <stdlib.h>
#include "mathcustomlib.h"

int main() {
    int rows = 3;
    int cols = 3;

    double** matrix = create_matrix(rows, cols);

    if (!matrix) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }

    printf("Matrix:\n");
    show_matrix(matrix, rows, cols, 2);

    free_matrix(matrix, rows);

    return 0;
}