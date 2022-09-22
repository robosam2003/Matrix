

#include "Matrix.h"

template<typename T, unsigned int num_rows, unsigned int num_columns>
Matrix<T, num_rows, num_columns>::Matrix() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = 0;
        }
    }
}

// Copy constructor
template<typename T, unsigned int num_rows, unsigned int num_columns>
Matrix<T, num_rows, num_columns>::Matrix(const Matrix &m) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
}

// Copy assignment
template<typename T, unsigned int num_rows, unsigned int num_columns>
Matrix<T, num_rows, num_columns> &Matrix<T, num_rows, num_columns>::operator=(const Matrix &m) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
    return *this;
}

template<typename T, unsigned int num_rows, unsigned int num_columns>
Matrix<T, num_rows, num_columns>::Matrix(Matrix &&m) noexcept {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
}

template<typename T, unsigned int num_rows, unsigned int num_columns>
Matrix<T, num_rows, num_columns> &Matrix<T, num_rows, num_columns>::operator=(Matrix &&m) {
for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
    return *this;
}

template<typename T, unsigned int num_rows, unsigned int num_columns>
void Matrix<T, num_rows, num_columns>::transpose() {
    Matrix<T, num_columns, num_rows> m = *this;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[j][i];
        }
    }
}

template<typename T, unsigned int num_rows, unsigned int num_columns>
Vector<T, num_rows> Matrix<T, num_rows, num_columns>::getRow(unsigned int row) {
    Vector<T, num_rows> v;
    for (int i = 0; i < num_rows; i++) {
        v[i] = elem[row][i];
    }
    return v;
}


template<typename T, unsigned int num_rows, unsigned int num_columns>
Vector<T, num_columns> Matrix<T, num_rows, num_columns>::getColumn(unsigned int column) const {
    Vector<T, num_columns> v = {0};
    for (int i = 0; i < num_columns; i++) {
        v[i] = elem[i][column];
    }
    return v;
}




