#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Pravljenje korisnickog naloga
struct Korisnik {
    string user;
    string password;
    bool prijavljen;

    Korisnik(const string& user, const string& password)
        : user(user), password(password), prijavljen(false) {}
};

vector<Korisnik> korisnici;

//Funkcija za registraciju korisnika
void registracijaKorisnika() {
	string user, password;
	cout << "Unesite korisnicko ime: ";
	cin >> user;
	for (const Korisnik& korisnik : korisnici) { //Provjerava da li korisnicko ime vec postoji
		if (korisnik.user == user) {
			cout << "Korisnicko ime vec postoji. Izaberite drugo." << endl;
			return;
		}
	}
	cout << "Unesite lozinku: ";
	cin >> password;
	korisnici.push_back({user,password});
	cout << "Registracija uspjesna!" << endl;
}

//Funkcija za prijavu korisnika
Korisnik* prijavaKorisnika() {
	string user, password;
	cout << "Unesite korisnicko ime: ";
	cin >> user;
	cout << "Unesite lozinku: ";
	cin >> password;
	for (Korisnik& korisnik : korisnici) {
		if (korisnik.user == user && korisnik.password == password) {
			korisnik.prijavljen = true;
			return &korisnik;
		}
	}
	cout << "Pogresno korisnicko ime ili lozinka!" << endl;
	return nullptr;
}

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
			registracijaKorisnika();
			break;
			case 2:
			Korisnik* trenutniKorisnik = prijavaKorisnika();
			if (trenutniKorisnik) {
				cout << "Prijavljeni ste kao " << trenutniKorisnik -> user << "." << endl;
			}
			break;
		case 3:
			pisanjeDnevnika(dnevnik);
			break;

		case 4:
			pretragaPoDatumu(dnevnik);
			break;

		case 5:
			cout << "Dovidjenja!";
			break;
		}
	} while (izbor != 3);

}