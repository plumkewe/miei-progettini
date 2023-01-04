#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//  linear search vs binary search


int main() {
	setlocale(LC_ALL, "italian");
	
	int x;
	
	cout << "Inserisci la lunghezza del tuo array: ";
	cin >> x;
	
	double binary_search = log2(x);
	int linear_search = x * 1;
	double saving_time = linear_search - binary_search;
	
	
	cout << setprecision(2) << fixed <<
			"\n\vCon Binary Search al massimo ti serviranno: " << binary_search << "ms" <<
			"\n\tCon Binary Search al massimo ti serviranno: " << linear_search << "ms" <<
			"\n\tCon Binary search risparmi: " << saving_time << "ms!";

	
	return 0;
}