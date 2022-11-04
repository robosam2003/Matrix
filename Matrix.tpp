

#include "Matrix.h"

// default constructor
template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T>::Matrix() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = 0;
        }
    }
}

// std::initializer_list constructor
template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T>::Matrix(initializer_list<std::initializer_list<T>> list) {
    int i = 0;
    for (auto row : list) {
        int j = 0;
        for (auto col : row) {
            elem[i][j] = col;
            j++;
        }
        i++;
    }
}


// Copy constructor
template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T>::Matrix(const Matrix &m) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
}

// Copy assignment
template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T> &Matrix<num_rows, num_columns, T>::operator=(const Matrix &m) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
    return *this;
}

// Move constructor
template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T>::Matrix(Matrix &&m) noexcept {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
}
// Move assignment
template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T> &Matrix<num_rows, num_columns, T>::operator=(Matrix &&m) noexcept {
for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
    return *this;
}

// Addition operator
template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T> Matrix<num_rows, num_columns, T>::operator+(const Matrix &m) const {
    Matrix<num_rows, num_columns, T> result;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            result.elem[i][j] = elem[i][j] + m.elem[i][j];
        }
    }
    return result;
}

// Subtraction operator
template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T> Matrix<num_rows, num_columns, T>::operator-(const Matrix &m) const {
    Matrix<num_rows, num_columns, T> result;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            result.elem[i][j] = elem[i][j] - m.elem[i][j];
        }
    }
    return result;
}

// Casting operator - c-style cast
template<unsigned int num_rows, unsigned int num_columns, class T>
template<unsigned int new_num_rows, unsigned int new_num_columns, class D>
Matrix<num_rows, num_columns, T>::operator Matrix<new_num_rows, new_num_columns, D>() const {
    Matrix<new_num_rows, new_num_columns, D> result; // initialises all zeros
    for (int i = 0; i < min(num_rows, new_num_rows); i++) {
        for (int j = 0; j < min(num_columns, num_columns); j++){
            result[i][j] = (D)elem[i][j];
        }
    }

    return result;
}


template<unsigned int num_rows, unsigned int num_columns, class T>
void Matrix<num_rows, num_columns, T>::transpose() {
    Matrix<num_columns, num_rows, T> m = *this;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[j][i];
        }
    }
}

template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T> Matrix<num_rows, num_columns, T>::transposed() const {
    Matrix<num_rows, num_columns, T> m = *this;
    m.transpose();
    return m;
}

template<unsigned int num_rows, unsigned int num_columns, class T>
Vector<T, num_rows> Matrix<num_rows, num_columns, T>::getRow(unsigned int row) {
    Vector<T, num_rows> v;
    for (int i = 0; i < num_rows; i++) {
        v[i] = elem[row][i];
    }
    return v;
}


template<unsigned int num_rows, unsigned int num_columns, class T>
Vector<T, num_columns> Matrix<num_rows, num_columns, T>::getColumn(unsigned int column) const {
    Vector<T, num_columns> v = {0};
    for (int i = 0; i < num_columns; i++) {
        v[i] = elem[i][column];
    }
    return v;
}

template<unsigned int num_rows, unsigned int num_columns, class T>
Matrix<num_rows, num_columns, T> Matrix<num_rows, num_columns, T>::operator*(const T &scalar) const {
    Matrix<num_rows, num_columns, T> result;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            result.elem[i][j] = elem[i][j] * scalar;
        }
    }
    return result;
}

template<unsigned int num_rows, unsigned int num_columns, class T>
Vector<T, num_columns> Matrix<num_rows, num_columns, T>::operator*(const Vector<T, num_columns> &v) const {
    Vector<T, num_columns> result;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            result[i] += elem[i][j] * v[j];
        }
    }
    return result;
}

template<unsigned int num_rows, unsigned int num_columns, class T>
template<unsigned int num_col_2, class D>
Matrix<num_rows, num_col_2, T>
Matrix<num_rows, num_columns, T>::operator*(const Matrix<num_columns, num_col_2, D> &m) const {
Matrix<num_rows, num_col_2, T> result;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_col_2; j++) {
            for (int k = 0; k < num_columns; k++) {
                result.elem[i][j] += elem[i][k] * m.elem[k][j];
            }
        }
    }
    return result;
}












