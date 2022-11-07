#include "Matrix.h"


int main() {
    Matrix<3, 3> m = {{1.1,2.2,3.3},
                      {4.4,5.5,6.6},
                      {7.7,8.8,9.9}};

    Matrix<2, 2, int> m2 = (Matrix<2, 2, int>) m;
    // m2 = 1 2 3 0
    //      4 5 6 0
    //      7 8 9 0
    //      0 0 0 0




    Vector<double, 3> B;
    B[0] = 4;
    B[1] = 15;
    B[2] = 1;

    Vector<double, 3> Out = {0,0,0};
    Out = m.GaussianElimination(B);
    
    std::cout<<Out[0] << " " << Out[1] << " " << Out[2] << std:: endl;

     // partial pivot test

    m.PartialPivotMatrix(B); // success
    m.Display();

   /*
    std::cout<<B[0]<<std::endl;
    std::cout<<B[1]<<std::endl;
    std::cout<<B[2]<<std::endl;
   */
   
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