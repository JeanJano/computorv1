#ifndef POLYNOME_HPP
#   define POLYNOME_HPP


#   include "computer.hpp"
#   include <vector>
#   include <array>
#   include "Complex.hpp"

class Polynome {
    public:
        Polynome();
        Polynome(string equation);
        Polynome(const Polynome &cpy);
        ~Polynome();
        Polynome& operator=(const Polynome &cpy);

        void    show();

    private:
        void    find_degree();
        void    parse_equation_1();
        void    parse_equation_2();
        void    reduce_equation_1();
        void    reduce_equation_2();
        void    solution_1();
        void    solution_2();

        template <size_t N>
        void    fill_var(array<float*, N> &variable);
        string  format_string(float num, string degree);

        string          equation;
        string          reduce_form;
        int             degree;
        float           discriminant;
        // vector<float>   solutions;
        // left part of the equation
        float           a;
        float           b;
        float           c;
        // rigth part of the equation
        float           a_;
        float           b_;
        float           c_;

        float           x0;
        float           x1;
        float           x2;
        Complex         x1_;
        Complex         x2_;
};


#endif