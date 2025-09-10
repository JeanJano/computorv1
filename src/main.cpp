#include "computer.hpp"

int main(int ac, char **av) {
    string input = "";
    if (ac > 2) {
        cerr << "need the equation argument\nex: '5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0'" << endl;
        return (1);
    } else if (ac == 1)
        getline(cin, input);
    try {
        if (input.length() == 0)
            input = av[1];
        Polynome pol(input);
        pol.show();

    } catch (const char *e) {
        cerr << "error: " << e << endl;
    }

}