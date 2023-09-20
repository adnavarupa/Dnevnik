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

	cout << "Unesite datum (DD-MM-GGGG):";
	getline(cin, datum);

	cout << "Mozete poceti sa pisanjem:";
	getline(cin, unos);

	dnevnikUnos noviUnos;
	noviUnos.datum = datum;
	noviUnos.unos = unos;

	dnevnik.push_back(noviUnos);

	cout << "Uspjesno spremljeno!";
}

//Funkcija za pretragu unosa u dnevnik po datumu
void pretragaPoDatumu(const vector<dnevnikUnos>& dnevnik) {
	string datum;
	cout << "Unesite datum (DD-MM-GGGG):";
	getline(cin, datum);

	cout << "Unosi za " << datum << ":" << endl;
	bool pronadjen = false;

	for (const dnevnikUnos& unos : dnevnik) {
		if (unos.datum == datum) {
			cout << unos.unos << endl;
			pronadjen = true;
		}
	}

	if (!pronadjen) {
		cout << "Nema unosa u dnevnik za taj datum.";
	}
}

int main(){
	vector<dnevnikUnos> dnevnik;
	
	cout << "                         ,..........   ..........," << endl;
	cout << "                     ,..,'          '.'          ',..," << endl;
	cout << "                    ,' ,'            :            ', '," << endl;
	cout << "                   ,' ,'             :             ', '," << endl;
	cout << "                  ,' ,'              :              ', '," << endl;
	cout << "                 ,' ,'............., : ,.............', ', " << endl;
	cout << "                ,'  '............   '.'   ............'  '," << endl;
	cout << "                 '''''''''''''''''';''';''''''''''''''''''" << endl;
	cout << "                                    '''" << endl;
	
	


	int izbor;
	do {
		cout << "Meni:\n1. Pisanje dnevnika\n2. Pretraga po datumu\n3. Kraj";
		cin >> izbor;

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