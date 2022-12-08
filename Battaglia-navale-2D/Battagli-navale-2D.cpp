#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

//  Creato: 08/12/22
//  Da: swampkewe
//  Versione: 0.00 (non funziona)

void mostralamappa (string aCopiamappa[11][11]){
	
	cout << setw(26) << fixed << "A B C D E F G H I J";
	
	for (int i = 1; i < 11; i++) {
		
		cout << '\n' << setw(5) << i << " ";
		
		for(int b = 1, a = 1; b < 11; ++b, ++a) {
			cout << aCopiamappa[a][b];
		}
		
	}
	
}



int main() {
	setlocale(LC_ALL, "italian");
	
	int aTavoladagioco[11][11],
	iRiga = 0, iColonna = 0, iDadove = 0, intLettera = 0, intNumero = 0;
	string aCopiamappa[11][11];
	
	char iSelezione = 'f', iLettera = 'f';
	
//	fill(aCopiamappa[0][0], aCopiamappa[0][] + sizeof(aCopiamappa), "⬜️");
	fill(&aTavoladagioco[0][0], &aTavoladagioco[0][0] + sizeof(aTavoladagioco), 0 );
	
	for (int i = 1; i < 11; i++) {
		
		for(int b = 1, a = 1; b < 11; ++b, ++a) {
			aCopiamappa[a][b] = "⬜️";
		}
		
	}
	
	
	
	cout << "[=] Questo è layout sul quale dovrai posizionare le barche!\n\n";
	
	mostralamappa(aCopiamappa);
	
	
	cout << "\n\n[=] Ne dovrai posizionare:\n" <<
			"\t2:3 3:2 2:4 1:6";
			
	
	cout << "\n\n[=] Iniziamo con quella da 6";
	
	cout << "[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
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
			
			for (int i = iDadove; i < 11; i++) {
				
aTavoladagioco[intLettera][i] = 1;
				aCopiamappa[intLettera][i] = "🚢";
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
			
			for (int i = iDadove; i < 11; ++i) {
				
				aTavoladagioco[i][intNumero] = 1;
				aCopiamappa[intNumero][i] = "🚢";
				
			}
			break;
			
		default: break;
	}
	
	mostralamappa(aCopiamappa); // ceh guarda qui il codice si è auto distrutto
	
	
	for (int i = 1; i < 3; ++i){
		
		cout << "\n\n[=] Ora 2 da 4 (" << i << ")";
		
		cout << "[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
		cin >> iSelezione;
		
		switch (iSelezione) {
			case 'V': case 'v': 
				
				cout << "[?] Inserisci la lettera: ";
				cin >> iLettera;
				
				intLettera = ((int)iLettera - 96);
				
				cout << "[?] Da che punto vuoi inserire la nave: ";
				cin >> iDadove;
				
				while (iDadove > 10 || iDadove < 1 || aTavoladagioco[iDadove][intLettera] == 1 || aTavoladagioco[iDadove][intLettera + 1] == 1) {
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia compreso tra 0-10: ";
					cin >> iDadove;
				}
				
				for (int i = 0; i < 5; ++i) {
					
					aTavoladagioco[intLettera][i] = 1;
					
				}
				break;
			
			
			case 'o': case 'O':
				
				cout << "[?] Inserisci il numero: ";
				cin >> intNumero;
				
				cout << "[?] Da che punto vuoi inserire la nave: ";
				cin >> iDadove;
				
				while (iDadove > 10 || iDadove < 1 || aTavoladagioco[intNumero][iDadove] == 1 || aTavoladagioco[intNumero][iDadove + 1] == 1) {
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia <6: ";
					cin >> iDadove;
				}
				
				for (int i = 0; i < 5; ++i) {
					
					aTavoladagioco[i][intNumero] = 1;
					
				}
				break;
			
			default: break;
		}
		
	}
	
	for (int i = 1; i < 3; ++i){
		
		cout << "\n\n[=] Ora 2 da 3 (" << i << ")";
		
		cout << "[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
		cin >> iSelezione;
		
		switch (iSelezione) {
			case 'V': case 'v': 
				
				cout << "[?] Inserisci la lettera: ";
				cin >> iLettera;
				
				intLettera = ((int)iLettera - 96);
				
				cout << "[?] Da che punto vuoi inserire la nave: ";
				cin >> iDadove;
				
				while (iDadove > 10 || iDadove < 1 || aTavoladagioco[iDadove][intLettera] == 1 || aTavoladagioco[iDadove][intLettera + 1] == 1) {
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia compreso tra 0-10: ";
					cin >> iDadove;
				}
				
				for (int i = 0; i < 4; ++i) {
					
					aTavoladagioco[intLettera][i] = 1;
					
				}
				break;
			
			
			case 'o': case 'O':
				
				cout << "[?] Inserisci il numero: ";
				cin >> intNumero;
				
				cout << "[?] Da che punto vuoi inserire la nave: ";
				cin >> iDadove;
				
				while (iDadove > 10 || iDadove < 1 || aTavoladagioco[intNumero][iDadove] == 1 || aTavoladagioco[intNumero][iDadove + 1] == 1) {
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia <6: ";
					cin >> iDadove;
				}
				
				for (int i = 0; i < 4; ++i) {
					
					aTavoladagioco[i][intNumero] = 1;
					
				}
				break;
			
			default: break;
		}
		
	}
	
	for (int i = 1; i < 4; ++i){
		
		cout << "\n\n[=] Ora 3 da 2 (" << i << ")";
		
		cout << "[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
		cin >> iSelezione;
		
		switch (iSelezione) {
			case 'V': case 'v': 
				
				cout << "[?] Inserisci la lettera: ";
				cin >> iLettera;
				
				intLettera = ((int)iLettera - 96);
				
				cout << "[?] Da che punto vuoi inserire la nave: ";
				cin >> iDadove;
				
				while (iDadove > 10 || iDadove < 1 || aTavoladagioco[iDadove][intLettera] == 1 || aTavoladagioco[iDadove][intLettera + 1] == 1) {
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia compreso tra 0-10: ";
					cin >> iDadove;
				}
				
				for (int i = 0; i < 3; ++i) {
					
					aTavoladagioco[intLettera][i] = 1;
					
				}
				break;
			
			
			case 'o': case 'O':
				
				cout << "[?] Inserisci il numero: ";
				cin >> intNumero;
				
				cout << "[?] Da che punto vuoi inserire la nave: ";
				cin >> iDadove;
				
				while (iDadove > 10 || iDadove < 1 || aTavoladagioco[intNumero][iDadove] == 1 || aTavoladagioco[intNumero][iDadove + 1] == 1) {
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia <6: ";
					cin >> iDadove;
				}
				
				for (int i = 0; i < 3; ++i) {
					
					aTavoladagioco[i][intNumero] = 1;
					
				}
				break;
			
			default: break;
		}
		
	}
	
	for(int a = 0; a < 11; a++)
		{
			for(int b = 0; b < 11; b++)
				{
					cout << aTavoladagioco[a][b] << " ";
				}
			cout << endl;
		} 

	
	return 0;
}