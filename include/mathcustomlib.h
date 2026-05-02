#ifndef MATHCUSTOMLIB_H
#define MATHCUSTOMLIB_H

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divi(int a, int b);

// ----- MATRIX -----

double** create_matrix(int size_x, int size_y);
void show_matrix(double** matrix, int size_x, int size_y, int precision);
void free_matrix(double** matrix, int size_x);

#endif