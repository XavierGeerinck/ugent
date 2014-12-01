#include <string>
#include <iostream>

int main() {
    char c = 'x';
    std::string s = "" + c;
    std::cout << "karakter "<< c <<" omgezet: "<< s << "." << std::endl;

    char k = 'y';
    std::string w = "";
    w += k;
    std::cout << "karakter "<< k <<" omgezet: "<< w << "." << std::endl;
}