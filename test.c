// test.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main(void) {
    size_t i, j;
    double v;

    // 1) Allocate all needed matrices
    Matrix *A  = matrix_create(2, 2);
    Matrix *B  = matrix_create(2, 3);
    Matrix *C  = matrix_create(2, 3);
    Matrix *B3 = matrix_create(2, 3);  // for 3*B
    Matrix *CT = matrix_create(3, 2);  // for C^T
    Matrix *M  = matrix_create(2, 2);  // for B3 × CT
    Matrix *D  = matrix_create(2, 2);  // final result
    if (!A||!B||!C||!B3||!CT||!M||!D) {
        fprintf(stderr, "Allocation failed\n");
        return 1;
    }

    // 2) Fill A
    matrix_set(A, 0, 0, 6);
    matrix_set(A, 0, 1, 4);
    matrix_set(A, 1, 0, 8);
    matrix_set(A, 1, 1, 3);

    // 3) Fill B
    double Bvals[2][3] = { {1,2,3}, {4,5,6} };
    for (i = 0; i < 2; ++i)
      for (j = 0; j < 3; ++j)
        matrix_set(B, i, j, Bvals[i][j]);

    // 4) Fill C
    double Cvals[2][3] = { {2,4,6}, {1,3,5} };
    for (i = 0; i < 2; ++i)
      for (j = 0; j < 3; ++j)
        matrix_set(C, i, j, Cvals[i][j]);

    // 5) Compute B3 = 3 * B
    for (i = 0; i < 2; ++i) {
      for (j = 0; j < 3; ++j) {
        matrix_get(B, i, j, &v);
        matrix_set(B3, i, j, v * 3.0);
      }
    }

    // 6) Transpose C → CT
    if (matrix_transpose(C, CT) != 0) {
      fprintf(stderr, "Transpose failed\n");
      return 1;
    }

    // 7) Multiply B3 × CT → M
    if (matrix_mul(B3, CT, M) != 0) {
      fprintf(stderr, "Multiplication failed\n");
      return 1;
    }

    // 8) Add A + M → D
    if (matrix_add(A, M, D) != 0) {
      fprintf(stderr, "Addition failed\n");
      return 1;
    }

    // 9) Print D
    printf("D =\n");
    for (i = 0; i < 2; ++i) {
      for (j = 0; j < 2; ++j) {
        matrix_get(D, i, j, &v);
        printf("%8.3f ", v);
      }
      putchar('\n');
    }

    // 10) Clean up
    matrix_destroy(A);
    matrix_destroy(B);
    matrix_destroy(C);
    matrix_destroy(B3);
    matrix_destroy(CT);
    matrix_destroy(M);
    matrix_destroy(D);
    return 0;
}
