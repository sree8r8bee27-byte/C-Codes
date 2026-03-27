#include <iostream>

// Base template
template <unsigned int N>
struct Factorial {
    static const unsigned long long value = N * Factorial<N - 1>::value;
};

// Template specialization for 0 (Ending the recursion)
template <>
struct Factorial<0> {
    static const unsigned long long value = 1;
};

int main() {
    // Calculated by the compiler, not the CPU at runtime
    std::cout << "Factorial of 10: " << Factorial<10>::value << std::endl;
    return 0;
}
