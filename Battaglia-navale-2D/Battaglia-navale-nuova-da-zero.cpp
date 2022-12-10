#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

//  Creato: 08/12/22
//  Da: swampkewe
//  Versione: 0.01 (funziona, ma manca l'optimizzazioene)

void mostralamappa (string aCopiamappa[11][11]){
	
	cout << "\n\n       A B C D |E F G H I J";
			
	for (int i = 1; i < 11; i++) {
		cout << '\n' << setw(5) << i << " ";
		
		for (int j = 1; j < 11; j++) {
			
			cout << aCopiamappa[i][j];
		}
			
	}
	
	cout << "\n\n";
		
}


void mostranumerini (int aTavoladagioco[11][11]){ //  una funzione tecnica, non serve per il gioco
	
	cout << '\n';
	
	for (int i = 1; i < 11; i++) {
		
		cout << '\n';
		
		for (int j = 1; j < 11; j++) {
			
			cout << aTavoladagioco[i][j] << " ";
			
		}
		
	}
	
}


void riempiremappa (string aCopiamappa[11][11]) {
	
	for (int i = 1; i < 11; i++) {
		
		for (int j = 1; j < 11; j++) {
			
			aCopiamappa[i][j] = "⬜️";
			
		}
		
	}
	
}


void testlettera (char &iLettera) {
	
	while (!(cin >> iLettera)) {
		
		cout << "[!] Devi inseire una lettera: ";
		
		cin.clear();
		cin.ignore(123, '\n');
	}
	
}

void testnumero (int &intNumero) {
	
	while (!(cin >> intNumero)) {
		
		cout << "[!] Devi inseire un numero: ";
		
		cin.clear();
		cin.ignore(123, '\n');
	}
	
}



