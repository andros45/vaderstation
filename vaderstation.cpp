#include <iostream>
#include <string>

using namespace std;

class Stad {

    string namn;
    int temp;

    public:

        // Metod för att returnera en sträng med bägge värden från ett objekt
        string toString() {
            string tempString;
            tempString = (namn + " " + to_string(temp));
            return (tempString);
        }

        // Metod för att sätta objektets värden (attribut) 

        void setValues(string s, int t) {
            namn = s;
            temp = t;
        }

<<<<<<< Updated upstream
<<<<<<< Updated upstream
        //TODO
        //int linsok(fält städer, int n, int söktemp)
=======
};
>>>>>>> Stashed changes
=======
};
>>>>>>> Stashed changes

        //TODO
        // void bubblesort(fält städer, int n)

        //TODO
        // hogstTemp

        //TODO
        // lagstTemp

};

int main() {

    // Variabler för att lagra användarens inmatningar
    string inputNamn;
    int inputTemp;

    // Variabel för att användas i while-loopen där temperatur kontrolleras
    bool tempNotOk = true;

    // Skapa en array med plats för fyra objekt av typen Stad
    Stad stader[4];

    // Loop för att få användaren att mata in de fyra städerna och
    // tillhörande temperaturer. Inmatad temperatur kontrolleras
    // så att inte gränsvärdena överskrids. (-60 till +60 grader)
    for(int i=0; i < 4; i++) {
        cout << "\n\nAnge namn på stad nr " << i+1 << " av 4: ";
        cin >> inputNamn;
        while(tempNotOk) {
            cout << "Ange temperatur i " << inputNamn << ": ";
            cin >> inputTemp;
            if (inputTemp >= -60 && inputTemp <= 60) {
                tempNotOk = false;
            } else {
                cout << "\nTemperaturen måste ligga mellan -60 och +60 grader. Försök igen!\n";
            }
        }
        
        // Återställ tempNotOk för while-loopen
        tempNotOk = true;

        // Anrop av den inbyggda metoden setValues för att sätta värden
        // på objekten i arrayen
        stader[i].setValues(inputNamn, inputTemp);
    }
    
    // Skriv ut två blankrader
    cout << "\n\n";

<<<<<<< Updated upstream
<<<<<<< Updated upstream
    // Skriv ut alla objekt som finns i arrayen
    for(int i=0; i < 4; i++) {
        cout << "stader[" << i << "].toString(): " << stader[i].toString() << "\n";
    }
    
=======
=======
>>>>>>> Stashed changes
    // Skriv ut alla objekt som finns i arrayen innan bubblesort
    cout << "\nInnan bubblesort...\n";
    for(int i=0; i < 4; i++) {
        cout << "\nstader[" << i << "].toString(): " << stader[i].toString() << "\n";
    }
    
    // Sortera mha bubblesort
    // TODO
    // Detta ska också gällas i en egen metod där arrayen skickas med som parameter
    // Skriv också en funktion/metod som sorterar ett Stad-fält efter temperatur (kallast först)
     for(int i=0; i < 4; i++) {
         for(int j=0; j < 4; j++) {
             if (stader[j].getTemp() > stader[j+1].getTemp()) {
                tempStad = stader[j].getNamn();
                tempTemp = stader[j].getTemp();
                stader[j].setValues(stader[j+1].getNamn(), stader[j+1].getTemp());
                stader[j+1].setValues(tempStad, tempTemp);
         }
        
        }
    }

    // Skriv ut alla objekt som finns i arrayen efter bubblesort
    cout << "\nEfter bubblesort...\n";
    for(int i=0; i < 4; i++) {
        cout << "\nstader[" << i << "].toString(): " << stader[i].toString() << "\n";
    }

     // Be användaren ange vilken temperatur som ska sökas i arrayen med städer
    cout << "\nVilken temperatur vill du söka efter? Ange värde: ";
    cin >> sokTemperatur;


    // TODO
    // Den här funkar, men enligt uppgiften ska detta läggas i en separat metod
    for(int i=0; i < 4; i++) {
        if (stader[i].getTemp() == sokTemperatur) {
            cout << "\nStaden " << stader[i].getNamn() << " har eftersökt temperatur (" << stader[i].getTemp() << ")\n";
        }
    }

/*
    OM mittersta värdet i fältet är lika med det sökta värdet
        Värdet hittat
    ANNARS OM vektorn består av endast ett element
        Sökta värdet finns inte i fältet 
    ANNARS OM sökta värdet är mindre än mittersta värdet
        Sök i nedre halvan av fältet 
    ANNARS
        Sök i övre halvan av fältet
*/

    // Be användaren ange vilken temperatur som ska sökas i arrayen (binärsök) med städer
    cout << "\nVilken temperatur vill du söka efter? (binärsök) Ange värde: ";
    cin >> sokTemperatur;


    // TODO
    // Den här funkar, men enligt uppgiften ska detta läggas i en separat metod
    for(int i=0; i < 4; i++) {
        if (stader[i].getTemp() == sokTemperatur) {
            cout << "\nStaden " << stader[i].getNamn() << " har eftersökt temperatur (" << stader[i].getTemp() << ")\n";
        }
    }
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

    return 0;
}