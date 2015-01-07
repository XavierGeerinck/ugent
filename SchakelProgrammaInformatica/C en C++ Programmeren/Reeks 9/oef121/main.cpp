#include "oef121.h"

Breuk* som(Breuk &b1, Breuk &b2);
void schrijf(const Breuk &b);
bool is_stambreuk(const Breuk &b);

int main() {
    Breuk b(121, 11);
    b.schrijf(std::cout);
    b.normaliseer();
    b.schrijf(std::cout);

    Breuk b1(5, 12);
    Breuk b2(2, 3);

    Breuk * result = som(b1, b2);
    schrijf(*result);

    Breuk b_stam(1, 15);

    std::cout << "Is 1/15 stam? " << is_stambreuk(b_stam) << std::endl;
    std::cout << "Is 13/12 stam? " << is_stambreuk(*result) << std::endl;

    delete result;
}

bool is_stambreuk(const Breuk &b) {
    return b.get_teller() == 1;
}

void schrijf(const Breuk &b) {
    b.schrijf(std::cout);
}

Breuk* som(Breuk &b1, Breuk &b2) {
    int t1 = b1.get_teller() * b2.get_noemer();
    int t2 = b2.get_teller() * b1.get_noemer();

    int nieuwe_noemer = b1.get_noemer() * b2.get_noemer();

    Breuk * n = new Breuk((t1 + t2), nieuwe_noemer);
    n->normaliseer();

    return n;
}