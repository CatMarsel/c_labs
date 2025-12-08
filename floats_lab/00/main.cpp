#include <iostream>

void printBinary(unsigned int n) {
    for (int i = 31; i >= 0; --i) {
        unsigned int bit = (n >> i) & 1;
        std::cout << bit;
    }
    std::cout << std::endl;
}

int main() {
    unsigned int x;
    std::cout << "Enter number: ";
    std::cin >> x;

    printBinary(x);
    return 0;
}
