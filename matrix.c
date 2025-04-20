#include "matrix.h"
#include <stdlib.h>
#include <string.h>

Matrix* matrix_create(size_t rows, size_t cols) {
    if (rows == 0 || cols == 0) return NULL;
    Matrix *m = malloc(sizeof(Matrix));
    if (!m) return NULL;
    m->rows = rows;
    m->cols = cols;
    m->data = calloc(rows * cols, sizeof(double));
    if (!m->data) {
        free(m);
        return NULL;
    }
    return m;
}

void matrix_destroy(Matrix *m) {
    if (!m) return;
    free(m->data);
    free(m);
}

int matrix_get(const Matrix *m, size_t i, size_t j, double *out) {
    if (!m || !out || i >= m->rows || j >= m->cols) return -1;
    *out = m->data[i * m->cols + j];
    return 0;
}

int matrix_set(Matrix *m, size_t i, size_t j, double value) {
    if (!m || i >= m->rows || j >= m->cols) return -1;
    m->data[i * m->cols + j] = value;
    return 0;
}

int matrix_add(const Matrix *A, const Matrix *B, Matrix *C) {
    if (!A || !B || !C ||
        A->rows != B->rows || A->cols != B->cols ||
        C->rows != A->rows || C->cols != A->cols)
    {
        return -1;
    }
    size_t n = A->rows * A->cols;
    for (size_t k = 0; k < n; ++k) {
        C->data[k] = A->data[k] + B->data[k];
    }
    return 0;
}

int matrix_sub(const Matrix *A, const Matrix *B, Matrix *C) {
    if (!A || !B || !C ||
        A->rows != B->rows || A->cols != B->cols ||
        C->rows != A->rows || C->cols != A->cols)
    {
        return -1;
    }
    size_t n = A->rows * A->cols;
    for (size_t k = 0; k < n; ++k) {
        C->data[k] = A->data[k] - B->data[k];
    }
    return 0;
}

int matrix_mul(const Matrix *A, const Matrix *B, Matrix *C) {
    if (!A || !B || !C || A->cols != B->rows ||
        C->rows != A->rows || C->cols != B->cols)
    {
        return -1;
    }
    // zero out C
    memset(C->data, 0, C->rows * C->cols * sizeof(double));

    for (size_t i = 0; i < A->rows; ++i) {
        for (size_t k = 0; k < A->cols; ++k) {
            double aik = A->data[i * A->cols + k];
            for (size_t j = 0; j < B->cols; ++j) {
                C->data[i * C->cols + j] += aik * B->data[k * B->cols + j];
            }
        }
    }
    return 0;
}

int matrix_transpose(const Matrix *A, Matrix *B) {
    if (!A || !B || A->rows != B->cols || A->cols != B->rows) {
        return -1;
    }
    for (size_t i = 0; i < A->rows; ++i) {
        for (size_t j = 0; j < A->cols; ++j) {
            B->data[j * B->cols + i] = A->data[i * A->cols + j];
        }
    }
    return 0;
}
