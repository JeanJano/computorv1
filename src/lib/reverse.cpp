#include "computer.hpp"

void reverse(string &str, int n, int i) {
    if (n <= i)
        return;
    swap(str[i], str[n]);
    reverse(str, n - 1, i + 1);
}