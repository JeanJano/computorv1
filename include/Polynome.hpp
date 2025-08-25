#ifndef POLYNOME_HPP
#   define POLYNOME_HPP


#   include "computer.hpp"
#   include <vector>

class Polynome {
    public:
        Polynome();
        Polynome(string equation);
        Polynome(const Polynome &cpy);
        ~Polynome();
        Polynome& operator=(const Polynome &cpy);

    private:
        void    get_degree();

        string          equation;
        string          reduce_form;
        int             degree;
        vector<float>   solutions;
        float           a;
        float           b;
        float           c;
        float           x0;
        float           x1;
        float           x2;
};


#endif