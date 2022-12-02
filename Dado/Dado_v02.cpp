#include <iostream>
#include <random>
#include <string>

using namespace std;

//  Creato: 01/12/22
//  Da: swampkewe
//  Versione: 0.02

int main() {
    setlocale(LC_ALL, "italian");

    string aDado[6] =  {"\u2680", "\u2681", "\u2682", "\u2683", "\u2684", "\u2685"};
    int iQuanti, sSomma = 0;
    char iConferma;

    cout << "Ciao sono un dado, quanti ne vuoi lanciare? ";

    while (!(cin >> iQuanti)) {
        
        cout << "[!] Devi inserire un numero: ";
        cin.clear();
        cin.ignore(222, '\n');
    }

    cout << "Digita 'S' per lanciare: ";
    cin >> iConferma;

    if (iConferma != 's' | iConferma != 'S') {

        iConferma = 's';

    }

    if (iQuanti < 0)
        iQuanti -= iQuanti + iQuanti;

    do {

        for (int i = 0; i < iQuanti; ++i) {

            random_device rd;
            mt19937 rDadorandom(rd());
            uniform_int_distribution<int> dist(0,5);

            int sMemonumero = dist(rDadorandom);

            if (iQuanti > 1) {

                cout << "\nÈ uscito il numero: " << sMemonumero + 1 << " sul " << i + 1 << " dado " << aDado[sMemonumero];
                sSomma += sMemonumero + 1;

            }
            
            else
                
                cout << "\nSul dado è uscito il numero: " << sMemonumero + 1 << " " << aDado[sMemonumero];

        }

        if (iQuanti > 1)

            cout << "\nLa somma dei tutti dadi è pari a: " << sSomma << '\n';


        cout << "\nVuoi lanciare un'altro dado? [S/N]: ";
        cin >> iConferma;

        sSomma = 0;
        iQuanti = 1;

    } while (iConferma == 's' || iConferma == 'S');


    cout << "\nAlla prossima";
    

    return 0;
}