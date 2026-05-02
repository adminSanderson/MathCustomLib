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
#include "mathcustomlib.h"

int main() {
    printf("%d\n", add(5, 3));
    printf("%d\n", sub(5, 3));
    printf("%d\n", mul(5, 3));
    return 0;
}
```

---

## 🛠️ Clean

```
make clean
```

---

## 👨‍💻 Author

adminSanderson
