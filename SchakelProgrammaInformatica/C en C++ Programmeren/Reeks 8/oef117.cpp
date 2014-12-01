/*
Regelnummers
180
40
300
20

20 Zin
40 is
180 Test
300 Een
 */
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

int main() {
    /*
        Map met index, dit is de originele plaats

        Vb:
        180 0
        40  1
        300 2
        20  3

        Map Houd bij:
        20  3
        40  1
        180 0
        300 2

        Vector<int, Std::map<int, std:;string>>
        Index RegelNummer
        RegelNummer String
     */
    // Store as: vector<index, std::map<regelnummer, regel>>

    // std::map<regel_nummer, zin>
    std::map<int, std::string> regels;
    std::vector<int> volgorde;

    // Input streams
    std::ifstream in_regels("regelnummers.txt");
    std::ifstream in_bijbel("nbible.txt");

    // Maak Key aan voor temp value
    int regel_nummer = 0, i = 0;
    while (in_regels >> regel_nummer) {
        regels[regel_nummer] = "";
        volgorde.push_back(regel_nummer);
        i++;
    }

    // Print hashmap with regels
    for (std::map<int, std::string>::iterator it = regels.begin(); it != regels.end(); it++) {
        std::cout << std::endl << it->first << " " << it->second;
    }

    // Loop through the bijbel
    std::string regel;
    regel_nummer = 0;
    while (in_bijbel >> regel) {
        if (regels.find(regel_nummer) != regels.end()) {
            //std::cout << "Print index: " << index_cache[regel_nummer] << std::endl;
            regels[regel_nummer] = regel;
        }

        regel_nummer++;
    }

    // Loop opnieuw door de lijst met regels, deze keer printen we de value in onze hashmap
    for (int i = 0; i < volgorde.size(); i++) {
        std::cout << " " << regels[volgorde[i]];
    }



    in_regels.close();
    in_bijbel.close();
}