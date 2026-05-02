#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mathcustomlib.h"

Matrix matrix_create(int rows, int cols) {
    Matrix m;

    m.rows = rows;
    m.cols = cols;
    m.data = (double*)malloc(rows * cols * sizeof(double));

    return m;
}

void matrix_print(Matrix m, int precision) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%.*f ", precision, m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

void matrix_free(Matrix m) {
    free(m.data);
}

void matrix_fill(Matrix m, double value) {
    for (int i = 0; i < m.rows * m.cols; i++) {
        m.data[i] = value;
    }
}

Matrix matrix_copy(Matrix m) {
    Matrix result = matrix_create(m.rows, m.cols);
    
    for (int i = 0; i < m.rows * m.cols; i++) result.data[i] = m.data[i];

    return result;
}

Matrix matrix_identity(int size) {
    Matrix m = matrix_create(size, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                m.data[i * size + j] = 1.0;
            else
                m.data[i * size + j] = 0.0;
        }
    }

    return m;
}

Matrix matrix_fill_value(int rows, int cols) {
    Matrix result = matrix_create(rows, cols);

    for (int i = 0; i < rows * cols; i++) result.data[i] = i;
    
    return result;
}

Matrix matrix_add(Matrix a, Matrix b) {
    Matrix empty = {0, 0, NULL};

    if (a.rows != b.rows || a.cols != b.cols) {
        printf("[MCL] Error: matrix sizes do not match\n");
        return empty;
    }

    Matrix result = matrix_create(a.rows, a.cols);

    for (int i = 0; i < a.rows * a.cols; i++) {
        result.data[i] = a.data[i] + b.data[i];
    }

    return result;
}

Matrix matrix_sub(Matrix a, Matrix b) {
    Matrix empty = {0, 0, NULL};

    if (a.rows != b.rows || a.cols != b.cols) {
        printf("[MCL] Error: matrix sizes do not match\n");
        return empty;
    }

    Matrix result = matrix_create(a.rows, a.cols);

    for (int i = 0; i < a.rows * a.cols; i++) {
        result.data[i] = a.data[i] - b.data[i];
    }

    return result;
}

Matrix matrix_scalar_mul(Matrix a, double k) {
    Matrix result = matrix_create(a.rows, a.cols);

    for (int i = 0; i < a.rows * a.cols; i++) {
        result.data[i] = a.data[i] * k;
    }

    return result;
}

Matrix matrix_transpose(Matrix a) {
    Matrix result = matrix_create(a.cols, a.rows);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[j * a.rows + i] = a.data[i * a.cols + j];
        }
    }

    return result;
}

Matrix matrix_mul(Matrix a, Matrix b) {
    Matrix empty = {0, 0, NULL};

    if (a.cols != b.rows) {
        printf("[MCL] Error: invalid sizes\n");
        return empty;
    }

    Matrix result = matrix_create(a.rows, b.cols);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {

            result.data[i * b.cols + j] = 0;

            for (int k = 0; k < a.cols; k++) {
                result.data[i * b.cols + j] +=
                    a.data[i * a.cols + k] * b.data[k * b.cols + j];
            }
        }
    }

    return result;
}

double matrix_determinant(Matrix m) {
    if (m.rows != m.cols) return 0;

    int n = m.rows;
    double det = 1;

    Matrix temp = matrix_copy(m);

    for (int i = 0; i < n; i++) {

        double pivot = temp.data[i * n + i];

        if (fabs(pivot) < 1e-9) {
            free(temp.data);
            return 0;
        }

        det *= pivot;

        for (int j = i + 1; j < n; j++) {
            double factor = temp.data[j * n + i] / pivot;

            for (int k = i; k < n; k++) {
                temp.data[j * n + k] -= factor * temp.data[i * n + k];
            }
        }
    }

    free(temp.data);
    return det;
}