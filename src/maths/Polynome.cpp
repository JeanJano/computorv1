#include "Polynome.hpp"

Polynome::Polynome() {
    equation = "";
}

Polynome::Polynome(string input) {
    equation = input;
    degree = 0;
    discriminant = 0;
    x0 = 0;
    x1 = 0;
    x2 = 0;
    a = 0;
    b = 0;
    c = 0;
    parse_equation();
    reduce_equation();
    find_degree();
    solve();
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
    if (degree != 0)
        cout << "Polynomial degree: " << degree << endl;
    if (degree == 0) {
        if (b != 0)
            cout << "No solution." << endl;
        else if (b == 0)
            cout << "Any real number is a solution." << endl;
    } else if (degree == 1) {
        cout << "The solution is:" << endl;
        cout << x0 << endl;
    } else if (degree == 2) {
        if (discriminant < 0) {
            cout << "Discriminant is strictly negative, the two complex solutions are:" << endl;
            cout << x1_.to_string() << endl;
            cout << x2_.to_string() << endl;
        } else if (discriminant == 0)
            cout << x0 << endl;
        else if (discriminant > 0) {
            cout << "Discriminant is strictly positive, the two solutions are:" << endl;
            cout << x1 << endl;
            cout << x2 << endl;
        }
    } else if (degree > 2)
        cout << "The polynomial degree is strictly greater than 2, I can't solve." << endl;
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
}

void    Polynome::reduce_equation() {
    int l = right_values.size();
    auto left_it = left_values.begin();
    auto right_it = right_values.begin();

    for (int i = 0; i < l; i++) {
        float left = *left_it;
        float right = *right_it;
        left = left - right;
        *left_it = left;
        *right_it = 0;

        ++left_it;
        ++right_it;
    }

    l = left_values.size();
    left_it = left_values.begin();
    reduce_form += float_to_string(*left_it) + " * X^0 ";
    ++left_it;
    for (float deg = 1; deg < l; deg++) {
        string d = float_to_string(deg);
        reduce_form += format_string(*left_it, "X^" + d);
        
        ++left_it;
    }

    reduce_form += "= 0";
}

void    Polynome::solve() {
    if (degree == 0)
        solution_0();
    if (degree == 1)
        solution_1();
    else if (degree == 2) 
        solution_2();
}

void    Polynome::solution_0() {
    auto it = left_values.begin();
    b = *it;
}

void    Polynome::solution_1() {
    auto it = left_values.begin();
    b = *it;
    ++it;
    a = *it;

    if (b == 0 && a != 0)
        x0 = 0;
    else if (a == 0)
        throw "No Solution";
    else
        x0 = -b / a;
}

void    Polynome::solution_2() {
    auto it = left_values.begin();
    c = *it;
    ++it;
    b = *it;
    ++it;
    a = *it;

    discriminant = b * b - 4 * a *c;

    if (discriminant < 0) {
        float real_part = -b / (2 * a);
        float imag_part = sqrt(-discriminant) / (2 * a);

        x1_ = Complex(real_part, -imag_part);
        x2_ = Complex(real_part, imag_part);

    } else if (discriminant == 0) {
        x0 = -b / (2 * a);
    } else if (discriminant > 0) {
        x1 = (-b - sqrt(discriminant)) / (2 * a);
        x2 = (-b + sqrt(discriminant)) / (2 * a);
    }
}

void    Polynome::parse_equation() {
    size_t  pos = 0;
    size_t  equal_pos = equation.find('=', 0);
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

        if (pos < equal_pos) {
            left_values.push_back(atof(var.c_str()) * sign);
        } else {
            right_values.push_back(atof(var.c_str()) * sign);
        }
        pos++;
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