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