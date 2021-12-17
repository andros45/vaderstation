#include <iostream>
#include <string>

using namespace std;

class Stad {
    public:

        string namn;
        int temp;

        // Constructormetod till klassen
        Stad() {
            
        }

        // string ToString()

        //int linsok(fält städer, int n, int söktemp)

        // void bubblesort(fält städer, int n)

        // hogstTemp

        // lagstTemp

};

int main() {

    Stad minStad;

    minStad stader[4];

    cout << "Ange namn på stad nr 1: ";
    cin >> minStad.namn;

    cout << "Ange temperatur i " << minStad.namn << ": ";
    cin >> minStad.temp;

    cout << "I staden " << minStad.namn << " är det " << minStad.temp << " grader varmt.\n";

    return 0;
}