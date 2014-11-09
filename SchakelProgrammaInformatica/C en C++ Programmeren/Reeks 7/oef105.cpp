#include <iostream>

using namespace std;

int main() {
    const int AANT=10;
    int getallen[AANT];
    char letters[AANT];
    string woorden[AANT];

    cout<<"Geef "<<AANT<<" getallen, "
            <<"letters resp. woorden: ";

    cin>>getallen;
    cin>>letters;
//    cin>>woorden;

    //cout<<getallen<<endl;
    cout<<letters<<endl;
    cout<<woorden<<endl;
}