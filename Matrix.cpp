

#include "Matrix.h"

template<unsigned int rows, unsigned int columns>
Matrix<rows, columns>::Matrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            elem[i][j] = 0;
        }
    }
}

// Copy constructor
template<unsigned int rows, unsigned int columns>
Matrix<rows, columns>::Matrix(const Matrix &m) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
}

// Copy assignment
template<unsigned int rows, unsigned int columns>
Matrix<rows, columns> &Matrix<rows, columns>::operator=(const Matrix &m) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
    return *this;
}

template<unsigned int rows, unsigned int columns>
Matrix<rows, columns>::Matrix(Matrix &&m) noexcept {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
}

template<unsigned int rows, unsigned int columns>
Matrix<rows, columns> &Matrix<rows, columns>::operator=(Matrix &&m) {
for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
    return *this;
}

template<unsigned int rows, unsigned int columns>
void Matrix<rows, columns>::transpose() {
    Matrix<columns, rows> m = std::copy(*this);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            elem[i][j] = m.elem[j][i];
        }
    }
}



