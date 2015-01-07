#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::acos;
using std::ostream;

class Figure {
public:
    virtual double get_surface() const = 0;
    virtual double get_outline() const = 0;

    friend ostream& operator<<(ostream &os, const Figure &f) {
        os << "Surface: " << f.get_surface() << endl;
        os << "Outline: " << f.get_outline() << endl;
        return os;
    }
};

class Rectangle : public Figure {
public:
    Rectangle(int length, int width) : m_length(length), m_width(width) {};
    double get_surface() const { return m_length * m_width; }
    double get_outline() const { return m_length * 2 + m_width * 2; }

private:
    int m_length;
    int m_width;
};

class Square : public Rectangle {
public:
    Square(int side) : Rectangle(side, side) {};
};

class Circle : public Figure {
public:
    Circle(int radius) : m_radius(radius) {};
    double get_surface() const { return M_PI * m_radius * m_radius; }
    double get_outline() const { return 2 * M_PI * m_radius; }

private:
    int m_radius;
};

int main() {
    Circle circle(1);           // Radius 1
    cout << circle << endl;     // Print: Surface: xxx Outline: xxx

    Rectangle rectangle(2, 3);  // Length 2, Width 3
    cout << rectangle << endl;  // Print: Surface: xxx Outline: xxx

    Square square(4);       // Side 4
    cout << square << endl;   // Print: Surface: xxx Outline: xxx

    return 0;
}