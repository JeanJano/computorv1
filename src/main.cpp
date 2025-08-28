#include "computer.hpp"

//todo:
// refaire equation nb complexe
// calculer reduced form pour tout les cas
// revoir cas avec degree 0
int main(int ac, char **av) {
    if (ac != 2) {
        cerr << "need the equation argument\nex: '5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0'" << endl;
        return (1);
    }
    try {
        string input = av[1];
        Polynome pol(input);
        pol.show();

    } catch (const char *e) {
        cerr << "error: " << e << endl;
    }

}