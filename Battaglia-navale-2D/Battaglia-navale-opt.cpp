#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

//  Creato: 08/12/22
//  Da: swampkewe
//  Versione: 0.03 ottimizzata "ok" (poteva essere meglio ma sono pigro), mancano i casi. Rinominato tutte le variabili e funzioni per capire meglio


void fRiempire_interfaccia (string aCopia_le_posizioni[11][11], string il_carattere) {
	
	for (int i = 1; i < 11; i++) {
		
		for (int j = 1; j < 11; j++) {
			
			aCopia_le_posizioni[i][j] = il_carattere;
			
		}
		
	}
	
}


void mostranumerini (int aLayout_gioco[11][11]){ //  una funzione tecnica, non serve per il gioco
	
	cout << '\n';
	
	for (int i = 1; i < 11; i++) {
		
		cout << '\n';
		
		for (int j = 1; j < 11; j++) {
			
			cout << aLayout_gioco[i][j] << " ";
			
		}
		
	}
	
}

void fMosta_linterfaccia (string aCopia_le_posizioni[11][11]){
	
	cout << "\n\n      A B C D E F G H I J"; //  era più semplice fare così
	
	for (int i = 1; i < 11; i++) {
		cout << '\n' << setw(5) << i << " ";
		
		for (int j = 1; j < 11; j++) {
			
			cout << aCopia_le_posizioni[i][j];
		}
		
	}
	
	cout << "\n\n";
	
}

void fTest_lettera_char (char &iLettera) {
	
	while (!(cin >> iLettera)) {
		
		cout << "[!] Devi inseire una lettera: ";
		
		cin.clear();
		cin.ignore(123, '\n');
	}
	
}

void fTest_numero_int (int &sPosizione_numero_int) {
	
	while (!(cin >> sPosizione_numero_int)) {
		
		cout << "[!] Devi inseire un numero: ";
		
		cin.clear();
		cin.ignore(123, '\n');
	}
	
}

void fInserimento_navi (int lunghezza_della_barca, int quante_barche, int aLayout_gioco[11][11], int sPosizione_lettera_int, int sPosizione_numero_int, string aCopia_le_posizioni[11][11], int sPosizione_accettata) {
		
	char iSelezione = '0', iLettera = '0', iScelta = '0';
	
	for (int i = 0; i < quante_barche; ++i){
	
//	do {
		
		cout << "[=] Ora " << quante_barche << " da " << lunghezza_della_barca << " (" << i + 1 << ")";
		
		cout << "\n[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
		cin >> iSelezione;
		
		switch (iSelezione) {
			case 'V': case 'v': 
				
				//do {
				
					cout << "[?] Inserisci la lettera: ";
					fTest_lettera_char(iLettera);
					
					sPosizione_lettera_int = ((int)iLettera - 96);
					
					cout << "[?] Da che numero vuoi inserire la nave: ";
					fTest_numero_int(sPosizione_numero_int);
					
				while (sPosizione_numero_int > 10 || sPosizione_numero_int < 1 || aLayout_gioco[sPosizione_numero_int][sPosizione_lettera_int] == 1 || aLayout_gioco[sPosizione_numero_int][sPosizione_lettera_int + 1] == 1 || sPosizione_numero_int > sPosizione_accettata) {
						
						cout << "[!] Posizione non valida, riprova: ";
						fTest_numero_int(sPosizione_numero_int);
					}
					
					for (int i = sPosizione_numero_int; i < sPosizione_numero_int + lunghezza_della_barca; i++) {
						
						aLayout_gioco[i][sPosizione_lettera_int] = 1;
						aCopia_le_posizioni[i][sPosizione_lettera_int] = "\u26F5";
					}
					
					break;
			
			//	} while (aLayout_gioco[(1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 & 11)][sPosizione_lettera_int] == 1);
			
			// iDadove > 11 || iDadove < 1 || aLayout_gioco[sPosizione_lettera_int][iDadove] == 1 ||  sPosizione_lettera_int > (lunghezza_della_barca * 2) + 2
			
			case 'o': case 'O':
				//do {
					
					cout << "[?] Inserisci il numero: ";
					fTest_numero_int(sPosizione_numero_int);
					
					cout << "[?] Da che lettera vuoi inserire la nave: ";
					fTest_lettera_char(iLettera);
					
					sPosizione_lettera_int = ((int)iLettera - 96);
					
					while (sPosizione_lettera_int > 10 || sPosizione_lettera_int < 1 || aLayout_gioco[sPosizione_numero_int][sPosizione_lettera_int] == 1 || aLayout_gioco[sPosizione_numero_int][sPosizione_lettera_int + 1] == 1 || sPosizione_lettera_int > sPosizione_accettata) {
						
						cout << "[!] Posizione non valida, riprova: ";
						fTest_lettera_char(iLettera);
						
						sPosizione_lettera_int = ((int)iLettera - 96);
					}
					
					for (int i = sPosizione_lettera_int; i < sPosizione_lettera_int + lunghezza_della_barca; i++) {
						
						aLayout_gioco[sPosizione_numero_int][i] = 1;
						aCopia_le_posizioni[sPosizione_numero_int][i] = "\u26F5";
					}
				
					break;
				
					//} while (aLayout_gioco[sPosizione_lettera_int][(1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 & 11)] == 1);
			
			default:
				break;
				
//				cout << "\n[!] Digita 's' se vuoi giocare 'n' se no: ";
//				cin >> iScelta;
//				
//				if (iScelta != 's' || iScelta != 'S')
				
		}
		
//	} while (iScelta == 's' || iScelta == 'S');
		
	fMosta_linterfaccia(aCopia_le_posizioni);
	
	}
	
	
}


