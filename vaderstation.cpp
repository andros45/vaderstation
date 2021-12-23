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

        //TODO
        // hogstTemp(fält städer, int n)

        //TODO
        // lagstTemp(fält städer, int n)


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

        
int main() {

    // Variabler för att lagra användarens inmatningar
    string inputNamn, tempStad;
    int inputTemp, sokTemperatur, tempTemp;

    int sokRes;

    // Variabel för att användas i while-loopen där temperatur kontrolleras
    bool tempNotOk = true;

    // Skapa en array med plats för fyra objekt av typen Stad
    Stad stader[4];

    int n = sizeof(stader);
    
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
    
         // Be användaren ange vilken temperatur som ska sökas i arrayen med städer
    cout << "\nVilken temperatur vill du söka efter? Ange värde: ";
    cin >> sokTemperatur;

    sokRes = linsok(stader, sokTemperatur, 4);

    if (sokRes == -1) {
        cout << "\nKunde tyvärr inte hitta någon stad med temperaturen " << sokTemperatur << " grader.";
    } else {
        cout << "\nStaden " << stader[sokRes].getNamn() << " har eftersökt temperatur på " << stader[sokRes].getTemp() << " grader.\n";
    }

    // Skriv ut alla objekt som finns i arrayen innan bubblesort
    cout << "\nInnan bubblesort...\n";
    for(int i=0; i < 4; i++) {
        cout << "\nstader[" << i << "].toString(): " << stader[i].toString() << "\n";
    }
    
    // Sortera arrayen genom att anropa funktionen bubblesort
    bubbleSort(stader, 4);

    // Skriv ut alla objekt som finns i arrayen efter bubblesort
    cout << "\nEfter bubblesort...\n";
    for(int i=0; i < 4; i++) {
        cout << "\nstader[" << i << "].toString(): " << stader[i].toString() << "\n";
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

/*
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


// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

*/
    return 0;
}