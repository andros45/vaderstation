#include <iostream>
#include <string>

using namespace std;

class Stad {
    public:

        string namn;
        int temp;

        // Constructormetod till klassen
        Stad(string x, int y) {
            namn = x;
            temp = y;
        }

        // Metod för att returnera en sträng med bägge värden från ett objekt
        string ToString(string x, int y) {
            string tempString, tempStringg;

            tempString = (x + " " + to_string(y));

            return (tempString);
        }

        //int linsok(fält städer, int n, int söktemp)

        // void bubblesort(fält städer, int n)

        // hogstTemp

        // lagstTemp

};

int main() {

    string inputNamn;
    int inputTemp;

    

    cout << "\n\nAnge namn på stad nr 1: ";
    cin >> inputNamn;

    cout << "\n\nAnge temperatur i " << inputNamn << ": ";
    cin >> inputTemp;

    Stad stad1(inputNamn, inputTemp);

    // Stad stader[4];

    cout << "\n\nI staden " << stad1.namn << " är det " << stad1.temp << " grader varmt.\n";

    return 0;
}