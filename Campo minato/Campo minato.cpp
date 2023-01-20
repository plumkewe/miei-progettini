#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//  


void InizioDelGioco (int back_o_front[][11], int che_cosa)
{
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
			back_o_front[i][j] = che_cosa;
	}
}

void InizioDelGioco (string back_o_front[][11], string che_cosa)
{
	for (int i = 1; i < 11; i++)
		{
			for (int j = 1; j < 11; j++)
				back_o_front[i][j] = che_cosa;
		}
}

template <typename T>

void MostrareInterfacciaUtente (T back_o_front[][11])
{
	cout << endl;
	
	for (int altezza = 1; altezza < 11; altezza++)
	{
		for (int riga = 1; riga < 11; riga++)
			cout << setw(3) << back_o_front[altezza][riga];
		
		cout << endl;
	}
	
}
void InserireUnaBomba (string interfaccia[][11], int funzionamento_back[][11])
{
	int posizione_altezza = 0;
	int    posizione_riga = 0;
	
	cout << "Inserisci altezza: ";
	cin  >> posizione_altezza;
	
	cout << "Inserisci la riga: ";
	cin  >> posizione_riga;
	
	while (funzionamento_back[posizione_altezza][posizione_riga] >= 10 || posizione_riga > 10 || posizione_altezza > 10 || posizione_riga < 1 || posizione_altezza < 1)
	{
		cout << "ERRORE RIPROVA\n";
		
		cout << "Inserisci altezza: ";
		cin  >> posizione_altezza;
		
		cout << "Inserisci la riga: ";
		cin  >> posizione_riga;
	}
	
	funzionamento_back[posizione_altezza][posizione_riga] = 10;
	interfaccia[posizione_altezza][posizione_riga] = "💣";
	

//  lo volevo fare con un loop ma non andava, quindi per ora va bene così

//  sopra
	funzionamento_back[posizione_altezza - 1][posizione_riga - 1] ++;
	funzionamento_back[posizione_altezza - 1][posizione_riga    ] ++;
	funzionamento_back[posizione_altezza - 1][posizione_riga + 1] ++;

//  stesso livello
	funzionamento_back[posizione_altezza    ][posizione_riga - 1] ++;
	funzionamento_back[posizione_altezza    ][posizione_riga + 1] ++;

//  sotto
	funzionamento_back[posizione_altezza + 1][posizione_riga + 1] ++;
	funzionamento_back[posizione_altezza + 1][posizione_riga    ] ++;
	funzionamento_back[posizione_altezza + 1][posizione_riga - 1] ++;
}

//void MostraCaselleVuote (string interfaccia[][11], int funzionamento_back[][11], int posizione_altezza, int posizione_riga)
//{
//	for (int pos_alt = posizione_altezza; pos_alt < 11; pos_alt++)
//	{
//		for (int in_dir_avanti = posizione_riga; in_dir_avanti < 11; in_dir_avanti++)
//		{
//			if (funzionamento_back[pos_alt][in_dir_avanti] > 1)
//				interfaccia[pos_alt][in_dir_avanti] = funzionamento_back[pos_alt][in_dir_avanti];
//				
//			else
//				if (funzionamento_back[pos_alt][in_dir_avanti] > 10)
//					break;
//				else
//				{
//					funzionamento_back[pos_alt][in_dir_avanti] = 9;
//					interfaccia[pos_alt][in_dir_avanti] = "j";
//				}
//		
//		}
//		for (int in_dir_dietro = posizione_riga; in_dir_dietro < 11; in_dir_dietro--)
//		{
//			if (funzionamento_back[pos_alt][in_dir_dietro] > 1)
//				interfaccia[pos_alt][in_dir_dietro] = funzionamento_back[pos_alt][in_dir_dietro];
//			
//			else
//				if (funzionamento_back[pos_alt][in_dir_dietro] > 10)
//				break;
//			else
//			{
//				funzionamento_back[pos_alt][in_dir_dietro] = 9;
//				interfaccia[pos_alt][in_dir_dietro] = "j";
//			}
//		}
//	}
//}


int main()
{
	setlocale(LC_ALL, "italian");
	
	string    interfaccia[11][11];
	int retro_interfaccia[11][11];
	
	InizioDelGioco (interfaccia, "⬜️");
	InizioDelGioco (retro_interfaccia, 0);
	
	
	for (int i = 0; i < 10; i++)
	{
		InserireUnaBomba(interfaccia, retro_interfaccia);
		MostrareInterfacciaUtente(interfaccia);
		MostrareInterfacciaUtente(retro_interfaccia);
	}
	
	
	MostrareInterfacciaUtente(interfaccia);
	MostrareInterfacciaUtente(retro_interfaccia);
	
	
//	int posizione_altezza = 0;
//	int    posizione_riga = 0;
//	
//	cout << "Inserisci altezza: ";
//	cin  >> posizione_altezza;
//	
//	cout << "Inserisci la riga: ";
//	cin  >> posizione_riga;
//	
//	MostraCaselleVuote(interfaccia, retro_interfaccia, posizione_altezza, posizione_riga);
	
//	int contatore_trovate = 0;
//	
//	while (contatore_trovate != 1)
//	{
//		
//		
//		
//		
//	}
//	
	return 0;
}