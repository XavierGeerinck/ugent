#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]) {
    string line;
    char * p_letter;
    char letter;

    ifstream in_stream(argv[1]);

//    while (getline(in_stream, line)) {
//        cout << line << endl;
//        cout << "X" << endl;
//    }

//    // 1. char inlezen met cin >> (die versie staat er al)
//    cin >> letter;
//    while(letter != 'X'){
//        cout << "*" << letter << "*" << endl;
//        cin >> letter;
//    }
//
//    // 2. char inlezen met cin.get()
//    letter = (char)cin.get();
//    while(letter != 'X'){
//        cout << "*" << letter << "*" << endl;
//        cin >> letter;
//    }
//
//    // 3. char inlezen met getline(cin,..)
//    cin.getline(&letter, 1);
//    while(letter != 'X'){
//        cout << "*" << letter << "*" << endl;
//        cin >> letter;
//    }
//
//    // 4. string inlezen met cin >>
//    cin >> line;
//    while(line != "X"){
//        cout << "*" << line << "*" << endl;
//        cin >> line;
//    }
//
//    // 5. string inlezen met cin.get()
//    line = cin.get();
//    while(line != "X"){
//        cout << "*" << line << "*" << endl;
//        cin >> line;
//    }
//
//    // 6. string inlezen met getline(cin,..)
//    getline(cin, line);
//    while(line != "X"){
//        cout << "*" << line << "*" << endl;
//        cin >> line;
//    }

    // 7. char* inlezen met cin >>
    cin >> *p_letter;
    while(*p_letter != 'X'){
        cout << "*" << *p_letter << "*" << endl;
        cin >> *p_letter;
    }
//
//    // 8. char* inlezen met cin.get()
//    cin >> letter;
//    while(letter != 'X'){
//        cout << "*" << letter << "*" << endl;
//        cin >> letter;
//    }
//
//    // 9. char* inlezen met getline(cin,..)
//    cin >> letter;
//    while(letter != 'X'){
//        cout << "*" << letter << "*" << endl;
//        cin >> letter;
//    }
}