#include <iostream>
// #include <string>

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

        // Metod för att hämta attributet 'namn'
        string getNamn() {
            return namn;
        }

        // Metod för att hämta attributet 'temp'
        int getTemp() {
            return temp;
        }

        // Metod för att sätta objektets värden (attribut) 
        void setValues(string s, int t) {
            namn = s;
            temp = t;
        }

};

int hogstTemp(Stad stader[], int n) {
    int index = 0;
    int hogst = stader[index].getTemp();
    
    for(int i=0; i < n; i++) {    
        if (hogst < stader[i].getTemp()) {
            hogst = stader[i].getTemp();
            index = i;
        }
    }
    return index;
}

int lagstTemp(Stad stader[], int n) {
    int index = 0;
    int lagst = stader[index].getTemp();
    
    for(int i=0; i < n; i++) {    
        if (lagst > stader[i].getTemp()) {
            lagst = stader[i].getTemp();
            index = i;
        }
    }
    return index;
}

int linsok(Stad stader[], int sokTemp, int n) {
    for(int i=0; i < n; i++) {    
        if (sokTemp == stader[i].getTemp()) {
            return i;
        }
    }
    return -1;
}

void bubbleSort(Stad stader[], int n) {
    string tempStad;
    int tempTemp;
    for(int i=0; i < n; i++) {
         for(int j=0; j < n; j++) {
             if (stader[j].getTemp() > stader[j+1].getTemp()) {
                tempStad = stader[j].getNamn();
                tempTemp = stader[j].getTemp();
                stader[j].setValues(stader[j+1].getNamn(), stader[j+1].getTemp());
                stader[j+1].setValues(tempStad, tempTemp);
            }
        }
    }
}


int binSok(Stad stader[], int v, int h, int sokTemp)
{
    
	if (h >= v) {
		int mitten = v + (h - v) / 2;

        // Om värdet finns i mitten kan vi returnera det direkt
		if (stader[mitten].getTemp() == sokTemp)
			return mitten;

        // Om värdet är mindre än mitten så kan det
        // bara finnas i den vänstra delen av arrayen
		if (stader[mitten].getTemp() > sokTemp) {
			return binSok(stader, v, mitten - 1, sokTemp);
        } else {
            // Annars kan värdet bara finnas i den
            // högra delen av arrayen
            return binSok(stader, mitten + 1, h, sokTemp);
        }
	}

    // Om vi inte hittar värdet i arrayen returneras -1
	return -1;
}

        
int main() {

    // Variabler för att lagra användarens inmatningar
    string inputNamn, tempStad;
    int inputTemp, sokTemperatur, tempTemp;



    int sokRes;

    // Variabel för att användas i while-loopen där temperatur kontrolleras
    bool tempNotOk = true;

    // Skapa en array med plats för fyra objekt av typen Stad
    Stad stader[4];

    // Antal element i arrayen
    int n = 4;

    cout << "\n\n" << n << "\n\n";
    
    // Loop för att få användaren att mata in de fyra städerna och
    // tillhörande temperaturer. Inmatad temperatur kontrolleras
    // så att inte gränsvärdena överskrids. (-60 till +60 grader)
    for(int i=0; i < n; i++) {
        cout << "\n\nAnge namn på stad nr " << i+1 << " av " << n << ": ";
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
    
         // Be användaren ange vilken temperatur som ska sökas i arrayen med städer
    cout << "\nVilken temperatur vill du söka efter? Ange värde: ";
    cin >> sokTemperatur;

    sokRes = linsok(stader, sokTemperatur, n);

    if (sokRes == -1) {
        cout << "\nKunde tyvärr inte hitta någon stad med temperaturen " << sokTemperatur << " grader.";
    } else {
        cout << "\nStaden " << stader[sokRes].getNamn() << " har eftersökt temperatur på " << stader[sokRes].getTemp() << " grader.\n";
    }

    // Skriv ut alla objekt som finns i arrayen innan bubblesort
    cout << "\nInnan bubblesort...\n";
    for(int i=0; i < n; i++) {
        cout << "\nstader[" << i << "].toString(): " << stader[i].toString() << "\n";
    }
    
    // Sortera arrayen genom att anropa funktionen bubblesort
    bubbleSort(stader, n);

    // Skriv ut alla objekt som finns i arrayen efter bubblesort
    cout << "\nEfter bubblesort...\n";
    for(int i=0; i < n; i++) {
        cout << "\nstader[" << i << "].toString(): " << stader[i].toString() << "\n";
    }

    // Be användaren ange vilken temperatur som ska sökas i arrayen (binärsök) med städer
    cout << "\nVilken temperatur vill du söka efter? (binärsök) Ange värde: ";
    cin >> sokTemperatur;

    sokRes = binSok(stader, 0, n, sokTemperatur);

    if (sokRes == -1) {
        cout << "\nKunde tyvärr inte hitta någon stad med temperaturen " << sokTemperatur << " grader. (binärsökning)\n";
    } else {
        cout << "\nStaden " << stader[sokRes].getNamn() << " har eftersökt temperatur på " << stader[sokRes].getTemp() << " grader. (binärsökning)\n";
    }

    cout << "Staden med högst temperatur är " << stader[hogstTemp(stader, n)].getNamn() << " med " << 
        stader[hogstTemp(stader, n)].getTemp() << " grader.\n";

    cout << "Staden med lägst temperatur är " << stader[lagstTemp(stader, n)].getNamn() << " med " << 
        stader[lagstTemp(stader, n)].getTemp() << " grader.\n";

    return 0;
}