//
// Created by robos on 06/09/2022.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <complex>
#include <iostream>
#include "Vector.h"

using namespace std;


template<typename T, unsigned int num_rows, unsigned int num_columns>
class Matrix {
private:
    T elem[num_rows][num_columns];
public:
    // default constructor
    Matrix();

    // Copy constructor
    Matrix(const Matrix &m);

    // Copy assignment
    Matrix &operator=(const Matrix &m);

    // Move constructor
    Matrix(Matrix &&m) noexcept ;

    // Move assignment
    Matrix &operator=(Matrix &&m);


    void transpose();

    T* operator[](unsigned int index) { /// return a vector which is the row, note that this way, you can get the full coordinate using m[i][j]
        return (elem[index]); // TODO: Is this the best way to implement [][] operator? look into proxy classes????
    }

    Vector<T, num_rows> getRow(unsigned int row);

    Vector<T, num_columns> getColumn(unsigned int column) const;




    // Destructor
    ~Matrix() = default;
};

#include "Matrix.tpp"




#endif //MATRIX_H
