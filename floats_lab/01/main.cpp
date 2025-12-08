#include <iostream>

void printBinary(unsigned int n) {
    for (int i = 31; i >= 0; --i) {
        unsigned int bit = (n >> i) & 1;
        std::cout << bit;
    }
    std::cout << std::endl;
}

union FloatUnion {
    float f;
    unsigned int n;
};

void printFloatInBinary(float number) {
    FloatUnion u;
    u.f = number;
    printBinary(u.n);
}

int main() {
    float x;
    std::cout << "Enter float: ";
    std::cin >> x;

    printFloatInBinary(x);
    return 0;
}
