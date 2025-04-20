#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class Matrix {
private:
    size_t rows_, cols_;
    vector<double> data_;

public:
    // Constructors
    Matrix(size_t rows, size_t cols);
    Matrix(const Matrix& other) = default;
    Matrix(Matrix&& other) noexcept = default;

    // Assignment
    Matrix& operator=(const Matrix& other) = default;
    Matrix& operator=(Matrix&& other) noexcept = default;

    // Element access
    double& operator()(size_t i, size_t j);
    double  operator()(size_t i, size_t j) const;

    // Dimensions
    size_t rows() const noexcept { return rows_; }
    size_t cols() const noexcept { return cols_; }

    // Arithmetic
    Matrix operator+(const Matrix& rhs) const;
    Matrix operator-(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;
    Matrix operator*(double scalar)       const;

    // Transpose
    Matrix transpose() const;

    // I/O
    friend ostream& operator<<(ostream& os, const Matrix& m);
};
#endif
