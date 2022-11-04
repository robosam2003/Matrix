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


    // print the matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << m2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;

}
