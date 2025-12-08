#include <iostream>
#include <iomanip>

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
    float number = 10;
    int n = 11;
    float res = 1;

    for (int i = 0; i < n; i++) {
        res *= number;

        std::cout << std::fixed << "Curr: " << res << std::endl;
        std::cout << "Bin: ";
        printFloatInBinary(res);
        std::cout << "\n";
    }

    return 0;
}
