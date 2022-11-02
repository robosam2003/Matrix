#include "Matrix.h"

int main() {
    Matrix<3, 3> m;
    Matrix<3, 3> m2;

    m[0][0] = 12;
    m2[0][0] = 5;

    Matrix<3, 3> m3 = m*m2;
    std::cout << m3[0][0] << std::endl;

    return 0;
}
