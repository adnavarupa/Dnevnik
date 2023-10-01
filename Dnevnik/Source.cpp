#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Funkcija za autentifikaciju korisnka
/*bool autentifikacijaKorisnika() {
	string ime;
	string password;

}*/

//Struct za unos u dnevnk
struct dnevnikUnos {
	string datum;
	string unos;
};

//Funkcija za pisanje dnevnika
void pisanjeDnevnika(vector<dnevnikUnos>& dnevnik) {
	string unos;
	string datum;
    cout << endl;
	cout << "Unesite datum (DD-MM-GGGG):";
	getline(cin, datum);
	
	cout << "Mozete poceti sa pisanjem:";
	getline(cin, unos);

	dnevnikUnos noviUnos;
	noviUnos.datum = datum;
	noviUnos.unos = unos;

	dnevnik.push_back(noviUnos);

	cout << "\nUspjesno spremljeno!\n\n";
}

//Funkcija za pretragu unosa u dnevnik po datumu
void pretragaPoDatumu(const vector<dnevnikUnos>& dnevnik) {
	string datum;
	cout << endl;
	cout << "Unesite datum (DD-MM-GGGG):";
	getline(cin, datum);
	int brojac = 1;

	cout << "Unosi za " << datum << ":" << endl;
	bool pronadjen = false;

	for (const dnevnikUnos& unos : dnevnik) {
		cout << endl;
		if (unos.datum == datum) {
			cout << "Unos " << brojac << ": \"" << unos.unos << "\"" << endl;
			pronadjen = true;
			brojac + 1;
		}
	}

	if (!pronadjen) {
		cout << "Nema unosa u dnevnik za taj datum.";
	}
	cout << endl;
}

int main(){
	
	cout << "                         ,..........   ..........," << endl;
	cout << "                     ,..,'          '.'          ',..," << endl;
	cout << "                    ,' ,'            :            ', '," << endl;
	cout << "                   ,' ,'             :             ', '," << endl;
	cout << "                  ,' ,'              :              ', '," << endl;
	cout << "                 ,' ,'............., : ,.............', ', " << endl;
	cout << "                ,'  '............   '.'   ............'  '," << endl;
	cout << "                 '''''''''''''''''';''';''''''''''''''''''" << endl;
	cout << "                                    '''" << endl;
	
	vector<dnevnikUnos> dnevnik;
	int izbor;
	string password;
	string trazeniPassword;
	
	//Korisnik mora napraviti password
	cout << "Kreirajte password:";
	getline(cin, password);
	cout << endl;

	do {

		//Korisnik mora unijeti tacan password da bi pristupio opcijama
		do {
			cout << "Unesite password:";
			getline(cin, trazeniPassword);
		} while (trazeniPassword != password); 

		cout << endl;
		cout << "Meni:\n1. Pisanje dnevnika\n2. Pretraga po datumu\n3. Kraj\n\n";
		cout << "Unesite izbor:";
		cin >> izbor;
		cin.ignore();
		switch (izbor) {
		case 1:
			pisanjeDnevnika(dnevnik);
			break;

		case 2:
			pretragaPoDatumu(dnevnik);
			break;

		case 3:
			cout << "Dovidjenja!";
			break;
		}
	} while (izbor != 3);

}