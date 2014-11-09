#include <iostream>
#include <fstream>
#include <map>

/*
Never use using namespace, this is a bad practice
http://google-styleguide.googlecode.com/svn/trunk/cppguide.html#Namespaces
 */
int main() {
    std::ifstream in("lord.txt"); // Instantly open the file
    std::string word;

    std::map<std::string, int> m;

    // Map words
    while (in >> word) {
        // IF key doesn't exists, add it
        if (m.find(word) == m.end()) {
            m[word] = 0;
        }

        m[word]++;
    }

    // Print the frequency of the words :D
    std::map<std::string, int>::iterator i = m.begin();
    while (i != m.end()) {
        std::cout << i->second << " " << i->first << std::endl;
        i++;
    }
}