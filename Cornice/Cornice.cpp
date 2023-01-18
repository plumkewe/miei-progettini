#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//  


int main()
{
	setlocale(LC_ALL, "italian");
		
	int      bordi = 1;;
	char carattere = '-';
	string  parola ;
	
//  ===== settings:
	const bool    in_mezzo_char = true;
	const short int spazziatura = 3;
	
	cout << "Inserisci una parola: ";
	getline(cin, parola);
	
	cout << "Inserisci xBordi: ";
	cin  >> bordi; //  bords xNum
	
	cout << "Inserisci un carattere: ";
	cin  >> carattere;  // char
	
	bordi % 2 == 0 ? bordi + 1 : bordi = bordi; //  borders
	
	const int   altezza = bordi * 2 + 1; //  height
	const int lunghezza = parola.size() + bordi * 2; // lenght
	
	cout << endl << endl;
	
	for (int prime_i = 0; prime_i < altezza; prime_i++)
	{
		for (int second_i = 0, word_k = 0; second_i < lunghezza; second_i++)
		{
			if (second_i >= bordi && second_i < parola.size() + bordi && prime_i == altezza / 2 && word_k <= parola.size())
			{
				if (in_mezzo_char == true && isspace(parola[word_k]) == true)
				{
					cout << setw(spazziatura) << carattere;
				}
				else
				{
					cout << setw(spazziatura) << parola[word_k]; 
				}
				
				word_k++;
			}
			else
				cout << setw(spazziatura) << carattere;
		}
		
		cout << endl;
	}
	
	
	return 0;
}