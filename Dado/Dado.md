# ð² <br /> Dado

### Come mi era nata l'idea

//

###### Simboli utilizzati:

| **Simbolo:** | **Unicode:** |
|:-- | :-- |
| â | 2680 |
| â | 2681 |
| â | 2682 |
| â | 2683 |
| â | 2684 |
| â | 2685 | 



### Versioni alternative:

//

###### Codice:

```cpp
#include <iostream>
#include <random>
#include <string>

using namespace std;

//  Creato: 01/12/22
//  Da: swampkewe
//  Versione: 0.01

int main() {
	setlocale(LC_ALL, "italian");

    string aDado[6] =  {"\u2680", "\u2681", "\u2682", "\u2683", "\u2684", "\u2685"};

    char iConferma;

    random_device rd;
    mt19937 rDadorandom(rd());
    uniform_int_distribution<int> dist(0,5);

    cout << "Ciao sono un dado, scrivi 'S' per lancare e 'N' per uscire: ";
    cin >> iConferma;

    do {
    short int unsigned sMemonumero = dist(rDadorandom);

    cout << "\nÃ uscito il numero: " << sMemonumero + 1 << " sul dado " << aDado[sMemonumero];

    cout << "\nVuoi tirare un'alta volta [S/N]: ";
    cin >> iConferma;

    } while (iConferma == 's' || iConferma == 'S');

    cout << "\nAlla prossima";

	return 0;
}
```
