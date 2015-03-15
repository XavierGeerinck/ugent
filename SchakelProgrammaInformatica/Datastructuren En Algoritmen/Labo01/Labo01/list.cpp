#include <iostream>

namespace Lijsten{
    // Lijst
    template <typename T>
    class Lijstknoop;
    
    template <typename T>
    class Lijst{
    public:
        Lijst();
        Lijst(const Lijst &l);
        ~Lijst();
        //
        Lijst<T>& operator=(const Lijst<T> &l);
        Lijst<T>* zoek_gerangschikt(const T &d);
        Lijstknoop<T>* get_k();
        void voeg_toe_vooraan(const T &d);
        void insertion_sort();
        void printList();
    private:
        Lijstknoop<T>* k;
    };
    
    // methoden
    template <typename T>
    Lijst<T>::Lijst(){
        k=0;
    }
    
    template <typename T>
    Lijst<T>::Lijst(const Lijst &l){
        Lijst* p = this;
        Lijstknoop<T>* q = l.k;
        while(q != 0){
            p->k = new Lijstknoop<T>(q->data);
            p = &(p->k->opv);
            q = q->opv.k;
        }
    }
    
    template <typename T>
    Lijst<T>::~Lijst(){
        delete k;
    }
    
    template <typename T>
    Lijst<T>& Lijst<T>::operator=(const Lijst<T> &l){
        if(this != &l){
            delete k;
            Lijst* p = this;
            Lijstknoop<T>* q = l.k;
            while(q != 0){
                p->k = new Lijstknoop<T>(q->data);
                p = &(p->k->opv);
                q = q->opv.k;
            }
        }
        return *this;
    }
    
    template <typename T>
    void Lijst<T>::printList() {
        Lijstknoop<T> * t = k;
        
        std::cout << k->data << " ";
        
        while (t->opv.k) {
            t = (t->opv.k);
            
            std::cout << t->data << " ";
        }
        
        std::cout << std::endl;
    }
    
    template <typename T>
    void Lijst<T>::voeg_toe_vooraan(const T &d){
        Lijstknoop<T>* h=k;
        k = new Lijstknoop<T>(d);
        k->opv.k = h;
    }
    
    template <typename T>
    Lijstknoop<T>* Lijst<T>::get_k() {
        return k;
    }
    
    /**
     *
     *
     */
    template <typename T>
    Lijst<T> * Lijst<T>::zoek_gerangschikt(const T &d) {
//        Recursieve implementatie
        if (k->data >= d || k == nullptr) {
            return this;
        }
        
        return k->opv.zoek_gerangschikt(d);
//        Gewone implementatie
//        Lijstknoop<T> * temp = this;
//        
//        if (k->data >= d || k == nullptr) {
//            return &k;
//        }
//        
//        while (temp->opv.k != nullptr && temp->k->opv.k->data < d) {
//            temp = &(temp->k->opv);
//        }
//        
//        return temp;
    }
    
    /**
     * Sorteer de lijst volgens insertion sort
     *
     * Pseudocode:
     * for i=0; i<size; i++
     *     h = array[i];
     *     h2 = i;
     *     for j=i;j>0;j--
     *         if (array[j] > array[i]) {
     *             array[h2] = array[j];
     *             h2--; // set new index
     *             k = j; // last replaced element
     *         }
     *     }
     *     array[k] = h;
     */
    template <typename T>
    void Lijst<T>::insertion_sort() {
        // Nothing to be done
        if (k == nullptr || k->opv.k == nullptr) {
            return;
        }
        
        // Start sorteren
        Lijstknoop<T> * sorted = k;
        k = k->opv.k;
        sorted->opv.k = nullptr;
        
        while (k) {
            // Ga naar volgende knoop
            Lijstknoop<T> * current = k;
            k = k->opv.k;
            
            // Zoek waar de huidige moet komen
            if (current->data < sorted->data) {
                current->opv.k = sorted;
                sorted = current;
            } else {
                Lijstknoop<T> * zoek = sorted;
                while (zoek->opv.k && current->data > zoek->opv.k->data) {
                    zoek = zoek->opv.k;
                }
                
                // Current achter zoek
                current->opv.k = zoek->opv.k;
                zoek->opv.k = current;
            }
        }
        
        k = sorted;
    }
    
    // Lijstknoop
    
    template <typename T>
    class Lijstknoop{
        friend class Lijst<T>;
    public:
        Lijstknoop(const T &d = T());
        T get_data();
    private:
        T data;
        Lijst<T> opv;
    };
    
    template <typename T>
    Lijstknoop<T>::Lijstknoop(const T &d) : data(d) {}
    
    template <typename T>
    T Lijstknoop<T>::get_data() {
        return data;
    }
    
} // namespace Lijsten