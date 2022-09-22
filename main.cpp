#include "Matrix.h"

int main() {
    Matrix<double, 3, 3> m;

    m[0][0] = 12;
    cout<< m[0][0] << endl;


    return 0;
}
