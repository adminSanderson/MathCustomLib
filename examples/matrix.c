#include "mathcustomlib.h"
#include <stdio.h>

int main() {

    size_t shape[1] = {5};

    NDArray* a = nda_ones(1, shape);
    NDArray* b = nda_zeros(1, shape);

    for (size_t i = 0; i < nda_total_size(b); i++) {
        b->data[i] = i * 2;
    }

    NDArray* c = nda_add(a, b);

    printf("Array A:\n");
    nda_print(a);

    printf("\nArray B:\n");
    nda_print(b);

    printf("\nA + B:\n");
    nda_print(c);

    printf("\nIdentity matrix:\n");

    NDArray* eye = nda_eye(4);
    nda_print(eye);

    nda_free(a);
    nda_free(b);
    nda_free(c);
    nda_free(eye);

    return 0;
}