#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>


double f(double x) {
    return x * x;          // x^2
}

double f_derivative(double x) {
    return 2.0 * x;        // 2x
}

double F_antiderivative(double x) {
    return x * x * x / 3.0; // x^3 / 3
}


void generateFunctionCsv(const std::string &filename, int points) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Cannot open file " << filename << " for writing\n";
        return;
    }

    out << "x,f,df,F\n";

    double a = 0.0;
    double b = 1.0;
    double h = (b - a) / (points - 1);

    for (int i = 0; i < points; ++i) {
        double x = a + i * h;
        double fx = f(x);
        double dfx = f_derivative(x);
        double Fx = F_antiderivative(x);
        out << std::setprecision(15) << x << "," << fx << "," << dfx << "," << Fx << "\n";
    }

    out.close();

}

// Численное интегрирование методом прямоугольников
// и запись результатов для float и double
void generateIntegralCsv(const std::string &filename,
                         int startN, int steps) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Cannot open file " << filename << " for writing\n";
        return;
    }

    // Заголовок
    out << "N,float_result,double_result\n";

    double a = 0.0;
    double b = 1.0;

    for (int k = 0; k < steps; ++k) {
        int N = startN * (1 << k); // N = startN * 2^k

        // double
        double h_d = (b - a) / static_cast<double>(N);
        double sum_d = 0.0;

        // float
        float h_f = static_cast<float>((b - a) / static_cast<double>(N));
        float sum_f = 0.0f;

        for (int i = 0; i < N; ++i) {
            // метод левых прямоугольников: x_i = a + i*h
            double x_d = a + i * h_d;
            float  x_f = static_cast<float>(a) + i * h_f;

            sum_d += f(x_d);
            sum_f += static_cast<float>(f(static_cast<double>(x_f)));
        }

        double integral_d = sum_d * h_d;
        float  integral_f = sum_f * h_f;

        out << N << ","
            << std::setprecision(15) << integral_f << ","
            << std::setprecision(15) << integral_d << "\n";
    }

    out.close();

}

int main() {

    generateFunctionCsv("/Users/maksimkuzin/Documents/МФТИ/1_семестр/информатика/floats_lab/function.csv", 1000);


    int startN = 10;
    int steps = 10;
    generateIntegralCsv("/Users/maksimkuzin/Documents/МФТИ/1_семестр/информатика/floats_lab/integrals.csv", startN, steps);


    return 0;
}
