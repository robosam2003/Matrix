#include "Matrix.h"


int main() {
    Matrix<3, 3> m = {{1,2,3},
                      {4,5,6},
                      {7,8,9}};

    // print the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;

}
