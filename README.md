# MathCustomLib

MathCustomLib is a simple C library for basic math operations.

---

## 📁 Project structure

```
mathcustomlib/
├── include/      # header file
├── src/          # source code
├── build/        # object files
├── lib/          # compiled library
├── examples/     # example program
├── Makefile
└── README.md
```

---

## ⚙️ How to build

Run:

```
make
```

After that you will get:

* `libmathcustomlib.a` (static library)
* `libmathcustomlib.so` (shared library)

---

## 🚀 How to use

### 1. Include the library

```c
#include "mathcustomlib.h"
```

---

### 2. Compile your program

```
gcc main.c -Iinclude -Llib -lmathcustomlib -o main
```

---

### 3. Run

```
./main
```

---

## 📘 Functions

```
Read the documentation
```

## ⚠️ Important

* Use only `int` values
* Wrong types can cause errors
* Compile with:

```
-Wall -Wextra -Werror
```

---

## 🧪 Example

```c
#include <stdio.h>
#include <stdlib.h>
#include "mathcustomlib.h"

int main() {
    int rows = 3;
    int cols = 3;

    double** matrix = create_matrix(rows, cols);

    if (!matrix) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }

    printf("Matrix:\n");
    show_matrix(matrix, rows, cols, 2);

    free_matrix(matrix, rows);

    return 0;
}
```
Output:

```cmd
Matrix:
1.00 2.00 3.00 
4.00 5.00 6.00 
7.00 8.00 9.00 
```


---

## 🛠️ Clean

```
make clean
```

---

## 👨‍💻 Author

@adminSanderson
