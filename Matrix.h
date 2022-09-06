//
// Created by robos on 06/09/2022.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <complex>
#include <iostream>
#include "Vector.h"

using namespace std;


template<unsigned int rows, unsigned int columns>
class Matrix {
private:
    complex<double> elem[rows][columns];

public:
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

    // operator[][]
    complex<double> &operator()(unsigned int i, unsigned int j) {
        return elem[i][j];
    }

    Matrix transposed();









    // Destructor
    ~Matrix() = default;
};




#endif //MATRIX_H
