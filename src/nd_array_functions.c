#include "mathcustomlib.h"

NDArray* nda_create(int ndim, const size_t* shape) {
    NDArray* arr = (NDArray*)malloc(sizeof(NDArray));
    if (!arr) return NULL;

    arr->ndim = ndim;

    arr->shape = (size_t*)malloc(sizeof(size_t) * ndim);
    if (!arr->shape) {
        free(arr);
        return NULL;
    }

    for (int i = 0; i < ndim; i++) {
        arr->shape[i] = shape[i];
    }

    arr->strides = (size_t*)malloc(sizeof(size_t) * ndim);
    if (!arr->strides) {
        free(arr->shape);
        free(arr);
        return NULL;
    }

    size_t stride = sizeof(double);
    for (int i = ndim - 1; i >= 0; i--) {
        arr->strides[i] = stride;
        stride *= arr->shape[i];
    }

    size_t total = 1;
    for (int i = 0; i < ndim; i++) {
        total *= shape[i];
    }

    arr->data = (double*)malloc(sizeof(double) * total);
    if (!arr->data) {
        free(arr->strides);
        free(arr->shape);
        free(arr);
        return NULL;
    }

    arr->owns_data = 1;

    return arr;
    
}

size_t nda_total_size(const NDArray* arr) {
    size_t total = 1;

    for (int i = 0; i < arr->ndim; i++) {
        total *= arr->shape[i];
    }

    return total;
}

int nda_same_shape(const NDArray* a, const NDArray* b) {
    if (a->ndim != b->ndim)
        return 0;

    for (int i = 0; i < a->ndim; i++) {
        if (a->shape[i] != b->shape[i])
            return 0;
    }

    return 1;
}

NDArray* nda_add(const NDArray* a, const NDArray* b) {
    if (!(nda_same_shape(a, b))) return NULL;

    NDArray* result = nda_create(a->ndim, a->shape);

    if (!result) return NULL;

    size_t total = nda_total_size(a);

    for (size_t i = 0; i < total; i++) {
        result->data[i] = a->data[i] + b->data[i];
    }

    return result;
}

void nda_print(const NDArray* arr) {
    if (!arr) {
        printf("[NDA]: NDArray(NULL)\n");
        return;
    }

    if (arr->ndim == 1) {
        for (size_t i = 0; i < arr->shape[0]; i++) {

            printf("%.2f", arr->data[i]);

            if (i + 1 < arr->shape[0]) {
                printf(", ");
            }
        }

        return;
    }

    printf("nda_print: ndim > 1 not supported yet\n");
    
}

void nda_free(NDArray* arr) {
    if (!arr) return;

    if (arr->owns_data)
        free(arr->data);

    free(arr->shape);
    free(arr->strides);
    free(arr);
}

NDArray* nda_fill(NDArray* arr, double value) {
    if (!arr) return NULL;

    size_t total = nda_total_size(arr);

    for (size_t i = 0; i < total; i++) arr->data[i] = value;

    return arr;
}

NDArray* nda_zeros(int ndim, const size_t* shape) {
    NDArray* arr = nda_create(ndim, shape);

    if (!arr) return NULL;

    nda_fill(arr, 0);

    return arr;
}

NDArray* nda_ones(int ndim, const size_t* shape) {
    NDArray* arr = nda_create(ndim, shape);

    if (!arr) return NULL;

    nda_fill(arr, 1.0);

    return arr;
}

NDArray* nda_copy(NDArray* arr) {
    NDArray* arr_copy = nda_create(arr->ndim, arr->shape);

    if (!arr_copy) return NULL;

    size_t total = nda_total_size(arr);

    for (size_t i = 0; i < total; i++) arr_copy->data[i] = arr->data[i];

    return arr_copy;
}

NDArray* nda_eye(size_t size) {
    size_t shape[2] = {size, size};

    NDArray* arr = nda_create(2, shape);

    if (!arr) return NULL;


    size_t total = nda_total_size(arr);

    for (size_t i = 0; i < total; i++) arr->data[i] = 0.0;

    for (size_t i = 0; i < size; i++) {
        arr->data[i * size + i] = 1.0;
    }

    return arr;
}