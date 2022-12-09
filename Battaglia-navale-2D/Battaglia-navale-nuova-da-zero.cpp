#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

//  Creato: 08/12/22
//  Da: swampkewe
//  Versione: 0.00 (non funziona)

void mostralamappa (string aCopiamappa[11][11]){
	
	cout << "       A B C D |E F G H I J";
			
	for (int i = 1; i < 11; i++) {
			cout << '\n' << setw(5) << i << " ";
			
			for (int j = 1; j < 11; j++) {
				
				cout << aCopiamappa[i][j];
			}
			
		}
	
}



int main() {
	setlocale(LC_ALL, "italian");
	
	int aTavoladagioco[11][11],
	iDadove = 0, intLettera, intNumero = 0;
	string aCopiamappa[11][11];
	
	char iSelezione = 'f', iLettera = 'f';
	

	for (int i = 1; i < 11; i++) {
		
		for (int j = 1; j < 11; j++) {
			
			aTavoladagioco[i][j] = 0;
			
		}
		
	}
	
	for (int i = 1; i < 11; i++) {
			
		for (int j = 1; j < 11; j++) {
			
			aCopiamappa[i][j] = "⬜️";
			
		}
			
	}
		
	
	
	cout << "[=] Questo è layout sul quale dovrai posizionare le barche!\n\n";
	
	mostralamappa(aCopiamappa);
	
	
	cout << "\n\n[=] Ne dovrai posizionare:\n" <<
			"\t2:3 3:2 2:4 1:6";
			
	
	cout << "\n\n[=] Iniziamo con quella da 6";
	
	cout << "\n[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
	cin >> iSelezione;
	
	switch (iSelezione) {
		case 'V': case 'v': 
			
			cout << "[?] Inserisci la lettera: ";
			cin >> iLettera;
			
			intLettera = ((int)iLettera - 96);
			
			cout << "[?] Da che punto vuoi inserire la nave: ";
			cin >> iDadove;
			
			while (iDadove > 5) {
				cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia <6: ";
				cin >> iDadove;
			}
			
			for (int i = iDadove; i < iDadove + 6; i++) {
				
				aTavoladagioco[i][intLettera] = 1;
				aCopiamappa[i][intLettera] = "\u26F5";
			}

			break;


		case 'o': case 'O': 
			
			cout << "[?] Inserisci il numero: ";
		
			cin >> intNumero;
			
			cout << "[?] Da che punto vuoi inserire la nave: ";
			cin >> iDadove;
			
			while (iDadove > 5) {
				cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia <6: ";
				cin >> iDadove;
			}
			
			for (int i = iDadove; i < 7; ++i) {
				
				aTavoladagioco[intNumero][i] = 1;
				aCopiamappa[intNumero][i] = "\u26F5";
			}

		break;

	
		default: break;
	}
	
	mostralamappa(aCopiamappa);
	
	cout << '\n';
	
	for (int i = 1; i < 11; i++) {
		
		cout << '\n';
		
		for (int j = 1; j < 11; j++) {
			
			cout << aTavoladagioco[i][j] << " ";
				
		}
				
		
	}

	
	cout << "H3Y";
	
	return 0;
}