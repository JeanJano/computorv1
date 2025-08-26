#ifndef POLYNOME_HPP
#   define POLYNOME_HPP


#   include "computer.hpp"
#   include <vector>
#   include <array>

class Polynome {
    public:
        Polynome();
        Polynome(string equation);
        Polynome(const Polynome &cpy);
        ~Polynome();
        Polynome& operator=(const Polynome &cpy);

    private:
        void    get_degree();
        void    parse_equation();
        void    reduce_equation();

        string          equation;
        string          reduce_form;
        int             degree;
        vector<float>   solutions;
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
};


#endif