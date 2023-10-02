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
	korisnici.push_back({ user,password });
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
	string username;
	string datum;
	string unos;
};

//Funkcija za pisanje dnevnika
void pisanjeDnevnika(vector<dnevnikUnos>& dnevnik, const string& username) {
	string unos;
	string datum;
	cout << endl;
	cout << "Unesite datum (DD-MM-GGGG):";
	getline(cin, datum);

	cout << "Mozete poceti sa pisanjem:";
	getline(cin, unos);

	dnevnikUnos noviUnos;
	noviUnos.username = username;
	noviUnos.datum = datum;
	noviUnos.unos = unos;

	dnevnik.push_back(noviUnos);

	cout << "\nUspjesno spremljeno!\n\n";
}

//Funkcija za pretragu unosa u dnevnik po datumu
void pretragaPoDatumu(const vector<dnevnikUnos>& dnevnik, const string& trenutniKorisnik) {
	string datum;
	cout << endl;
	cout << "Unesite datum (DD-MM-GGGG):";
	getline(cin, datum);
	int brojac = 1;

	cout << "Unosi za " << datum << ":" << endl;
	bool pronadjen = false;

	for (const dnevnikUnos& unos : dnevnik) {
		cout << endl;
		if (unos.datum == datum && unos.username == trenutniKorisnik) {
			cout << "Unos " << brojac << ": \"" << unos.unos << "\"" << endl;
			pronadjen = true;
			brojac ++;
		}
	}

	if (!pronadjen) {
		cout << "Nema unosa u dnevnik za taj datum.";
	}
	cout << endl;
}

int main() {

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
	
	string password;
	string trazeniPassword;
	Korisnik* trenutniKorisnik = nullptr;
	int izborA;
	int izborB;
	do {
		cout << endl;
		do {
		cout << "1. Registracija\n2. Prijava\n\nIzbor:";
		cin >> izborA;
		cin.ignore();
		switch (izborA) {
		case 1:
			cout << endl;
			registracijaKorisnika();
			cout << endl;
			break;
		case 2:
			cout << endl;
			trenutniKorisnik = prijavaKorisnika();
			if (trenutniKorisnik) {
				cout << "Prijavljeni ste kao " << trenutniKorisnik->user << "." << endl;
			}
			cout << endl;
			break;
		}
		} while (izborA != 2);
		

		cout << "Meni:\n1. Pisanje dnevnika\n2. Pretraga po datumu\n3. Kraj\n\n";
		cout << "Unesite izbor:";
		cin >> izborB;
		
		cin.ignore();
		switch (izborB) {
		case 1:
			pisanjeDnevnika(dnevnik, trenutniKorisnik->user);
			break;

		case 2:
			pretragaPoDatumu(dnevnik, trenutniKorisnik->user);
			break;

		case 3:
			cout << "Dovidjenja!";
			break;
		}
	} while (izborB != 3);

}
