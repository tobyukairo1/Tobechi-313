# Author
Tobechi Ukairo UMBC sophmore 04/19/2025 

# Purpose

Provide basic functions to:

Create and free matrices

Read and write elements

Add, subtract, and multiply matrices

Transpose matrices

We include example programs to test these functions.

# Files

matrix.hpp, matrix.cpp

C++ class Matrix with methods and operators for matrix operations.

matrix.h, matrix.c

C functions for matrix operations following the C99 standard.

test.cpp

C++ program that builds and runs a sample matrix calculation.

test.c

C program that does the same sample calculation.

How to Build

C++ Version

# Compile
 g++ -Wall -g -c matrix.cpp -o matrix.o
 g++ -Wall -g matrix.o test.cpp -o test

 Run
 ./test_cpp

C Version

 gcc -std=c99 -Wall -g -c matrix.c -o matrix.o
 gcc -std=c99 -Wall -g matrix.o test.c -o test_c

 Run
 ./test_c

# Testing

Both test programs compute:

D = A + (3 * B) * C^T

They print the result so you can check it matches expected values.

