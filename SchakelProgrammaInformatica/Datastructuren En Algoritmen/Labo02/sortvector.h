//
//  sortvector.h
//  Labo2
//
//  Created by Xavier Geerinck on 18/02/15.
//  Copyright (c) 2015 Xavier Geerinck. All rights reserved.
//

#ifndef Labo2_sortvector_h
#define Labo2_sortvector_h

//sortvector is een klasse van sorteerbare vectoren

#include <iostream>
using std::istream;
using std::ostream;
#include <iomanip>   // voor setw
#include <cstdlib>   // voor rand - opletten!!
#include "sorteermethode.h"
#include "chrono.h"
#include "csv.h"
#include "Nstring.h"

template<class T>
class Sortvector{
public:
    
    // Constructor: het argument geeft de grootte aan
    // bij constructie zal de tabel opgevuld worden met
    // n verschillende getallen in random volgorde
    // (zie hulplidfunctie)
    Sortvector(int);
    
    // Geeft onderstaande code compileerfouten of warnings?
    // Zorg dat de compiler C++11-code aankan.
    // In Dev-C++:
    // in menubalk: Tools - compiler options - general -
    // 'add the following commands when calling the compiler': -std=c++11
    Sortvector(const Sortvector<T>& v) = delete;
    Sortvector<T>& operator=(const Sortvector<T>& v) = delete;
    Sortvector<T>& operator=(Sortvector<T>&& v) = delete;
    Sortvector(Sortvector<T>&& v) = delete; // Move constructor, delete zodat we die niet gebruiken! :D
    
    const T &operator[](int i) const { return tab[i]; }  // voor rechterlid
    T &operator[](int i)       { return tab[i]; }  // voor linkerlid
    
    // sorteer sorteert de tabel.
    // Het argument geeft de sorteermethode aan
    void sorteer(const Sorteermethode<T> & methode);
    
    void vul_range();
    void draai_om();
    void vul_omgekeerd();
    void shuffle();
    void vul_random_zonder_dubbels();
    void vul_random(); // nog niet implementeren
    
    bool is_gesorteerd() const;
    bool is_range() const;
    
    friend ostream& operator<<(ostream& os, const Sortvector<T>& s){
        s.schrijf(os);
        return os;
    }
    
private:
    vector<T> tab;
    
    void schrijf(ostream & os)const;
    int n; // Aantal elementen
    
};

template <class T>
void Sortvector<T>::schrijf(ostream & os)const{
    for(int i=0; i<tab.size(); i++){
        os<<tab[i]<<" ";
    }
    os<<endl;
}

template <class T>
Sortvector<T>::Sortvector(int elementCount) {
    n = elementCount;
}

/**
 * Vult de vector in van 0, 1, 2, 3, n - 1 waarbij n de grootte is
 */
template <class T>
void Sortvector<T>::vul_range() {
    for (int i = 0; i < n; i++) {
        tab.push_back(i);
    }
}

/**
 * Draait de elementen in de vector om
 */
template <class T>
void Sortvector<T>::draai_om() {
    std::reverse(tab.begin(),tab.end());
}

/**
 * vult de vector omgekeerd in (dus van n - 1 naar 0)
 */
template <class T>
void Sortvector<T>::vul_omgekeerd() {
    for (int i = n - 1; i >= 0; i--) {
        tab.push_back(i);
    }
}

template <class T>
void Sortvector<T>::sorteer(const Sorteermethode<T> & methode) {
    methode(tab);
}

/**
 * Shuffle methode gebaseerd op Fisher Yates
 * To shuffle an array a of n elements (indices 0..n-1):
 *    for i from n − 1 downto 1 do
 *        j ← random integer with 0 ≤ j ≤ i
 *        exchange a[j] and a[i]
 *
 * NOTE: http://www.cplusplus.com/reference/cstdlib/RAND_MAX/ rand limit = 32767
 */
template <class T>
void Sortvector<T>::shuffle() {
    int n = tab.size();
    for (int i = n - 1; i > 0; --i) {
        std::swap(tab[i], tab[rand() % (i + 1)]);
    }
}

