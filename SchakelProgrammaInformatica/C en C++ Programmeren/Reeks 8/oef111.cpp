#include <iostream>
#include <vector>

typedef struct Person Person;

struct Person {
    std::string naam;
    int leeftijd;
};

template<typename T>
void schrijf(const std::vector<T> &v){
    if (v.size() == 0) {
        return;
    }

    std::cout << "[ ";
    std::cout << v[0];

    for (int i = 1; i < v.size(); i++){
        std::cout <<  " | " << v[i];
    }

    std::cout << " ]";
}

template<typename T>
void schrijf_person(const std::vector<T> &v) {
    if (v.size() == 0) {
        return;
    }

    std::cout << std::endl << "[ ";
    std::cout << v[0];

    for (int i = 1; i < v.size(); i++){
        std::cout <<  " | " << v[i];
    }

    std::cout << " ]";
}

template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
    }

    return out;
}

std::ostream& operator<<(std::ostream& out, const Person & p){
    out <<p.naam<<" ("<<p.leeftijd<<" j)";
    return out;
}

int main() {
    // vector van int's
    std::vector<int> container;
    container.push_back(1);
    container.push_back(5);
    container.push_back(8);
    container.push_back(10);
    container.push_back(3);
    container.push_back(100);

    schrijf(container);

    // Vector van person's
    Person p1;
    p1.naam = "Xavier Geerinck";
    p1.leeftijd = 21;

    std::vector<Person> container2;
    container2.push_back(p1);

    schrijf_person(container2);

    // Vector van Vectoren
    std::cout << std::endl;
    std::vector<std::vector<int>> v;
    std::vector<int> x1;
    x1.push_back(1);
    x1.push_back(2);
    x1.push_back(3);
    x1.push_back(4);
    x1.push_back(5);

    std::vector<int> x2;
    x2.push_back(1);
    x2.push_back(2);
    x2.push_back(3);
    x2.push_back(4);
    x2.push_back(5);

    std::vector<int> x3;
    x3.push_back(1);
    x3.push_back(2);
    x3.push_back(3);
    x3.push_back(4);
    x3.push_back(5);

    std::vector<int> x4;
    x4.push_back(1);
    x4.push_back(2);
    x4.push_back(3);
    x4.push_back(4);
    x4.push_back(5);

    std::vector<int> x5;
    x5.push_back(1);
    x5.push_back(2);
    x5.push_back(3);
    x5.push_back(4);
    x5.push_back(5);

    v.push_back(x1);
    v.push_back(x2);
    v.push_back(x3);
    v.push_back(x4);
    v.push_back(x5);

    //std::cout << x1;

    std::cout << v;//schrijf_vector(v);
}

