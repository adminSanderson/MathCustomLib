#include <stdio.h>
#include "mathcustomlib.h"

// gcc examples/matrix.c -Iinclude -Llib -lmathcustomlib -o matrix.exe
// .\matrix.exe

int main() {

    printf("=== MATRIX TEST START ===\n\n");

    // -------------------------
    // 1. CREATE + FILL
    // -------------------------
    Matrix A = matrix_create(3, 3);
    matrix_fill(A, 2.0);

    printf("Matrix A (filled with 2.0):\n");
    matrix_print(A, 2);

    // -------------------------
    // 2. IDENTITY
    // -------------------------
    Matrix I = matrix_identity(3);

    printf("\nIdentity matrix:\n");
    matrix_print(I, 2);

    // -------------------------
    // 3. ADD / SUB
    // -------------------------
    Matrix B = matrix_fill_value(3, 3);

    Matrix add = matrix_add(A, B);
    Matrix sub = matrix_sub(B, A);

    printf("\nA + B:\n");
    matrix_print(add, 2);

    printf("\nB - A:\n");
    matrix_print(sub, 2);

    // -------------------------
    // 4. SCALAR
    // -------------------------
    Matrix scalar = matrix_scalar_mul(A, 3.0);

    printf("\nA * 3:\n");
    matrix_print(scalar, 2);

    // -------------------------
    // 5. TRANSPOSE
    // -------------------------
    Matrix T = matrix_transpose(B);

    printf("\nTranspose of B:\n");
    matrix_print(T, 2);

    // -------------------------
    // 6. MULTIPLICATION
    // -------------------------
    Matrix M = matrix_mul(A, B);

    printf("\nA * B:\n");
    matrix_print(M, 2);

    // -------------------------
    // 7. DETERMINANT
    // -------------------------
    double detA = matrix_determinant(I);

    printf("\nDeterminant of Identity: %.2f\n", detA);

    // -------------------------
    // 8. COPY TEST
    // -------------------------
    Matrix C = matrix_copy(A);

    printf("\nCopy of A:\n");
    matrix_print(C, 2);

    // -------------------------
    // 9. CLEANUP
    // -------------------------
    matrix_free(A);
    matrix_free(B);
    matrix_free(I);
    matrix_free(add);
    matrix_free(sub);
    matrix_free(scalar);
    matrix_free(T);
    matrix_free(M);
    matrix_free(C);

    printf("\n=== MATRIX TEST END ===\n");

    return 0;
}