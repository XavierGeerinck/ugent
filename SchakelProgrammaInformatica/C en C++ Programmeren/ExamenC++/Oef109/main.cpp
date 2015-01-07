#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;

int main() {
    ifstream in1("paddestoel.txt");
    ifstream in2("stationnetje.txt");
    ofstream out("mix.txt");

    string s1; // even
    string s2; // oneven

    if (!in1.is_open() || !in2.is_open()) {
        cout << "Kon bestanden niet openen";
        exit(1);
    }

    getline(in2, s2); // Head start

    // While not at the end of one of the files, keep going
    while (!in1.eof() || !in2.eof()) {
        getline(in1, s1);
        getline(in2, s2);

        out << s1 << endl << s2 << endl;

        getline(in1, s1);
        getline(in2, s2);
    }

    in1.close();
    in2.close();
    out.close();

    cout << "Done";
}