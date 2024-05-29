#include <iostream>
#include <stdexcept>

class Fraction {
    private:
        int m_numerator { 0 };
        int m_denominator { 1 };

    public:
        Fraction(int numerator, int denominator)
            :   m_numerator { numerator }, m_denominator { denominator }
        {
            if(m_denominator == 0) {
                throw std::runtime_error("Invalid fraction.");
            }
        }

        friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction){
            out << fraction.m_numerator << '/' << fraction.m_denominator;
            return out;
        }
};

int main() {
    std::cout << "Enter the numerator: ";
    int numerator {};
    std::cin >> numerator;

    std::cout << "Enter the denominator: ";
    int denominator {};
    std::cin >> denominator;

    try {
        Fraction fraction { numerator, denominator };
        std::cout << fraction << '\n';
    } catch(const std::exception& exception) {
        std::cerr << exception.what() << '\n';
    }

}