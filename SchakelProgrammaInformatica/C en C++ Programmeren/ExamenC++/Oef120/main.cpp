#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>

using std::string;
using std::vector;
using std::map;
using std::stack;
using std::set;
using std::cout;

int main() {
    vector<map<string, stack<set<string>>>> v(5);

    // Eerste vraag
    set<string> set1;
    set1.insert("do");
    set1.insert("re");
    set1.insert("mi");

    stack<set<string>> stack1;
    stack1.push(set1);

    map<string, stack<set<string>>> m1;
    m1["noot"] = stack1;

    v.push_back(m1);

    // Tweede vraag
    // 2de map vector, bevat priem? met bovenste element stack = woord 13
    if (v[1] != NULL && v[1].count("priem") > 0 && v[1]["priem"].top() != NULL && v[1]["priem"].top().count("13")) {
        cout << "FOUND";
    }
}