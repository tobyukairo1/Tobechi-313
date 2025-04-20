#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    size_t rows;
    size_t cols;
    double *data;
} Matrix;

// Allocate a new rows×cols matrix (initialized to zero), or NULL on failure.
Matrix* matrix_create(size_t rows, size_t cols);

// Free a matrix previously created with matrix_create.
void matrix_destroy(Matrix *m);

// Get element (i,j) into *out; returns 0 on success or -1 on error.
int matrix_get(const Matrix *m, size_t i, size_t j, double *out);

// Set element (i,j) = value; returns 0 on success or -1 on error.
int matrix_set(Matrix *m, size_t i, size_t j, double value);

// C = A + B; returns 0 on success, -1 on dimension mismatch or other error.
int matrix_add(const Matrix *A, const Matrix *B, Matrix *C);

// C = A - B; returns 0 on success, -1 on dimension mismatch or other error.
int matrix_sub(const Matrix *A, const Matrix *B, Matrix *C);

// C = A × B; returns 0 on success, -1 on dimension mismatch or other error.
int matrix_mul(const Matrix *A, const Matrix *B, Matrix *C);

// B = transpose(A); returns 0 on success, -1 on error.
int matrix_transpose(const Matrix *A, Matrix *B);

#ifdef __cplusplus
}
#endif

#endif // MATRIX_H
