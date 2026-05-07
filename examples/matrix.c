#include "mathcustomlib.h"
#include <stdio.h>

int main() {
    size_t shape[1] = {6};

    NDArray* a = nda_create(1, shape);
    NDArray* b = nda_create(1, shape);

    if (!a || !b) {
        printf("Error: memory allocation failed\n");
        return 1;
    }

    size_t total = nda_total_size(a);

    for (size_t i = 0; i < total; i++) {
        a->data[i] = (double)i;        // 0 1 2 3 4 5
        b->data[i] = 10.0;            // 10 10 10 ...
    }

    printf("Array A: ");
    nda_print(a);
    printf("\n");

    printf("Array B: ");
    nda_print(b);
    printf("\n");

    NDArray* c = nda_add(a, b);

    if (!c) {
        printf("Error: nda_add failed\n");
        return 1;
    }

    printf("A + B = ");
    nda_print(c);
    printf("\n");

    nda_free(a);
    nda_free(b);
    nda_free(c);

    return 0;
}