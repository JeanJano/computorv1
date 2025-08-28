#include "Polynome.hpp"

Polynome::Polynome() {
    equation = "";
}

Polynome::Polynome(string input) {
    equation = input;
    degree = 0;
    a = 0;
    b = 0;
    c = 0;
    a_ = 0;
    b_ = 0;
    c_ = 0;
    cout << equation << endl;
    find_degree();
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

void    Polynome::show() {
    cout << "Reduced form: " << reduce_form << endl;
    cout << "Polynomial degree: " << degree << endl;
}

void    Polynome::find_degree() {
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
}

void    Polynome::parse_equation() {
    array<float*, 6>    test = {&c, &b, &a, &c_, &b_, &a_};
    size_t              pos = 0;
    int                 i = 0;
    
    while ((pos = equation.find('X', pos)) != string::npos) {
        string  var = "";
        int     sign = 1;
        int     j = 4;

        for (; isdigit(equation[pos - j]) || equation[pos - j] == '.'; j++) {
            var += equation[pos - j];
        }
        j += 1;
        if (equation[pos - j] == '-')
            sign = -1;
        else if (pos - j > 5000000000 && equation[0] == '-')
            sign = -1;
        else if (equation[pos - j - 1] == '=')
            sign = -1;
        
        reverse(var, var.length() - 1, 0);
        *test[i] = atof(var.c_str()) * sign;
        pos += 1;
        i++;
    }
}

void    Polynome::reduce_equation() {
    a = a - a_;
    b = b - b_;
    c = c - c_;

    string c_form = float_to_string(c) + " * X^0 ";
    string b_form = format_string(b, "X^1");
    string a_form = format_string(a, "X^2");

    reduce_form += c_form + b_form + a_form;
    reduce_form += "= 0";
}



string  Polynome::format_string(float num, string degree) {
    string str = "";
    
    if (num < 0)
        str = "- " + float_to_string(num * -1) + " * " + degree + " ";
    else
        str = "+ " + float_to_string(num) + " * " + degree + " ";
    return str; 
}