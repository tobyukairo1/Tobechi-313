#include <iostream>
#include "matrix.hpp"

int main() {
    //  A = [6 4; 8 3]
    Matrix A(2,2);
    A(0,0)=6; A(0,1)=4;
    A(1,0)=8; A(1,1)=3;

    //  B = [1 2 3; 4 5 6]
    Matrix B(2,3);
    B(0,0)=1; B(0,1)=2; B(0,2)=3;
    B(1,0)=4; B(1,1)=5; B(1,2)=6;

    //  C = [2 4 6; 1 3 5]
    Matrix C(2,3);
    C(0,0)=2; C(0,1)=4; C(0,2)=6;
    C(1,0)=1; C(1,1)=3; C(1,2)=5;

    // D = A + (3*B) * C^T
    Matrix D = A + (B * 3.0) * C.transpose();

    std::cout << "D =\n" << D;
    return 0;
}
