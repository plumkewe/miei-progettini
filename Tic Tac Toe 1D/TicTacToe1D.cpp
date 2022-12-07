#include <iostream>

using namespace std;

//  Creato: 07/12/22
//  Da: swampkewe
//  Versione: 0.00



int main() {
    setlocale(LC_ALL, "italian");

    int aTavoladagioco[10],
    sQuanti = sizeof(aTavoladagioco)/sizeof(aTavoladagioco[0]),
    sTentativi = 0, iDove = 0;

    fill(aTavoladagioco, aTavoladagioco + sQuanti, 0);

    cout << "Layout del gioco è seguente:\n  1️⃣2️⃣3️⃣ \n  4️⃣5️⃣6️⃣ \n ️7️⃣8️⃣9️⃣ \n\n";

    while (sQuanti > sTentativi){

        sTentativi ++;

        if (sTentativi % 2 == 0) {
            cout << "Tocca al giocatore due: ";
            cin >> iDove;

            while (aTavoladagioco[iDove] == 1 || aTavoladagioco[iDove] == 2){
                cout << "La posizione è già occupata, riprova: ";
                cin >> iDove;

            }

            while (iDove > 9 || iDove < 1){
                cout << "Non puoi uscire dal layout, riprova: ";
                cin >> iDove;

            }

            aTavoladagioco[iDove] = 1;

        } else {
            cout << "Tocca al giocatore uno: ";
            cin >> iDove;

            while (aTavoladagioco[iDove] == 1 || aTavoladagioco[iDove] == 2){
                cout << "[!] La posizione è già occupata, riprova: ";
                cin >> iDove;

            }

            while (iDove > 9 || iDove < 1){
                cout << "[!] Non puoi uscire dal layout, riprova: ";
                cin >> iDove;

            }

            while (aTavoladagioco[iDove] == 1 || aTavoladagioco[iDove] == 2){
                cout << "[!] La posizione è già occupata, riprova: ";
                cin >> iDove;

            }

            while (iDove > 9 || iDove < 1){
                cout << "[!] Non puoi uscire dal layout, riprova: ";
                cin >> iDove;

            }

            aTavoladagioco[iDove] = 2;

        }

        if (aTavoladagioco[1] && aTavoladagioco[2] && aTavoladagioco[3] || aTavoladagioco[4] && aTavoladagioco[5] && aTavoladagioco[6] || aTavoladagioco[7] && aTavoladagioco[8] && aTavoladagioco[9] || aTavoladagioco[1] && aTavoladagioco[4] && aTavoladagioco[7] || aTavoladagioco[2] && aTavoladagioco[5] && aTavoladagioco[8] || aTavoladagioco[3] && aTavoladagioco[6] && aTavoladagioco[9] || aTavoladagioco[1] && aTavoladagioco[5] && aTavoladagioco[9] || aTavoladagioco[3] && aTavoladagioco[5] && aTavoladagioco[7]){

            if (sTentativi % 2 == 0) {

                cout << "\n[+] Giocatore 2 ha vinto";

            } else {

                cout << "\n[+] Giocatore 1 ha vinto";
            }

            return 0;

        }

    }


    return 0;
}