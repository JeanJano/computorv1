#ifndef COMPLEX_HPP
#   define COMPLEX_HPP

using namespace std;
#   include <iostream>
#   include <string>
std::string float_to_string(double value);
float       abso(float n);

class Complex {
    public:
        Complex();
        Complex(float real, float imag);
        Complex(const Complex &cpy);
        ~Complex();
        Complex& operator=(const Complex &cpy);
        Complex operator/(float d) const;

        void    set_real(float real);
        void    set_imag(float imag);
        string  to_string() const;

    private:
        float   real;
        float   imag;
};


#endif