/**
 * Vul de array zonder dubbels, dus eerst normaal en dan shufflen :D
 */
template <class T>
void Sortvector<T>::vul_random_zonder_dubbels() {
    vul_range();
    shuffle();
}

/**
 * Kijkt na of de array gesorteerd is in stijgende volgorde
 * kijk van eerste element, tot laatste of het i - 1 < i
 */
template <class T>
bool Sortvector<T>::is_gesorteerd() const {
    for (int i = 1; i < n; i++) {
        if (tab[i - 1] >= tab[i]) {
            return false;
        }
    }
    
    return true;
}

/**
 * Kijkt na of de elementen gesorteerd zijn zoals de range. Dus 0 1 2 3 4 5 .... n - 1
 */
template <class T>
bool Sortvector<T>::is_range() const {
    for (int i = 0; i < n; i++) {
        if (tab[i] != i) {
            return false;
        }
    }
    
    return true;
}

// Het volgende is geen lidfunctie van een klasse.
// Deze externe procedure schrijft naar os een overzicht (met de nodige ornamenten)
// met de snelheid van de opgegeven sorteermethode sm. Er wordt 1 lijn uitgedrukt voor elke mogelijke
// grootte. Deze groottes zijn kleinste, 10*kleinste, 100*kleinste,
// enzovoorts, tot aan grootste.
// Op een lijn staat de snelheid van de methode toegepast op
// (1) een random tabel
// (2) een al gesorteerde tabel.
// (3) een omgekeerd gesorteerde tabel.

// Deze functie werkt alleen als T een toekenning van een int toelaat,
// zodat bv.
//    T a=5;
// geldig is.
template<class T>
void meet(int kortste, int langste, const Sorteermethode<T> & sm, ostream& os) {
    int lengte = kortste;
    
    // Print header
    os << std::setw(10) << "Lengte\t\t"
    << "random\t"
    << "gesorteerd\t"
    << " omgekeerd"
    << std::endl;
    
    // Print results
    for (int i = 0; i < langste; i++) {
        lengte *= 10;

        Sortvector<T> svr(lengte);
        svr.vul_random_zonder_dubbels();
        
        Sortvector<T> svg(lengte);
        svg.vul_range();
        
        Sortvector<T> svo(lengte);
        svo.vul_omgekeerd();
        
        Chrono cr;
        cr.start();
        svr.sorteer(sm);
        cr.stop();
        
        Chrono cr2;
        cr2.start();
        svg.sorteer(sm);
        cr2.stop();
        
        Chrono cr3;
        cr3.start();
        svo.sorteer(sm);
        cr3.stop();
        
        os << std::setw(10) << lengte
        << "\t" << std::setw(10) << cr.tijd()
        << "\t" << std::setw(10) << cr2.tijd()
        << "\t" << std::setw(10) << cr3.tijd()
        << std::endl;
        

    }
}

template<class T>
void meet(int kortste, int langste, const Sorteermethode<T> & sm, CsvData & csv) {
    int lengte = kortste;
    
//    vector<std::string> headers;
//    headers.push_back("Lengte");
//    headers.push_back("Random");
//    headers.push_back("Gesorteerd");
//    headers.push_back("Omgekeerd");
    
//    csv.voegDataToe(headers);
    
    // Print results
    for (int i = 0; i < langste; i++) {
        lengte *= 10;
        
        Sortvector<T> svr(lengte);
        svr.vul_random_zonder_dubbels();
        
        Sortvector<T> svg(lengte);
        svg.vul_range();
        
        Sortvector<T> svo(lengte);
        svo.vul_omgekeerd();
        
        Chrono cr;
        cr.start();
        svr.sorteer(sm);
        cr.stop();
        
        Chrono cr2;
        cr2.start();
        svg.sorteer(sm);
        cr2.stop();
        
        Chrono cr3;
        cr3.start();
        svo.sorteer(sm);
        cr3.stop();
        
        vector<double> tijden;
        tijden.push_back(lengte);
        tijden.push_back(cr.tijd());
        tijden.push_back(cr2.tijd());
        tijden.push_back(cr3.tijd());
        
        csv.voegDataToe(tijden);
    }
}

#endif
