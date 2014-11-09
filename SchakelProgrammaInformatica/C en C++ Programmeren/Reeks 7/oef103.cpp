#include <iostream>

using namespace std;

void wissel(int &a, int &b){
    int hulp = a;
    a = b;
    b = hulp;
}

int main(){
    int x, y;
    x = 5;
    y = 10;
    cout << "Eerst hebben we x=" << x << " en y=" << y << "." << endl;
    wissel(x,y);
    cout << "Na de wissel hebben we x=" << x << " en y=" << y << "." << endl;
    return 0;
}