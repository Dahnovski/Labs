#include <iostream>

class Complex
{
private:
    double real;
    double imaginary;

public:
    // Конструкторы
    Complex() : real(0), imaginary(0) {}
    Complex(double r, double i) : real(r), imaginary(i) {}

    /* methods for getting values (setters and getters): мы тут получаем доступ к действительной и мнимой части */
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    /* Операторы сложения и вычитания для комплексных чисел */
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    /* Операторы сложения и вычитания для действительных чисел */
    Complex operator+(const double& other) const
    {
        return Complex(real + other, imaginary);
    }

    Complex operator-(const double& other) const
    {
        return Complex(real - other, imaginary);
    }

    /* Оператор присваивания */
    Complex& operator=(const Complex& other)
    {
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    /*
     * operators for input and output (при помощи дружественных функций)
     * std::ostream: — базовый класс для потоков вывода (например, std::cout - стандартный вывод).
     * функция принимает два параметра - поток вывода 'os' и 'complex' - объект класса который мы хотим вывести
     */
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex)
    {
        os << complex.real;
        if (complex.imaginary >= 0)
            os << " + " << complex.imaginary << "i";
        else
            os << " - " << -complex.imaginary << "i";
        return os;
    }

    /* опертор вывода из потока */
    friend std::istream& operator>>(std::istream& is, Complex& complex)
    {
        std::cout << "Enter real part: ";
        is >> complex.real;
        std::cout << "Enter imaginary part: ";
        is >> complex.imaginary;
        return is;
    }
};

int
main()
{
    Complex a(1, 2);
    Complex b(3, 4);

    Complex c = a + b;
    std::cout << "a + b = " << c << std::endl;

    c = a - b;
    std::cout << "a - b = " << c << std::endl;

    c = a + 7.3;
    std::cout << "a + 7.3 = " << c << std::endl;

    c = b - 2.0;
    std::cout << "b - 2.0 = " << c << std::endl;

    Complex d;
    std::cin >> d;
    std::cout << "Complex number which was entered: " << d << std::endl;

    return EXIT_SUCCESS;
}