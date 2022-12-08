#include <iostream>
#include <string>

using namespace std;

//  Creato: 07/12/22
//  Da: swampkewe
//  Versione: 0.03

void mostralamappa(string aCopiamappa[]){
    
    for (int i = 1; i < 10; i++) {
        
        
        if (i == 4 || i == 7 || i == 10) {
            
            cout << '\n';
        }
        
        cout << aCopiamappa[i];
        
    }
    
}

void controllo (int &iDove){
    
    while (!(cin >> iDove)) {
        
        cout << "[!] Posizione non valida: ";
        
        cin.clear();
        cin.ignore(123, '\n');
    }
    
}

void erorre(int aTavoladagioco[], int &iDove){
    
    controllo(iDove);
    
    while (aTavoladagioco[iDove] == 1 || aTavoladagioco[iDove] == 2){  //  lo potevo mettere in un while unico, ma voglio che stampi dei messaggi diversi
        cout << "[!] La posizione è già occupata, riprova: ";
        controllo(iDove);
        
    }
    
    while (iDove > 9 || iDove < 1){
        cout << "[!] Non puoi uscire dal layout, riprova: ";
        controllo(iDove);
        
    }
    
}




int main() {
    setlocale(LC_ALL, "italian");

    int aTavoladagioco[10],
    sQuanti = sizeof(aTavoladagioco)/sizeof(aTavoladagioco[0]),
    sTentativi = 0, iDove = 0;
    string aCopiamappa[10];
    

    fill(aTavoladagioco, aTavoladagioco + sQuanti, 0);
    fill(aCopiamappa, aCopiamappa + sQuanti, "⬜️");

    cout << "Layout del gioco è seguente:\n[1][2][3]\n[4][5][6]\n[7][8][9]";
    cout << "\nIl giocatore uno gioca con la ❌ e il giocatore due con ⭕️";

    while (sQuanti > sTentativi){

        sTentativi ++;
        
        if (sTentativi == 10){
            
            cout << "Nessuno ha vinto!";
            return 0;
            
        }


        if (sTentativi % 2 == 0) {
            cout << "\n\nTocca al giocatore due: ";
            
            erorre(aTavoladagioco, iDove);
            
            aTavoladagioco[iDove] = 2;
            aCopiamappa[iDove] = "⭕️";
            

        } else {
            cout << "\n\nTocca al giocatore uno: ";

            erorre(aTavoladagioco, iDove);

            aTavoladagioco[iDove] = 1;
            aCopiamappa[iDove] = "❌";

        }
        
        //  non so come otimizzare questa parte

        if (aTavoladagioco[1] == 1 && aTavoladagioco[2] == 1 && aTavoladagioco[3] == 1 || aTavoladagioco[4] == 1 && aTavoladagioco[5] == 1 && aTavoladagioco[6] == 1 || aTavoladagioco[7] == 1 && aTavoladagioco[8] == 1 && aTavoladagioco[9] == 1 || aTavoladagioco[1] == 1 && aTavoladagioco[4] == 1 && aTavoladagioco[7] == 1 || aTavoladagioco[2] == 1 && aTavoladagioco[5] == 1 && aTavoladagioco[8] == 1 || aTavoladagioco[3] == 1 && aTavoladagioco[6] == 1 && aTavoladagioco[9] == 1 || aTavoladagioco[1] == 1 && aTavoladagioco[5] == 1 && aTavoladagioco[9] == 1 || aTavoladagioco[3] == 1 && aTavoladagioco[5] == 1 && aTavoladagioco[7] == 1 ||aTavoladagioco[1] == 2 && aTavoladagioco[2] == 2 && aTavoladagioco[3] == 2 || aTavoladagioco[4] == 2 && aTavoladagioco[5] == 2 && aTavoladagioco[6] == 2 || aTavoladagioco[7] == 2 && aTavoladagioco[8] == 2 && aTavoladagioco[9] == 2 || aTavoladagioco[1] == 2 && aTavoladagioco[4] == 2 && aTavoladagioco[7] == 2 || aTavoladagioco[2] == 2 && aTavoladagioco[5] == 2 && aTavoladagioco[8] == 2 || aTavoladagioco[3] == 2 && aTavoladagioco[6] == 2 && aTavoladagioco[9] == 2 || aTavoladagioco[1] == 2 && aTavoladagioco[5] == 2 && aTavoladagioco[9] == 2 || aTavoladagioco[3] == 2 && aTavoladagioco[5] == 2 && aTavoladagioco[7] == 2 ){

            if (sTentativi % 2 == 0) {

                cout << "\n[+] Giocatore 2 (⭕️) ha vinto\n";

            } else {

                cout << "\n[+] Giocatore 1 (❌) ha vinto\n";
            }
        
            mostralamappa(aCopiamappa);

            return 0;

        }
    
        mostralamappa(aCopiamappa);
        

    }


    return 0;
}