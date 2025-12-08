#include <iostream>
#include <iomanip>

int main() {
    float number = 10;
    int n = 0;

    for (float i = 16767300; i < 20000000; i++) {

        std::cout << std::fixed << "Curr: " << i << std::endl;
        std::cout << "Int: " << (int)i << std::endl;
        std::cout << '\n';

        if (n == 16777310) { 
            break; 
        }
        n++;
    }

    return 0;
}
