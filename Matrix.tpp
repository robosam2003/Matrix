

#include "Matrix.h"

// default constructor (Initializes a zero matrix)
template<unsigned int num_rows, unsigned int num_columns, typename T>
Matrix<num_rows, num_columns, T>::Matrix() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = 0;
        }
    }
}

// Copy constructor
template<unsigned int num_rows, unsigned int num_columns, typename T>
Matrix<num_rows, num_columns, T>::Matrix(const Matrix &m) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
}

// Copy assignment
template<unsigned int num_rows, unsigned int num_columns, typename T>
Matrix<num_rows, num_columns, T> &Matrix<num_rows, num_columns, T>::operator=(const Matrix &m) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
    return *this;
}

// Move constructor
template<unsigned int num_rows, unsigned int num_columns, typename T>
Matrix<num_rows, num_columns, T>::Matrix(Matrix &&m) noexcept {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
}
// Move assignment
template<unsigned int num_rows, unsigned int num_columns, typename T>
Matrix<num_rows, num_columns, T> &Matrix<num_rows, num_columns, T>::operator=(Matrix &&m) noexcept {
for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[i][j];
        }
    }
    return *this;
}

// Addition operator
template<unsigned int num_rows, unsigned int num_columns, typename T>
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
template<unsigned int num_rows, unsigned int num_columns, typename T>
Matrix<num_rows, num_columns, T> Matrix<num_rows, num_columns, T>::operator-(const Matrix &m) const {
    Matrix<num_rows, num_columns, T> result;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            result.elem[i][j] = elem[i][j] - m.elem[i][j];
        }
    }
    return result;
}


template<unsigned int num_rows, unsigned int num_columns, typename T>
void Matrix<num_rows, num_columns, T>::transpose() {
    Matrix<num_columns, num_rows, T> m = *this;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            elem[i][j] = m.elem[j][i];
        }
    }
}

template<unsigned int num_rows, unsigned int num_columns, typename T>
Vector<T, num_rows> Matrix<num_rows, num_columns, T>::getRow(unsigned int row) {
    Vector<T, num_rows> v;
    for (int i = 0; i < num_rows; i++) {
        v[i] = elem[row][i];
    }
    return v;
}


template<unsigned int num_rows, unsigned int num_columns, typename T>
Vector<T, num_columns> Matrix<num_rows, num_columns, T>::getColumn(unsigned int column) const {
    Vector<T, num_columns> v = {0};
    for (int i = 0; i < num_columns; i++) {
        v[i] = elem[i][column];
    }
    return v;
}

template<unsigned int num_rows, unsigned int num_columns, typename T>
Matrix<num_rows, num_columns, T> Matrix<num_rows, num_columns, T>::operator*(const T &scalar) const {
    Matrix<num_rows, num_columns, T> result;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            result.elem[i][j] = elem[i][j] * scalar;
        }
    }
    return result;
}

template<unsigned int num_rows, unsigned int num_columns, typename T>
Vector<T, num_columns> Matrix<num_rows, num_columns, T>::operator*(const Vector<T, num_columns> &v) const {
    Vector<T, num_columns> result;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            result[i] += elem[i][j] * v[j];
        }
    }
    return result;
}

template<unsigned int num_rows, unsigned int num_columns, typename T>
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

// To display the matrix in command line 
template<unsigned int num_rows, unsigned int num_columns, typename T>
void Matrix<num_rows, num_columns, T>::Display(){
    Matrix<num_rows, num_columns, T> m = *this;

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            std::cout<<m.elem[i][j] << "\t";
        }
        std::cout<<"\n";
    }
    
}



template<unsigned int num_rows, unsigned int num_columns, typename T>
void Matrix<num_rows, num_columns, T>::PartialPivotMatrix(Vector<T, num_columns> &v){
    Matrix<num_rows, num_columns, T> m = *this;

    auto temp = 0;
    auto temp2 =0;
    for (int i = 0; i < num_rows-1; i++)
    {
        for (int k = i+1; k < num_rows; k++)
        {
            if (std::abs(elem[i][i]) < std::abs(elem[k][i]))
            {
                
                for (int j = 0; j < num_columns; j++)
                {
                    temp = elem[i][j];
                    elem[i][j] = elem[k][j];
                    elem[k][j] = temp;
                }

                temp = v[i];
                v[i] = v[k];
                v[k] = temp;
                
            }
        }
        
    }
    
}

// Non-Singular Matrix ONLY, a check will be implemented as soon as Determinant() is complete
template<unsigned int num_rows, unsigned int num_columns, typename T>
Vector<T, num_columns> Matrix<num_rows, num_columns, T>::GaussianElimination(Vector<T, num_columns> &v) const {
    
    Matrix<num_rows, num_columns, T> m = *this;
    Vector<T, num_columns> coeff;
    m.PartialPivotMatrix(v);

    for (int j = 0; j < num_columns-1; j++)
    {
        for (int i = j+1; i < num_rows; i++)
        {
            if (m[i][j] != 0) // what if m[j][j] = 0, code breaks? TEST required
            {
                auto lam = m.elem[i][j]/m.elem[j][j];
                for (int k = j; k < num_columns; k++)
                {
                    m.elem[i][k] = m.elem[i][k] - lam*m.elem[j][k];
                }
                v[i] = v[i] - lam*v[j];
            }
            
        }
        
        
    }

    // Back substitution
    for (int k = num_rows-1; k > -1; k = k-1)
    {
        auto sigma = 0;
        for (int j = k+1; j < num_columns; j++)
        {
            sigma += (m.elem[k][j]*(float)coeff[j]);
        }
        coeff[k] = (v[k] - sigma)/m.elem[k][k];
    }
    
    
    return coeff;
    
}






