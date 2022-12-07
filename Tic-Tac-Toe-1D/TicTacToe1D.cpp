#include <iostream>
#include <string>

using namespace std;

//  Creato: 07/12/22
//  Da: swampkewe
//  Versione: 0.01
//  Fa più schivo di prima



int main() {
    setlocale(LC_ALL, "italian");

    int aTavoladagioco[10],
    sQuanti = sizeof(aTavoladagioco)/sizeof(aTavoladagioco[0]),
    sTentativi = 0, iDove = 0;
    string aCopiamappa[10];
    

    fill(aTavoladagioco, aTavoladagioco + sQuanti, 0);
    fill(aCopiamappa, aCopiamappa + sQuanti, "⬜️");

    cout << "Layout del gioco è seguente:\n  1️⃣2️⃣3️⃣ \n  4️⃣5️⃣6️⃣ \n ️7️⃣8️⃣9️⃣ \n\n";

    while (sQuanti > sTentativi){

        sTentativi ++;


        if (sTentativi % 2 == 0) {
            cout << "Tocca al giocatore due: ";
            cin >> iDove;

            while (aTavoladagioco[iDove] == 1 || aTavoladagioco[iDove] == 2){
                cout << "[!] La posizione è già occupata, riprova: ";
                cin >> iDove;

            }

            while (iDove > 9 || iDove < 1){
                cout << "[!] Non puoi uscire dal layout, riprova: ";
                cin >> iDove;

            }

            aTavoladagioco[iDove] = 1;
            aCopiamappa[iDove] = "⭕️";
            

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

            aTavoladagioco[iDove] = 2;
            aCopiamappa[iDove] = "❌";

        }
        
        //  ajajjaja

        if (aTavoladagioco[1] == 1 && aTavoladagioco[2] == 1 && aTavoladagioco[3] == 1 || aTavoladagioco[4] == 1 && aTavoladagioco[5] == 1 && aTavoladagioco[6] == 1 || aTavoladagioco[7] == 1 && aTavoladagioco[8] == 1 && aTavoladagioco[9] == 1 || aTavoladagioco[1] == 1 && aTavoladagioco[4] == 1 && aTavoladagioco[7] == 1 || aTavoladagioco[2] == 1 && aTavoladagioco[5] == 1 && aTavoladagioco[8] == 1 || aTavoladagioco[3] == 1 && aTavoladagioco[6] == 1 && aTavoladagioco[9] == 1 || aTavoladagioco[1] == 1 && aTavoladagioco[5] == 1 && aTavoladagioco[9] == 1 || aTavoladagioco[3] == 1 && aTavoladagioco[5] == 1 && aTavoladagioco[7] == 1 ||aTavoladagioco[1] == 2 && aTavoladagioco[2] == 2 && aTavoladagioco[3] == 2 || aTavoladagioco[4] == 2 && aTavoladagioco[5] == 2 && aTavoladagioco[6] == 2 || aTavoladagioco[7] == 2 && aTavoladagioco[8] == 2 && aTavoladagioco[9] == 2 || aTavoladagioco[1] == 2 && aTavoladagioco[4] == 2 && aTavoladagioco[7] == 2 || aTavoladagioco[2] == 2 && aTavoladagioco[5] == 2 && aTavoladagioco[8] == 2 || aTavoladagioco[3] == 2 && aTavoladagioco[6] == 2 && aTavoladagioco[9] == 2 || aTavoladagioco[1] == 2 && aTavoladagioco[5] == 2 && aTavoladagioco[9] == 2 || aTavoladagioco[3] == 2 && aTavoladagioco[5] == 2 && aTavoladagioco[7] == 2 ){

            if (sTentativi % 2 == 0) {

                cout << "\n[+] Giocatore 2 (⭕️) ha vinto";

            } else {

                cout << "\n[+] Giocatore 1 (❌) ha vinto";
            }
            
            cout << '\n';
            
            for (int i = 1; i < 10; i++) {
                
                if (i == 4 || i == 7 || i == 10) {
                    
                    cout << '\n';
                }
                
                cout << aCopiamappa[i];
                
            }
            
            cout << '\n';

            return 0;

        }
        
        for (int i = 1; i < 10; i++) {
            
            if (i == 4 || i == 7 || i == 10) {
                
                cout << '\n';
            }
            
            cout << aCopiamappa[i];

        }
        
        cout << '\n' << '\n';
        

    }


    return 0;
}