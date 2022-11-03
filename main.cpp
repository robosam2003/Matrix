#include "Matrix.h"

int main() {

    /*
    Matrix<3, 3> m;
    Matrix<3, 3> m2;

    m[0][0] = 12;
    m2[0][0] = 5;

    Matrix<3, 3> m3 = m*m2;
    std::cout << m3[0][1] << std::endl;

    Vector<double,3> v;

    v = m3.getColumn(0);
    std::cout << v[0] << std::endl;

    // testing scalar multiplication
    m = m3.operator*(3);
    std::cout<<m[0][0]<<std::endl;

    // testing multiplication of individual elem
    double mult = 0.78;
    double ans = mult*m[0][0];
    std::cout<< ans << std::endl;
    
    */

    // test for Gaussian Elimination [NOT READY TO BE TESTED: 2 ERRORS]
 
    Matrix<3,3> LS;
    LS[0][0] = 1;
    LS[0][1] = -1;
    LS[0][2] = 1;
    LS[1][0] = 2;
    LS[1][1] = 3;
    LS[1][2] = -1;
    LS[2][0] = 3;
    LS[2][1] = -2;
    LS[2][2] = -9;

    Vector<double, 3> B;
    B[0] = 8;
    B[1] = -2;
    B[2] = 9;

    Vector<double, 3> Out;
    Out = LS.GaussianElimination(B);

    // we should get 1,2,3
    std::cout<<Out[0] << " " << Out[1] << " " << Out[2] << std:: endl;

    

    return 0;
}

/*
Manual check

m = 12 0  0    *   m2 = 5 0 0
    0  0  0             0 0 0
    0  0  0             0 0 0
m3 = 60 0  0
     0  0  0
     0  0  0
*/