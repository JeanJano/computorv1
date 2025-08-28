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

void    Complex::set_real(float real) {
    this->real = real;
    real_ = float_to_string(real);
}

void    Complex::set_imag(float imag) {
    this->imag = imag;
    imag_ = float_to_string(imag) + "i";
}

string   Complex::get_real() {
    return real_;
}

string   Complex::get_imag() {
    return imag_;
}

void    Complex::divide_by(float num) {
    int dem = find_grand_commun_demoninator(real, num);
    // real /= num;
}

int     Complex::find_grand_commun_demoninator(float a, float b) {
    int c = a * 100000;
    int d = b * 100000;
    while (d != 0) {
        int temp = d;
        d = c % d;
        c = temp;
    }
    return c;
}