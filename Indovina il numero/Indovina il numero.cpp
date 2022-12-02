#include <iostream>
#include <random>

using namespace std;

//  Creato: 02/12/22
//  Da: swampkewe
//  Versione: 0.00 (non ottimizzata!)


int main() {
	setlocale(LC_ALL, "italian");
	
	int iFino, iProvo, sSupporto, sSupportoII, i = 0;
	char scelta;
	
	cout << "Ciao io sono un giochino nel quale tu dovrai indovinare un numero casuale.";
	
	cout << "\nMa prima di tutto stabiliamo fino a che numero vuoi tentare la tua fortuna: ";

			
	do {
		
		sSupportoII = 0;
		
		while (!(cin >> iFino)) {
			
			cout << "[!] Devi inserire un numero: ";
			cin.clear();
			cin.ignore(222, '\n');
			
		}
		
		
		while (iFino <= 6) {
			
			cout << "Troppo facile... inserisci un numero più grande: ";
			cin >> iFino;
			
		}
		
		sSupporto = iFino;
		
		random_device rd;
		mt19937 rNumerocasuale(rd());
		uniform_int_distribution<int> dist(1, iFino);
		
		int sMemonumero = dist(rNumerocasuale);
		
		if (iFino % 2 == 0 && iFino >= 16)
			
			iFino = iFino / 2;
		
		else if (iFino % 3 == 0 && iFino >= 21)
			
			iFino = iFino / 3;
		
		
		
		cout << "\n[+] Hai " << iFino << " tentativi!\n";
		
		
		for (i = 0; i < iFino && sSupportoII != 1; ++i) {
			
			cout << "Tentativo n" << i + 1 << ": ";
			cin >> iProvo;
			
			if (iProvo < 1 || iProvo > sSupporto) {
				
				cout << "Beh, per questo errore i tuoi tentativi diminuiscono di due e non di uno, non sbagliare più!\n";
		
				++i;
				
			}
			
			if (iProvo == sMemonumero) {
				
				cout << "\n[&] HAI VINTO";
				++ sSupportoII;
			
			}
			
		}
		
		if (i == iFino) {
			
			cout << "\n[-] Hai perso a causa dei tentativi finiti!\n";
			
		
		}
		
		
		cout << "\nVuoi giocare un'altra volta? [S/N]: ";
		cin >> scelta;
		
		if (scelta == 's' || scelta == 'S') {
			
			cout << "\nInserisci fino a che numero: ";
		
		}
		
		
	} while (scelta == 's' || scelta == 'S');

	cout << "\nAlla prossima!";
	
	
	
	return 0;
}