void fGioco_user (int aLayout_gioco[11][11], int sPosizione_numero_int, string aCopia_le_posizioni[11][11], int sContatore_navi_abbattute, int iPosizioneNumero, char iPosizioneLettera, int intIposizioneLettera) {
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "[!] Questo è il layout, dovrai indovinare 26 posizioni nelle quali il tuo avversario ha posizionato le seguenti navi:\n\t2:3 3:2 2:4 1:6";
	
	cout << "[!] Hai a disposizione soltanto 40 mosse! Non sprecarle!";
	
	for (int i = 0; i < 40; i++) {
		
	fMosta_linterfaccia(aCopia_le_posizioni);
		
		cout << "\n[+] Questo è il tuo (" << i + 1 << ") tentativo";
		
		
		cout << "\n[A] Inserisci il numero: ";
		cin >> iPosizioneNumero;
		
		cout << "\n[A] Inserisci la lettera: ";
		cin >> iPosizioneLettera;
		intIposizioneLettera = ((int)iPosizioneLettera - 96);
		
		if (aLayout_gioco[iPosizioneNumero][intIposizioneLettera] == 1) {
			
			sContatore_navi_abbattute ++;
			cout << "Complimenti hai colpito la barca!";
			aLayout_gioco[iPosizioneNumero][intIposizioneLettera] = 2;
			aCopia_le_posizioni[iPosizioneNumero][intIposizioneLettera] = "\U0001f4a3";
			
		} else {
			
			cout << "Purtroppo non hai colpito la barca!";
			aLayout_gioco[iPosizioneNumero][intIposizioneLettera] = 2;
			aCopia_le_posizioni[iPosizioneNumero][intIposizioneLettera] = "\U0001f30a";
			
		}
		
		if (sContatore_navi_abbattute == 26) {
			
			cout << "\n[&] Congrutulazioni hai vinto!";
			
		}
		
	}

}


int main() {
	setlocale(LC_ALL, "italian");
	
	int aLayout_gioco[11][11]{},
	sPosizione_lettera_int = 0, sPosizione_numero_int = 0;
	string aCopia_le_posizioni[11][11];
	
	char iSelezione, iLettera;
	
	//  =========== Attacco da parte del giocatore
	
	int iPosizioneNumero = 0, intIposizioneLettera = 0, sContatore_navi_abbattute = 0;
	char iPosizioneLettera;

	//  =========== Preparazzione gioco
	
	fRiempire_interfaccia(aCopia_le_posizioni, "\u2B1C"); //  interfaccia pronta per l'input delle navi
	
	cout << "[=] Questo è layout sul quale dovrai posizionare le barche!";
	fMosta_linterfaccia(aCopia_le_posizioni);
	cout << "[=] Ne dovrai posizionare:\n\t2:3 3:2 2:4 1:6\n\n";
			
	fInserimento_navi(6, 1, aLayout_gioco, sPosizione_lettera_int, sPosizione_numero_int, aCopia_le_posizioni, 6);
	fInserimento_navi(4, 2, aLayout_gioco, sPosizione_lettera_int, sPosizione_numero_int, aCopia_le_posizioni, 7);
	fInserimento_navi(3, 2, aLayout_gioco, sPosizione_lettera_int, sPosizione_numero_int, aCopia_le_posizioni, 8);
	fInserimento_navi(2, 3, aLayout_gioco, sPosizione_lettera_int, sPosizione_numero_int, aCopia_le_posizioni, 9);

	//  =========== il gioco
	
	fRiempire_interfaccia(aCopia_le_posizioni, "\u2B1C"); //  azera linterfaccia
	
	fGioco_user(aLayout_gioco, sPosizione_numero_int, aCopia_le_posizioni, sContatore_navi_abbattute, iPosizioneNumero, iPosizioneLettera, intIposizioneLettera);

	cout << "[!] Hai perso perchè hai finito i tentativi, misdispiace!";
	
	return 0;
}