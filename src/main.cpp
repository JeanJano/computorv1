#include "computer.hpp"


int main(int ac, char **av) {
    if (ac != 2) {
        cerr << "need the equation argument\nex: '5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0'" << endl;
        return (1);
    }
    // cout << "coucou computer" << endl;
    string input = av[1];
    Polynome test(input);
}