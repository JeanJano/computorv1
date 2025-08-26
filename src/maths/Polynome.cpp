#include "Polynome.hpp"

Polynome::Polynome() {
    equation = "";
}

Polynome::Polynome(string input) {
    equation = input;
    degree = 0;
    cout << equation << endl;
    get_degree();
    parse_equation();
    reduce_equation();
}

Polynome::Polynome(const Polynome &cpy) {
    if (this != &cpy)
        *this = cpy;
}

Polynome    &Polynome::operator=(const Polynome &cpy) {
    if (this != &cpy) {
        this->equation = cpy.equation;
    }
    return (*this);
}

Polynome::~Polynome() {

}

void    Polynome::get_degree() {
    size_t pos = 0;

    while ((pos = equation.find('X', pos)) != string::npos) {
        string sub = equation.substr(pos + 2, 1);
        int deg = atoi(sub.c_str());
        if (deg > degree)
            degree = deg;
        pos += 1;
    }

    if (degree > 2)
        throw "polynomial degree can not be above 2";

    // cout << degree << endl;
}

// to do: recuper le signe + ou -
void    Polynome::parse_equation() {
    array<float*, 6>    test = {&c, &b, &a, &c_, &b_, &a_};
    size_t              pos = 0;
    int                 i = 0;

    while ((pos = equation.find('X', pos)) != string::npos) {
        string var = "";
        for (int i = 4; isdigit(equation[pos - i]) || equation[pos - i] == '.'; i++) {
            var += equation[pos - i];
        }
        reverse(var, var.length() - 1, 0);
        *test[i] = atof(var.c_str());
        pos += 1;
        i++;
    }
    // cout << "a=" << a << " b=" << b << " c=" << c << " a'=" << a_ << " b'=" << b_ << " c'=" << c_ << endl;
}

// to do: prendre en compte l'operation avec le signe et afficher avec le signe
void    Polynome::reduce_equation() {
    a = a - a_;
    b = b - b_;
    c = c - c_;

    cout << c << " X^0 " << b << " X^1 " << a << " X^2" << endl;
}