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
    discriminant = 0;
    x0 = 0;
    x1 = 0;
    x2 = 0;
    cout << equation << endl;
    find_degree();
    if (degree == 1) {
        parse_equation_1();
        reduce_equation_1();
        solution_1();
    } else {
        parse_equation_2();
        reduce_equation_2();
        solution_2();
    }
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

void    Polynome::parse_equation_1() {
    array<float*, 4>    variables = {&b, &a, &b_, &a_};

    fill_var(variables);
}

void    Polynome::parse_equation_2() {
    array<float*, 6>    variables = {&c, &b, &a, &c_, &b_, &a_};

    fill_var(variables);
}

void    Polynome::reduce_equation_1() {
    a = a - a_;
    b = b - b_;

    string b_form = float_to_string(b) + " * X^0 ";
    string a_form = format_string(a, "X^1");

    reduce_form += b_form + a_form;
    reduce_form += "= 0";
}

void    Polynome::reduce_equation_2() {
    a = a - a_;
    b = b - b_;
    c = c - c_;

    string c_form = float_to_string(c) + " * X^0 ";
    string b_form = format_string(b, "X^1");
    string a_form = format_string(a, "X^2");

    reduce_form += c_form + b_form + a_form;
    reduce_form += "= 0";
}

void    Polynome::solution_1() {
    if (b == 0 && a != 0) {
        x0 = 0;
    } else if (a == 0) {
        // no solution;
        throw "No Solution";
    } else {
        x0 = -b / a;
    }
    cout << x0 << endl;
}

void    Polynome::solution_2() {
    discriminant = b * b - 4 * a *c;

    cout << discriminant << endl;
    if (discriminant < 0) {

    } else if (discriminant == 0) {
        x0 = -b / (2 * a);
        cout << x0 << endl;
    } else if (discriminant > 0) {
        x1 = (-b - sqrt(discriminant)) / (2 * a);
        x2 = (-b + sqrt(discriminant)) / (2 * a);
        cout << x1 << endl << x2 << endl;
    }
}


template <size_t N>
void    Polynome ::fill_var(array<float*, N> &variables) {
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
        *variables[i] = atof(var.c_str()) * sign;
        pos += 1;
        i++;
    }
}

string  Polynome::format_string(float num, string degree) {
    string str = "";
    
    if (num < 0)
        str = "- " + float_to_string(num * -1) + " * " + degree + " ";
    else
        str = "+ " + float_to_string(num) + " * " + degree + " ";
    return str; 
}