int main() {
	setlocale(LC_ALL, "italian");
	
	int aTavoladagioco[11][11],
	iDadove, intLettera, intNumero;
	string aCopiamappa[11][11];
	
	char iSelezione, iLettera;
	
	//  per il attacco 
	
	int iPosizioneNumero = 0, intIposizioneLettera = 0, iContatoreAttacco = 0;
	char iPosizioneLettera;
	

	for (int i = 1; i < 11; i++) {
		
		for (int j = 1; j < 11; j++) {
			
			aTavoladagioco[i][j] = 0;
			
		}
		
	}
	
	riempiremappa(aCopiamappa);
	
	cout << "[=] Questo è layout sul quale dovrai posizionare le barche!";
	
	mostralamappa(aCopiamappa);
	
	
	cout << "[=] Ne dovrai posizionare:\n" <<
			"\t2:3 3:2 2:4 1:6";
			
	
	cout << "\n\n[=] Iniziamo con quella da 6";
	
	cout << "\n[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
	cin >> iSelezione;
	
	switch (iSelezione) {
		case 'V': case 'v': 
			
			cout << "[?] Inserisci la lettera: ";
			testlettera(iLettera);
			
			intLettera = ((int)iLettera - 96);
			
			cout << "[?] Da che punto vuoi inserire la nave: ";
			testnumero(iDadove);
			
			while (iDadove > 5) {
				cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia <6: ";
				testnumero(iDadove);
			}
			
			for (int i = iDadove; i < iDadove + 6; i++) {
				
				aTavoladagioco[i][intLettera] = 1;
				aCopiamappa[i][intLettera] = "\u26F5";
			}

			break;


		case 'o': case 'O': 
			
			cout << "[?] Inserisci il numero: ";
			testnumero(intNumero);
			
			cout << "[?] Da che lettera vuoi inserire la nave: ";
			testlettera(iLettera);
			
			intLettera = ((int)iLettera - 96);
			
			while (intLettera > 5) {
				intLettera = 0;
				cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci una lettera valida: ";
				testlettera(iLettera);
				intLettera = ((int)iLettera - 96);
			}
			
			for (int i = intLettera; i < intLettera + 6; i++) {
				
				aTavoladagioco[intNumero][i] = 1;
				aCopiamappa[intNumero][i] = "\u26F5";
			}
			
			break;
	
	}
	
	for (int i = 1; i < 3; ++i){
		
		mostralamappa(aCopiamappa);
		
		cout << "[=] Ora 2 da 4 (" << i << ")";
		
		cout << "\n[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
		cin >> iSelezione;
		
		switch (iSelezione) {
			case 'V': case 'v': 
				
				cout << "[?] Inserisci la lettera: ";
				testlettera(iLettera);
				
				intLettera = ((int)iLettera - 96);
				
				cout << "[?] Da che punto vuoi inserire la nave: ";
				testnumero(iDadove);
				
				while (iDadove > 10 || iDadove < 1 || aTavoladagioco[iDadove][intLettera] == 1 || aTavoladagioco[iDadove][intLettera + 1] == 1 || iDadove > 7) {
					iDadove = 0;
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia compreso tra 0-10: ";
					testnumero(iDadove);
				}
				
				for (int i = iDadove; i < iDadove + 4; i++) {
					
					aTavoladagioco[i][intLettera] = 1;
					aCopiamappa[i][intLettera] = "\u26F5";
				}

				break;
			
			
			case 'o': case 'O':
				
				cout << "[?] Inserisci il numero: ";
				testnumero(intNumero);
				
				cout << "[?] Da che lettera vuoi inserire la nave: ";
				testlettera(iLettera);
				
				intLettera = ((int)iLettera - 96);
				
				while (intLettera > 10 || intLettera < 1 || aTavoladagioco[intNumero][intLettera] == 1 || aTavoladagioco[intNumero][intLettera + 1] == 1 || intLettera > 7) {
					intLettera = 0;
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci una lettera valida: ";
					testlettera(iLettera);
					intLettera = ((int)iLettera - 96);
				}
				
				for (int i = intLettera; i < intLettera + 4; i++) {
					
					aTavoladagioco[intNumero][i] = 1;
					aCopiamappa[intNumero][i] = "\u26F5";
				}
				
				break;
			
		}
		
	}
	
	//
	
	for (int i = 1; i < 3; ++i){
		
		mostralamappa(aCopiamappa);
		
		cout << "[=] Ora 2 da 3 (" << i << ")";
		
		cout << "\n[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
		cin >> iSelezione;
		
		switch (iSelezione) {
			case 'V': case 'v': 
				
				cout << "[?] Inserisci la lettera: ";
				testlettera(iLettera);
				
				intLettera = ((int)iLettera - 96);
				
				cout << "[?] Da che punto vuoi inserire la nave: ";
				testnumero(iDadove);
				
				while (iDadove > 10 || iDadove < 1 || aTavoladagioco[iDadove][intLettera] == 1 || aTavoladagioco[iDadove][intLettera + 1] == 1 || iDadove > 8) {
					iDadove = 0;
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia compreso tra 0-10: ";
					testnumero(iDadove);
				}
				
				for (int i = iDadove; i < iDadove + 3; i++) {
					
					aTavoladagioco[i][intLettera] = 1;
					aCopiamappa[i][intLettera] = "\u26F5";
				}
				
				break;
			
			
			case 'o': case 'O':
				
				cout << "[?] Inserisci il numero: ";
				testnumero(intNumero);
				
				cout << "[?] Da che lettera vuoi inserire la nave: ";
				testlettera(iLettera);
				
				intLettera = ((int)iLettera - 96);
				
				while (intLettera > 10 || intLettera < 1 || aTavoladagioco[intNumero][intLettera] == 1 || aTavoladagioco[intNumero][intLettera + 1] == 1 || intLettera > 8) {
					intLettera = 0;
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci una lettera valida: ";
					testlettera(iLettera);
					intLettera = ((int)iLettera - 96);
				}
				
				for (int i = intLettera; i < intLettera + 3; i++) {
					
					aTavoladagioco[intNumero][i] = 1;
					aCopiamappa[intNumero][i] = "\u26F5";
				}
				
				break;
			
		}
		
		
	}

	// //
	
	for (int i = 1; i < 4; ++i){
		
		mostralamappa(aCopiamappa);
		
		cout << "[=] Ora 3 da 2 (" << i << ")";
		
		cout << "\n[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
		cin >> iSelezione;
		
		switch (iSelezione) {
			case 'V': case 'v': 
				
				cout << "[?] Inserisci la lettera: ";
				testlettera(iLettera);
				
				intLettera = ((int)iLettera - 96);
				
				cout << "[?] Da che punto vuoi inserire la nave: ";
				testnumero(iDadove);
				
				while (iDadove > 10 || iDadove < 1 || aTavoladagioco[iDadove][intLettera] == 1 || aTavoladagioco[iDadove][intLettera + 1] == 1 || iDadove > 9) {
					iDadove = 0;
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci un valore che sia compreso tra 0-10: ";
					testnumero(iDadove);
				}
				
				for (int i = iDadove; i < iDadove + 2; i++) {
					
					aTavoladagioco[i][intLettera] = 1;
					aCopiamappa[i][intLettera] = "\u26F5";
				}
				
				break;
			
			
			case 'o': case 'O':
				
				cout << "[?] Inserisci il numero: ";
				testnumero(intNumero);
				
				cout << "[?] Da che lettera vuoi inserire la nave: ";
				testlettera(iLettera);
				
				intLettera = ((int)iLettera - 96);
				
				while (intLettera > 10 || intLettera < 1 || aTavoladagioco[intNumero][intLettera] == 1 || aTavoladagioco[intNumero][intLettera + 1] == 1 || intLettera > 9) {
					intLettera = 0;
					cout << "[!] La tua barca non può uscire dal layout del gioco, inserisci una lettera valida: ";
					testlettera(iLettera);
					intLettera = ((int)iLettera - 96);
				}
				
				for (int i = intLettera; i < intLettera + 2; i++) {
					
					aTavoladagioco[intNumero][i] = 1;
					aCopiamappa[intNumero][i] = "\u26F5";
				}
				
				break;
			
		}
		
		
	}

	mostralamappa(aCopiamappa);
	riempiremappa(aCopiamappa);
	
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "[!] Questo è il layout, dovrai indovinare 26 posizioni nelle quali il tuo avversario ha posizionato le seguenti barche: ";
	
	cout << "[!] Hai a disposizione soltanto 40 mosse! Non sprecarle!\n\t2:3 3:2 2:4 1:6";
	
	for (int i = 0; i < 40; i++) {
		
		mostralamappa(aCopiamappa);
		
		cout << "\n[+] Questo è il tuo (" << i + 1 << ") tentativo";
		
		
		cout << "[A] Inserisci il numero: ";
		cin >> iPosizioneNumero;
		
		cout << "[A] Inserisci la lettera: ";
		cin >> iPosizioneLettera;
		intIposizioneLettera = ((int)iPosizioneLettera - 96);
		
		if (aTavoladagioco[iPosizioneNumero][intIposizioneLettera] == 1) {
			
			iContatoreAttacco ++;
			cout << "Complimenti hai colpito la barca!";
			aTavoladagioco[iPosizioneNumero][intIposizioneLettera] = 2;
			aCopiamappa[iPosizioneNumero][intIposizioneLettera] = "\U0001f4a3";
			
			
		} else {
			
			cout << "Purtroppo non hai colpito la barca!";
			aTavoladagioco[iPosizioneNumero][intIposizioneLettera] = 2;
			aCopiamappa[iPosizioneNumero][intIposizioneLettera] = "\U0001f30a";
		}
		
		if (iContatoreAttacco == 26) {
			
			cout << "[&] Congrutulazioni hai vinto!";
			return 0;
			
		}
		
	}
	
	cout << "[!] Hai perso perchè hai finito i tentativi, misdispiace!";
	
	return 0;
}