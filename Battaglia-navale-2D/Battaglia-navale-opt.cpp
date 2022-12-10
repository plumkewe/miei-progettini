#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

//  Creato: 08/12/22
//  Da: swampkewe
//  Versione: 0.02 optimizzazione ok (poteva essere meglio ma sono pigro) , mancano i casi

void riempiremappa (string aCopiamappa[11][11]) {
	
	for (int i = 1; i < 11; i++) {
		
		for (int j = 1; j < 11; j++) {
			
			aCopiamappa[i][j] = "⬜️";
			
		}
		
	}
	
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



void mostralamappa (string aCopiamappa[11][11]){
	
	cout << "\n\n       A B C D E F G H I J";
	
	for (int i = 1; i < 11; i++) {
		cout << '\n' << setw(5) << i << " ";
		
		for (int j = 1; j < 11; j++) {
			
			cout << aCopiamappa[i][j];
		}
		
	}
	
	cout << "\n\n";
	
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

void universalriempimento (int lunghezza_della_barca, int quante_barche, int aTavoladagioco[11][11], int iDadove, int intLettera, int intNumero, string aCopiamappa[11][11]) {
		
	char iSelezione, iLettera;
	
	for (int i = 0; i < quante_barche; ++i){
		
		cout << "[=] Ora " << quante_barche << " da " << lunghezza_della_barca << " (" << i + 1 << ")";
		
		cout << "\n[?] La vuoi inserire verticalmente o orizontalmente (v/o): ";
		cin >> iSelezione;
		
		switch (iSelezione) {
			case 'V': case 'v': 
				
				cout << "[?] Inserisci la lettera: ";
				testlettera(iLettera);
				
				intLettera = ((int)iLettera - 96);
				
				cout << "[?] Da che numero vuoi inserire la nave: ";
				testnumero(iDadove);
				
				while (iDadove > 11 || iDadove < 1 || aTavoladagioco[intLettera][iDadove] == 1 || aTavoladagioco[intLettera][iDadove + lunghezza_della_barca] == 1 ||  iDadove > (lunghezza_della_barca * 2) + 2) {
					
					cout << "[!] Posizione non valida, riprova: ";
					testnumero(iDadove);
				}
				
				for (int i = iDadove; i < iDadove + lunghezza_della_barca; i++) {
					
					aTavoladagioco[i][intLettera] = 1;
					aCopiamappa[i][intLettera] = "\u26F5";
				}
				
				break;
			// iDadove > 11 || iDadove < 1 || aTavoladagioco[intLettera][iDadove] == 1 ||  intLettera > (lunghezza_della_barca * 2) + 2
			
			case 'o': case 'O':
				
				cout << "[?] Inserisci il numero: ";
				testnumero(intNumero);
				
				cout << "[?] Da che lettera vuoi inserire la nave: ";
				testlettera(iLettera);
				
				intLettera = ((int)iLettera - 96);
				
				while (intLettera > 11 || intLettera < 1 || aTavoladagioco[intNumero][intLettera] == 1 || aTavoladagioco[intNumero][intLettera + lunghezza_della_barca] == 1 ||  intLettera > (lunghezza_della_barca * 2) + 2) {
					
					cout << "[!] Posizione non valida, riprova: ";
					testlettera(iLettera);
					
					intLettera = ((int)iLettera - 96);
				}
				
				for (int i = intLettera; i < intLettera + lunghezza_della_barca; i++) {
					
					aTavoladagioco[intNumero][i] = 1;
					aCopiamappa[intNumero][i] = "\u26F5";
				}
				
				
				break;
			
			default: 
				
				break;
			
		
		}
		
	mostralamappa(aCopiamappa);
	
	}
	
	
}


void ilgioco (int aTavoladagioco[11][11], int intNumero, string aCopiamappa[11][11], int iContatoreAttacco, int iPosizioneNumero, char iPosizioneLettera, int intIposizioneLettera) {
	
	
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
			
		}
		
	}

}


int main() {
	setlocale(LC_ALL, "italian");
	
	int aTavoladagioco[11][11],
	iDadove = 0, intLettera = 0, intNumero = 0;
	string aCopiamappa[11][11];
	
	char iSelezione, iLettera;
	
	//  per il attacco 
	
	int iPosizioneNumero = 0, intIposizioneLettera = 0, iContatoreAttacco = 0;
	char iPosizioneLettera;
	

	for (int i = 0; i < 11; i++) {
		
		for (int j = 0; j < 11; j++) {
			
			aTavoladagioco[i][j] = 0;
			
		}
		
	}
	
	riempiremappa(aCopiamappa);
	
	cout << "[=] Questo è layout sul quale dovrai posizionare le barche!";
	
	mostralamappa(aCopiamappa);
	
	
	cout << "[=] Ne dovrai posizionare:\n" <<
			"\t2:3 3:2 2:4 1:6\n\n";
			
	universalriempimento(6, 1, aTavoladagioco, iDadove, intLettera, intNumero, aCopiamappa);
	universalriempimento(4, 2, aTavoladagioco, iDadove, intLettera, intNumero, aCopiamappa);
	universalriempimento(3, 2, aTavoladagioco, iDadove, intLettera, intNumero, aCopiamappa);
	universalriempimento(2, 3, aTavoladagioco, iDadove, intLettera, intNumero, aCopiamappa);
	
	mostralamappa(aCopiamappa);
	riempiremappa(aCopiamappa);
	
	ilgioco(aTavoladagioco, intNumero, aCopiamappa, iContatoreAttacco, iPosizioneNumero, iPosizioneLettera, intIposizioneLettera);


	cout << "[!] Hai perso perchè hai finito i tentativi, misdispiace!";
	
	return 0;
}