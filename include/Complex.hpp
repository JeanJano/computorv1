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

        void    set_real(float real);
        void    set_imag(float imag);

        string  get_real();
        string  get_imag();
        string  get_equation();

        void    divide_by(float num);

    private:
        int     find_grand_commun_demoninator(float a, float b);
        // void    simplify();
        float   real;
        float   imag;
        string  real_;
        string  imag_;
};


#endif