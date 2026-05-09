#ifndef MATHCUSTOMLIB_H
#define MATHCUSTOMLIB_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

// =====================
// NDARRAY STRUCT
// =====================

typedef struct {
    int ndim;
    size_t* shape;
    size_t* strides;
    double* data;
    int owns_data;
} NDArray;

// =====================
// CORE FUNCTIONS
// =====================

NDArray* nda_create(int ndim, const size_t* shape);

void nda_free(NDArray* arr);

size_t nda_total_size(const NDArray* arr);

int nda_same_shape(const NDArray* a, const NDArray* b);

NDArray* nda_fill(NDArray* arr, double value);

NDArray* nda_zeros(int ndim, const size_t* shape);

NDArray* nda_ones(int ndim, const size_t* shape);

NDArray* nda_copy(NDArray* arr);

NDArray* nda_eye(size_t size);

// =====================
// OPERATIONS
// =====================

NDArray* nda_add(const NDArray* a, const NDArray* b);

// =====================
// IO
// =====================

void nda_print(const NDArray* arr);

#endif // MATHCUSTOMLIB_H