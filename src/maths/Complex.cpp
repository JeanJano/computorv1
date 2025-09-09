#include "Complex.hpp"

Complex::Complex() {
}

Complex::Complex(float real, float imag) {
    this->real = real;
    this->imag = imag;
}

Complex::Complex(const Complex &cpy) {
    if (this != &cpy)
        *this = cpy;
}

Complex    &Complex::operator=(const Complex &cpy) {
    if (this != &cpy) {
        this->real = cpy.real;
        this->imag = cpy.imag;
    }
    return (*this);
}

Complex::~Complex() {

}

void    Complex::set_real(float r) {
    real = r;
}

void    Complex::set_imag(float i) {
    imag = i;
}

string  Complex::to_string() const {
    string res = float_to_string(real);
    if (imag >= 0)
        res += " + " + float_to_string(imag) + "i";
    else
        res += " - " + float_to_string(-imag) + "i";
    return res;
}