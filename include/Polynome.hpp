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
        void    parse_equation();
        void    reduce_equation();
        void    solve();
        void    solution_0();
        void    solution_1();
        void    solution_2();

        string  format_string(float num, string degree);

        string          equation;
        string          reduce_form;
        int             degree;
        float           discriminant;
        vector<float>   left_values;
        vector<float>   right_values;

        float           a;
        float           b;
        float           c;

        float           x0;
        float           x1;
        float           x2;
        Complex         x1_;
        Complex         x2_;
};


#endif