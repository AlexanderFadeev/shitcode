#include <iostream>
#include <vector>

using namespace std;

void printPrimes(ostream& out, int lim) {
    if (lim < 2) {
        return;
    }

    out << "2\n";

    int i = 3;
    vector<char> v(lim/2, true);
    for (; i * i <= lim; i += 2) {
        if (!v[i/2 - 1]) {
            continue;
        }

        for (int j = 3 * i; j <= lim; j += 2 * i) {
            v[j/2 - 1] = false;
        }

        out << i << '\n';
    }

    for (; i <= lim; i += 2) {
        if (!v[i/2 - 1]) {
            continue;
        }

        out << i << '\n';
    }
}

int main() {
    const int lim = 1e8;

    printPrimes(cout, lim);
}