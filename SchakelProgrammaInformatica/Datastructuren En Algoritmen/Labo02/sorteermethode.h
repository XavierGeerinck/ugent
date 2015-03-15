//
//  sorteermethode.h
//  Labo2
//
//  Created by Xavier Geerinck on 18/02/15.
//  Copyright (c) 2015 Xavier Geerinck. All rights reserved.
//

#ifndef Labo2_sorteermethode_h
#define Labo2_sorteermethode_h

#include <iostream>
using std::endl;
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>   // voor sort()-methode uit STL
#include <iomanip> // setw()
#include <math.h> // floor

template <typename T>
class Sorteermethode{
public:
    virtual void operator()(vector<T> & v) const = 0;
};

/*
 *   STANDARD TEMPLATE LIBRARY SORT
 */
template <typename T>
class STLSort : public Sorteermethode<T>{
public:
    void operator()(vector<T> & v) const;
};

template <typename T>
void STLSort<T>::operator()(vector<T> & v) const{
    sort(v.begin(),v.end());
}

/*
 *   INSERTION SORT
 */
template <typename T>
class InsertionSort : public Sorteermethode<T>{
public:
    void operator()(vector<T> & v) const;
};

template <typename T>
void InsertionSort<T>::operator()(vector<T> & v) const{
    for (int i = 0; i < v.size(); i++) {
		// Save the temporary element
		T temp = v[i];
		
		// Create a key that points to the previous index
		// (we need to check if we have to shift)
		int j = i - 1;
		
		// Now we need to move the elements to the right if they are bigger
		while (j >= 0 && v[j] > temp) {
			v[j + 1] = v[j]; // Shift right
			j--; // Go one element back
		}
        
		// last but not least, fill in the temp on the position that we found
		v[j + 1] = temp;
	}
    
    /*
    for(int i=1; i<v.size(); i++){
        T h = v[i];
        int j=i-1;
        while(j>=0 && h<v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = h;
    }
     */
}

/*
 *   SHELLSORT
 */

/**
 * Shell sort gaat zolang gap >= 1 de originele opdelen in rijen van k aantal elementen
 * Na deze opsplitsing gaan we dan insertion sort toepassen op de gevonden kolommen
 * Als laatste gaan we ons k verminderen en gaan we de bovenstaande procedure opnieuw doen tot k < 1
 *
 * Gebruikt algoritme: N/2^K
 */
template <typename T>
class ShellSort : public Sorteermethode<T>{
public:
    void operator()(vector<T> & v) const;
};

// Implementatie
template <typename T>
void ShellSort<T>::operator()(vector<T> &v) const {
    int k = v.size() / 2; // Neem initiele increment
    
    while (k >= 1) {
        for (int i = k; i < v.size(); i++) {
            int h = v[i];
            int j = i - k;
            
            while (j >= 0 && h < v[j]) {
                v[j + k] = v[j];
                j -= k;
            }
            
            v[j + k] = h;
        }
        
        k /= 2;
    }
}

/*
 *    HEAP SORT
 */

/**
 * Algoritme werkt door een heap te maken, en dan te starten vanaf voorlaatste hoogte en zo naar boven te werken (dus --)
 * In een vector hebben we dus enkele dingen nodig:
 * - root element = i
 * Nu beginnen we op h - 1 en gaan we telkens heapify checken, als we geswapped hebben dan beginnen we terug volledig opnieuw.
 *
 * vb: vector = 19, 7, 1, 4, 3, 8, 10, 15, 2
 */
template <typename T>
class HeapSort : public Sorteermethode<T> {
public:
    void operator()(vector<T> & v) const;
    
    /**
     * ChildLeft  = 2 * idx_el + 1
     */
    int getChildLeftIndex(int index) const {
        //return 2 * index + 1;
        return (index << 1) + 1;
    }
    
    /**
     * ChildRight = 2 * (idx_el + 1)
     */
    int getChildRightIndex(int index) const {
        //return 2 * (index + 1);
        return (index + 1) << 1;
    }
    
    /**
     * GetHeightTree(arraySize) = shiftLeft beginnend vanaf 1 zolang < arraySize (log base 2 van (aantEl + 1) - 1)
     */
    int getHeightTree(int arraySize) const {
        int i = 1;
        int height = 0;
        
        while (i  < arraySize) {
            i <<= 1;
            height++;
        }
        
        return height - 1; // -1 want root element telt niet mee
    }
    
    /**
     * GetSecondLastHeightStart() = (2^h - 1) - 1 ==> last -1 since we want to rebase to 0 for array index
     */
    int getSecondLastHeightStartIndex(int h) const {
        // Simulate 2^h
        int i = 1;
        int value = 1;
        while (i <= h) {
            value <<= 1;
            i++;
        }
        
        return value - 2;
    }
    
    void buildMaxHeap(vector<T> &v) const {
        for (int i = (int)floor(v.size() / 2); i >= 0; i--)
            maxHeapify(v, i, v.size());
    }
    
    /**
     * endIndex en startIndex zijn hier zodat we inarray kunnen sorteren
     */
    void maxHeapify(vector<T> &v, int i, int endIndex) const {
        //int h = getHeightTree(endIndex + 1);
        //int secondLastHeightStartIdx = getSecondLastHeightStartIndex(h);

        //std::cout << "Array  Size: " << v.size() << std::endl;
        //std::cout << "Height Tree: " << h << std::endl;
        //std::cout << "Start Index: " << startIndex << std::endl;
  
        int elLeftIndex = getChildLeftIndex(i);
        int elRightIndex = getChildRightIndex(i);
            
        // Zet grootste node op root
        int largestNodeIdx = i;
            
        // If left child is the biggest, replace with parent
        if ((elLeftIndex < endIndex) && (v[largestNodeIdx] < v[elLeftIndex])) {
            largestNodeIdx = elLeftIndex;
        }
            
        // if right child exists, check if it is less than
        if ((elRightIndex < endIndex) && (v[largestNodeIdx] < v[elRightIndex])) {
            largestNodeIdx = elRightIndex;
        }
            
        // If one of the 2 was larger than the parent
        if (largestNodeIdx != i) {
            // Switch parent with child
            int temp = v[i];
            v[i] = v[largestNodeIdx];
            v[largestNodeIdx] = temp;
                
            // ReApply maxHeapify on the subtree
            maxHeapify(v, largestNodeIdx, endIndex);
        }
    }
};

template <typename T>
void HeapSort<T>::operator()(vector<T> &v) const {
    int heapSize = v.size();
    
    // Eerst heapify
    buildMaxHeap(v);
    
    // Nu sortdown, hier gaan we telkens het eerst el nemen en vervangen met het laatste el, Hierna resizen we de array en repeat
    for (int i = v.size() - 1; i > 0; i--) {
        // Swap eerste en laatste
        T tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;
        
        // Maak de heap opnieuw
        maxHeapify(v, 0, i);
    }
};

/*
 *    MERGE SORT
 */

/**
 *
 *
 *
 */
template <typename T>
class MergeSort : public Sorteermethode<T> {
public:
    void operator()(vector<T> & v) const;
};

template <typename T>
void MergeSort<T>::operator()(vector<T> &v) const {
    
};

/*
 *    QUICKSORT
 */

/**
 *
 *
 *
 */
template <typename T>
class QuickSort : public Sorteermethode<T> {
public:
    void operator()(vector<T> & v) const;
};

template <typename T>
void QuickSort<T>::operator()(vector<T> &v) const {
    
};

#endif
