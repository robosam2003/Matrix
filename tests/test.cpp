#include "gtest/gtest.h"
#include "../Matrix.h"

// Multiplication
TEST(multiplication, by_scalar) {
    Matrix<3, 3> m = {{1,2,3},
                      {4,5,6},
                      {7,8,9}};
    Matrix<3, 3> m2 = {{2,4,6},
                       {8,10,12},
                       {14,16,18}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(m2[i][j], m[i][j] * 2);
        }
    }
}

TEST(multiplication, one_by_one){
    Matrix<1,1> m = {{1}};
    Matrix<1,1> n = {{2}};
    Matrix<1,1> o = m*n;
    EXPECT_EQ(o[0][0], 2);
}

TEST(multiplication, two_by_two){
    Matrix<2,2> m = {{1,2},
                     {3,4}};
    Matrix<2,2> n = {{5,6},
                     {7,8}};
    Matrix<2,2> o = m*n;
    EXPECT_EQ(o[0][0], 19);
    EXPECT_EQ(o[0][1], 22);
    EXPECT_EQ(o[1][0], 43);
    EXPECT_EQ(o[1][1], 50);
}

// Addition
TEST(addition, one_by_one){
    Matrix<1,1> m = {{1}};
    Matrix<1,1> n = {{2}};
    Matrix<1,1> o = m+n;
    EXPECT_EQ(o[0][0], 3);
}

//int multiply() {
//    int test_result = 0;
//
//    // test 1 x 1
//    Matrix<1, 1> m11_1 = {{1}};
//    Matrix<1, 1> m11_2 = {{2}};
//    Matrix<1, 1> m11_3 = m11_1 * m11_2;
//    // assert truth
//    if (m11_3[0][0] != 2) {
//        test_result = 1;
//    }
//
//    // test 2 x 2
//    Matrix<2, 2> m22_1 = {{1, 2},
//                          {3, 4}};
//    Matrix<2, 2> m22_2 = {{5, 6},
//                          {7, 8}};
//    Matrix<2, 2> m22_3 = m22_1 * m22_2;
//
//    return test_result;
//
//}
//
//int main() {
//    return multiply();
//}