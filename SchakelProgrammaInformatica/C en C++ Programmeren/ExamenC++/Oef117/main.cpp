#include <map>
#include <vector>
#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::map;
using std::vector;

int main() {
    // Variables
    map<int, string> regels;
    vector<int> regelnummers;

    // Read IN
    ifstream in_regelnummers("regelnummers.txt");
    ifstream in_bijbel("nbible.txt");

    // Check if files open, anders exit met foutcode 1
    if (!in_regelnummers.is_open() || !in_bijbel.is_open()) {
        cout << "Kon bestanden niet openen";
        exit(1);
    }

    // Start met het inlezen van de regelnummers (gewoon regels, geen woorden dus << mag)
    string regel_nummer;
    while (in_regelnummers >> regel_nummer) {
        regels[atoi(regel_nummer.c_str())] = "test";
        regelnummers.push_back(atoi(regel_nummer.c_str()));
    }

    // Loop set regelnummers
//    for (map<int, string>::const_iterator i = regels.begin(); i != regels.end(); i++) {
//        cout << i->first << endl;
//    }

    // Ga door de bijbel, als we lijn vinden die in de map geset is, sla op
    string bijbel_regel;
    int regel_count = 0;
    while (!in_bijbel.eof()) {
        getline(in_bijbel, bijbel_regel);

        if (regels.count(regel_count)) {
            regels[regel_count] = bijbel_regel;
        }

        regel_count++;
    }

    // Print resultaat
    for (int i = 0; i < regelnummers.size(); i++) {
        cout << regels[regelnummers[i]] << endl;
    }
}