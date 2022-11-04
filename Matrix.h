//
// Created by robos on 06/09/2022.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Vector/Vector.h"

using namespace std;


template<unsigned int num_rows, unsigned int num_columns, typename T=double> // default type is double, can be changed
class Matrix {
private:
    T elem[num_rows][num_columns];
    //    const unsigned int nrows = num_rows; // allows us to extract information about the matrix from the methods
    //    const unsigned int ncols = num_columns; - Necessary?

public:


    // TODO: Add std::initializer_list constructor
    // TODO: Eigenvectors and eigenvalues calculation.
    // TODO: Neat, clear way of changing basis
    // TODO: Determinant
    // TODO: Inverse
    // TODO: Transpose
    // TODO: Casting to new type (and size)
    // which allows for    // appendRow and appendColumn - NEEDED?
    // TODO: Submatricies of matrix



    // default constructor
    Matrix();

    // Copy constructor
    Matrix(const Matrix &m);

    // Copy assignment
    Matrix &operator=(const Matrix &m);

    // Move constructor
    Matrix(Matrix &&m) noexcept;

    // Move assignment
    Matrix &operator=(Matrix &&m) noexcept;



    // Addition operator
    Matrix operator+(const Matrix &m) const;

    // Subtraction operator
    Matrix operator-(const Matrix &m) const;

    // Multiply by scalar
    Matrix operator*(const T &scalar) const;

    // Multiply by vector
    Vector<T, num_columns> operator*(const Vector<T, num_columns> &v) const;

    // Multiply by matrix
    // TODO: try second template for parameter to allow for different sized matrices, sort names of template parameters
    template<unsigned int num_col_2, class D>
        // Returns a matrix with size: number of rows from the first  x  number of columns from the second.
        // Second matrix (input) must have the same number of rows as the first matrix (this) has columns.
        Matrix<num_rows, num_col_2, T> operator*(const Matrix<num_columns, num_col_2, D> &m) const;

    T* operator[](unsigned int index) { /// return a vector which is row i, note that this way, you can get the full coordinate using m[i][j]
        return (elem[index]); // TODO: Is this the best way to implement [][] operator? look into proxy classes????
    }

    const T* operator[](unsigned int index) const { // const version of above
        return (elem[index]);
    }

    void transpose(); // NOT const (as it changes the matrix elements)

    Matrix transposed() const;

    Vector<T, num_rows> getRow(unsigned int row);

    Vector<T, num_columns> getColumn(unsigned int column) const;

    Vector<T, num_columns> GaussianElimination(Vector<T, num_columns> &v) const;

   void PartialPivotMatrix(Vector<T, num_columns> &v);

    // Destructor
    ~Matrix() = default;
};

#include "Matrix.tpp"




#endif //MATRIX_H
