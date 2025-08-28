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

string  Complex::get_equation() {
    string sign = " + ";
    if (imag < 0) {
        sign = " - ";
        imag_.erase(0, 1);
    }
    string equation = real_ + sign + imag_;
    return equation;
}

void    Complex::divide_by(float num) {
    float div = num;
    int dem1 = find_grand_commun_demoninator(abso(real), abso(num));
    real /= dem1;
    num /= dem1;
    // cout << "real: " << real << " num: " << num << endl;
    real_ = float_to_string(real) + "/" + float_to_string(num);
    int dem2 = find_grand_commun_demoninator(abso(imag), abso(div));
    imag /= dem2;
    div /= dem2;
    // cout << "imag: " << imag << " div: " << div << endl;
    imag_ = float_to_string(imag) + "i/" + float_to_string(div);
}

int     Complex::find_grand_commun_demoninator(float a, float b) {
    int c = a * 100000;
    int d = b * 100000;
    while (d != 0) {
        int temp = d;
        d = c % d;
        c = temp;
    }
    return c * 0.00001;
}