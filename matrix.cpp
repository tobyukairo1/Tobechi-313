#include "matrix.hpp"

// Constructor
Matrix::Matrix(std::size_t rows, std::size_t cols)
  : rows_(rows), cols_(cols), data_(rows * cols, 0.0)
{ 
    if (rows == 0 || cols == 0) {
        throw std::invalid_argument("Matrix dimensions must be non-zero");
    }
}

// Element access (with bounds checking)
double& Matrix::operator()(std::size_t i, std::size_t j) {
    if (i >= rows_ || j >= cols_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[i * cols_ + j];
}

double Matrix::operator()(std::size_t i, std::size_t j) const {
    if (i >= rows_ || j >= cols_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[i * cols_ + j];
}

// Addition
Matrix Matrix::operator+(const Matrix& rhs) const {
    if (rows_ != rhs.rows_ || cols_ != rhs.cols_) {
        throw std::invalid_argument("Dimension mismatch for addition");
    }
    Matrix result(rows_, cols_);
    for (std::size_t i = 0; i < data_.size(); ++i) {
        result.data_[i] = data_[i] + rhs.data_[i];
    }
    return result;
}

// Subtraction
Matrix Matrix::operator-(const Matrix& rhs) const {
    if (rows_ != rhs.rows_ || cols_ != rhs.cols_) {
        throw std::invalid_argument("Dimension mismatch for subtraction");
    }
    Matrix result(rows_, cols_);
    for (std::size_t i = 0; i < data_.size(); ++i) {
        result.data_[i] = data_[i] - rhs.data_[i];
    }
    return result;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix& rhs) const {
    if (cols_ != rhs.rows_) {
        throw std::invalid_argument("Dimension mismatch for multiplication");
    }
    Matrix result(rows_, rhs.cols_);
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < rhs.cols_; ++j) {
            double sum = 0.0;
            for (std::size_t k = 0; k < cols_; ++k) {
                sum += (*this)(i, k) * rhs(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

// Scalar multiplication
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows_, cols_);
    for (std::size_t i = 0; i < data_.size(); ++i) {
        result.data_[i] = data_[i] * scalar;
    }
    return result;
}

// Transpose
Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < cols_; ++j) {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}

// Stream output
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (std::size_t i = 0; i < m.rows_; ++i) {
        os << "[ ";
        for (std::size_t j = 0; j < m.cols_; ++j) {
            os << m(i, j) << (j + 1 < m.cols_ ? ", " : " ");
        }
        os << "]\n";
    }
    return os;
}
