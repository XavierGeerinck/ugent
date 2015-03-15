//testprogramma voor de move- en copy van een een lijst volgens de C++11-standaard.
#include <iostream>
#include <cstdlib>
#include "lijst.h"
#include <string>
using std::cerr;
using std::string;
int gemaakt=0;   //aantallen gemaakte en verwijderde knopen.
int verwijderd=0;
// Wat volgt is een toepassing;
// deze wordt normaal door de gebruiker geschreven.
//class Lijstknoop:public string{
//    int a;
//public:
//    Lijstknoop(){};
//};
Lijst<int> maak(){
    Lijst<int> l;
    l.voegToe(int(7));
    l.voegToe(int(45));
    l.voegToe(int(15));
    l.voegToe(int(45));
    l.voegToe(int(25));
    l.voegToe(int(35));
    l.voegToe(int(45));
    l.voegToe(int(55));
    gemaakt+=8;
    return l;
    
};


int main(){
    {
        cerr<<"maak met transfer\n";
        Lijst<int> l;
        l=maak(); // Roept move constructor op
        Lijstknoop<int>::controle(gemaakt,verwijderd);
        cerr<<"verwijderen\n";
        l.verwijder(45);
        verwijderd++;
        l.verwijder(123);
        Lijstknoop<int>::controle(gemaakt,verwijderd);
        //    for (auto s:l)
        //        cerr<<s<<"\n";
        //    l.schrijf(cerr);
        cerr<<"Losse oproep maak\n";
        maak();
        verwijderd +=8;
        Lijstknoop<int>::controle(gemaakt,verwijderd);
        cerr<<"maak() in constructor\n";
        Lijst<int> l2(maak());
        Lijstknoop<int>::controle(gemaakt,verwijderd);
        cerr<<"duplicaat 1\n";
        l2=l;
        verwijderd+=8;
        gemaakt+=7;
        Lijstknoop<int>::controle(gemaakt,verwijderd);
        cerr<<"duplicaat 2\n";
        l2=l;
        gemaakt+=7;
        verwijderd+=7;
        Lijstknoop<int>::controle(gemaakt,verwijderd);
        cerr<<"duplicaat 3\n";
        l2=l2;
        Lijstknoop<int>::controle(gemaakt,verwijderd);
        l2.schrijf(cerr);
        cerr<<"\n";
        cerr<<"insertion sort\n";
        l2.insertionsort();
        Lijstknoop<int>::controle(gemaakt,verwijderd);
//        cerr<<"verwijderen\n";
//        l.verwijder(45);
//        l.verwijder(45);
//        l.verwijder(45);
//        l.verwijder(45);
//        verwijderd+=2;
//        Lijstknoop<int>::controle(gemaakt,verwijderd);
//        cerr<<"swappen\n";
//        swap(l2,l);
//        Lijstknoop<int>::controle(gemaakt,verwijderd);
//        l2.schrijf(cerr);
//        cerr<<"\n";
    }
//    verwijderd+=12;
//    Lijstknoop<int>::controle(gemaakt,verwijderd);
    return 0;
}