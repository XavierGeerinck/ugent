#include "oef129.h"

void schrijf(const Breuk &b);
bool is_stambreuk(const Breuk &b);
Breuk som(const Breuk &b1, const Breuk &b2);
Breuk verschil(const Breuk &b1, const Breuk &b2);
Breuk vermenigvuldig(const Breuk &b1, const Breuk &b2);
Breuk quotient(const Breuk &b1, const Breuk &b2);
Breuk operator+(const Breuk &b1, const Breuk &b2);
Breuk operator-(const Breuk &b1, const Breuk &b2);
Breuk operator/(const Breuk &b1, const Breuk &b2);
Breuk operator*(const Breuk &b1, const Breuk &b2);
bool operator==(const Breuk &b1, const Breuk &b2);
std::ostream& operator<<(std::ostream& os, const Breuk &b);
std::istream& operator>>(std::istream& is, Breuk &b);
int ggd(int getal1, int getal2);

int main() {
    Breuk a(2, 5);
    Breuk b(1, -2);

    try {
        std::cout << a << " + " << b << " = " << (a + b) << std::endl;
        std::cout << a << " - " << b << " = " << (a - b) << std::endl;
        std::cout << a << " * " << b << " = " << (a * b) << std::endl;
        std::cout << a << " / " << b << " = " << (a / b) << std::endl;
    }
    catch (char * e) {
        std::cout << "Fout: " << e;
    }
    catch (...) {
        std::cout << "....";
    }

    Breuk c;
    std::cout << "Geef c op (onder de vorm teller/noemer): ";
    std::cin >> c;
    if (a == c) {
        std::cout << a << " is gelijk aan " << c << std::endl;
    } else {
        std::cout << a << " is niet gelijk aan " << c << std::endl;
    }
//
    std::cout << a << " * " << b << " * " << c << " = " << (a * b * c) << std::endl;

    Breuk d(2, 10);
    Breuk e;

    std::cout << d << " is stambreuk: " << is_stambreuk(d) << std::endl;
    std::cout << d << " + " << e << " = " << (d + e) << std::endl;
    std::cout << d << " * " << e << " = " << d.vermenigvuldig_met(e) << std::endl;
}

bool is_stambreuk(const Breuk &b) {
    return b.get_teller() == 1;
}

void schrijf(const Breuk &b) {
    b.schrijf(std::cout);
}

Breuk som(const Breuk &b1, const Breuk &b2) {
    int deler = ggd(b1.get_noemer(), b2.get_noemer());
    int teller = ((b2.get_noemer() / deler) * b1.get_teller()) + ((b1.get_noemer() / deler) * b2.get_teller());
    int noemer = b1.get_noemer() / deler * b2.get_noemer();
    return Breuk(teller, noemer);
}

Breuk verschil(const Breuk &b1, const Breuk &b2) {
    int deler = ggd(b1.get_noemer(), b2.get_noemer());
    int teller = ((b2.get_noemer() / deler) * b1.get_teller()) - ((b1.get_noemer() / deler) * b2.get_teller());
    int noemer = b1.get_noemer() / deler * b2.get_noemer();

    if (noemer < 0) {
        noemer *= -1;
    }

    return Breuk(teller, noemer);
}

Breuk vermenigvuldig(const Breuk &b1, const Breuk &b2) {
    int noemer = b1.get_noemer() * b2.get_noemer();
    int teller = b1.get_teller() * b2.get_teller();

    return Breuk(teller, noemer);
}

Breuk quotient(const Breuk &b1, const Breuk &b2) {
    Breuk temp(b2.get_noemer(), b2.get_teller());
    return vermenigvuldig(b1, temp);
}

Breuk operator+(const Breuk &b1, const Breuk &b2) {
    Breuk result(som(b1, b2));
    return result;
}

Breuk operator-(const Breuk &b1, const Breuk &b2) {
    Breuk result(verschil(b1, b2));
    return result;
}

Breuk operator/(const Breuk &b1, const Breuk &b2) {
    Breuk result(quotient(b1, b2));
    return result;
}

Breuk operator*(const Breuk &b1, const Breuk &b2) {
    Breuk result(vermenigvuldig(b1, b2));
    return result;
}

bool operator==(const Breuk &b1, const Breuk &b2) {
    return (b1.get_noemer() == b2.get_noemer()) && (b1.get_teller() == b2.get_teller());
}

std::ostream& operator<<(std::ostream& os, const Breuk &b) {
    b.schrijf(os);
    return os;
}

std::istream& operator>>(std::istream& is, Breuk &b) {
    int t, n;
    scanf("%d/%d", &t, &n);
    b.set_teller(t);
    b.set_noemer(n);
}