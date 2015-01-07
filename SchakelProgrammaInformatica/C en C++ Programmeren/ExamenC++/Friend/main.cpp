#include <iostream>

class A {
    int i;

    public:
        A(int _i = 0) : i(_i) {}
        int get_i() const;
        friend int g(const A &a);
};

int A::get_i() const { return i; }
int g(const A &a) { return a.i; }

int main() {
    A a(7);

    std::cout << a.get_i() << " " << g(a);
    return 0;
}