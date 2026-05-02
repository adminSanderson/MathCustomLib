#include <stdlib.h>
#include <stdio.h>
#include "mathcustomlib.h"

double** create_matrix(int size_x, int size_y) {
    double** matrix = malloc(size_x * sizeof(double*));
    if (!matrix) return NULL;

    for (int i = 0; i < size_x; i++) {
        matrix[i] = malloc(size_y * sizeof(double));
        if (!matrix[i]) return NULL;
    }

    return matrix;
}

void show_matrix(double** matrix, int size_x, int size_y, int precision) {
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            printf("%.*f ", precision, matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(double** matrix, int size_x) {
    for (int i = 0; i < size_x; i++) free(matrix[i]);
    free(matrix);
}