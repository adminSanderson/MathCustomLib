#ifndef MATHCUSTOMLIB_H
#define MATHCUSTOMLIB_H

#include <stdlib.h>
#include <stdio.h>

// =====================
// BASIC FUNCTIONS
// =====================

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divi(int a, int b);

// =====================
// MATRIX STRUCT
// =====================

typedef struct {
    int rows;
    int cols;
    double* data;
} Matrix;

Matrix matrix_create(int rows, int cols);
void matrix_free(Matrix m);

void matrix_print(Matrix m, int precision);
void matrix_fill(Matrix m, double value);
Matrix matrix_copy(Matrix m);

// MATRIX SPECIAL

Matrix matrix_identity(int size);
Matrix matrix_fill_value(int rows, int cols);

// MATRIX OPERATIONS

Matrix matrix_add(Matrix a, Matrix b);
Matrix matrix_sub(Matrix a, Matrix b);
Matrix matrix_scalar_mul(Matrix a, double k);
Matrix matrix_transpose(Matrix a);
Matrix matrix_mul(Matrix a, Matrix b);

// MATRIX ADVANCED

double matrix_determinant(Matrix m);

#endif // MATHCUSTOMLIB_H