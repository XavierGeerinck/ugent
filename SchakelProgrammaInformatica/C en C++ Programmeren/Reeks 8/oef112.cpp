/*
Ga voort op de vorige oefening. Voorzie code die volgende containers uitschrijft, telkens voor
elementen van niet nader gespecifi¨eerd type. Je test telkens uit met een container waaraan je
´e´en (maximaal twee) elementen toevoegt.

• een set (schrijf elementen uit tussen accolades, met een komma ertussen)
• een queue (schrijf elementen uit tussen vierkante haken, met verticale strepen ertussen)
• een stack (schrijf elementen uit onder elkaar; begin een nieuwe regel voor het eerste element)
• een map, waarbij je dus zowel type van sleutel als type van bijhorende data ongespecifi¨eerd
laat (schrijf sleutels onder elkaar uit; elke sleutel wordt gevolgd door een pijltje en zijn
bijhorende data)
 */

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>

template<typename T>
void schrijf_queue(std::queue<T> el) {
    std::cout << "[ ";

    while (el.front()) {
        std::cout << "| " << el.front();
        el.pop();
    }

    std::cout << " ]";
}

template<typename T>
void schrijf_set(const std::set<T> &el) {
    std::cout << "{ ";

    for (typename std::set<T>::const_iterator it = el.begin(); it != el.end(); ++it) {
        std::cout << *it << ", " ;
    }

    std::cout << " }";
}

template<typename T>
void schrijf_stack(std::stack<T> el) {
    std::cout << std::endl;

    while (!el.empty()) {
        std::cout << el.top();
        el.pop();
        std::cout << std::endl;
    }
}

void schrijf_map(const std::map<std::string, int> &el) {
    std::cout << std::endl;

    for (typename std::map<std::string, int>::const_iterator it = el.begin(); it != el.end(); ++it) {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
}

int main() {
    //• een set (schrijf elementen uit tussen accolades, met een komma ertussen)
    std::set<int> s;
    s.insert(1);
    s.insert(2);

    schrijf_set(s);

    //• een queue (schrijf elementen uit tussen vierkante haken, met verticale strepen ertussen)
    std::queue<int> q;
    q.push(2);
    q.push(3);

    schrijf_queue(q);

    //• een stack (schrijf elementen uit onder elkaar; begin een nieuwe regel voor het eerste element)
    std::stack<int> st;
    st.push(4);
    st.push(5);

    schrijf_stack(st);

    //• een map, waarbij je dus zowel type van sleutel als type van bijhorende data ongespecifi¨eerd
    //  laat (schrijf sleutels onder elkaar uit; elke sleutel wordt gevolgd door een pijltje en zijn
    //  bijhorende data)
    std::map<std::string, int> m;
    m["a"] = 1;
    m["b"] = 2;
    m["c"] = 3;
    m["d"] = 4;
    m["e"] = 5;

    schrijf_map(m);

}

