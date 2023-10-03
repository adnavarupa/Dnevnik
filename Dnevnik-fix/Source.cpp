//
// Created by hp on 10/2/2023.
//
#include <iostream>
#include <fstream>
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

//Struct za unos u dnevnk
struct dnevnikUnos {
    string username;
    string datum;
    string unos;
};

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

//Funkcija za spremanje korisnika u datoteku
void spremanjeKorisnikaUdatoteku(const vector<Korisnik>& korisnici) {
    ofstream datoteka("korisnici.txt");
    if (!datoteka.is_open()) {
        cout << "Nemoguce otvoriti datoteku za cuvanje korisnika!" << endl;
        return;
    }
    for (const Korisnik& korisnik : korisnici) {
        datoteka << korisnik.user << " " << korisnik.password << endl;
    }
    datoteka.close();
}

//Funkcija za ucitavanje korisnika iz datoteke
void ucitajKorisnika(vector<Korisnik>& korisnici) {
    ifstream datoteka("korisnici.txt");
    if (!datoteka.is_open()) {
        cout << "Nemoguce otvoriti datoteku za citanje korisnika!" << endl;
        return;
    }
    korisnici.clear(); //Obrisati postojecu listu korisnika
    string user, password;
    while (datoteka >> user >> password) {
        korisnici.push_back({user,password});
    }
    datoteka.close();
}

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
            brojac++;
        }
    }

    if (!pronadjen) {
        cout << "Nema unosa u dnevnik za taj datum.";
    }
    cout << endl;
}

//Funkcija za ispisivanje svih unosa u dnevnik za trenutnog korisnika
void ispisUnosa(const vector<dnevnikUnos>& dnevnik, const string& trenutniKorisnik) {
    cout << endl;
    for (const dnevnikUnos& unos : dnevnik) {
        if (unos.username == trenutniKorisnik) {
            cout << "Unos za " << unos.datum << ": \"" << unos.unos << "\"" << endl;
        }
    }
    cout << endl;
}

//Funkcija za spremanje dnevnika u datoteku
void spremanjeUdatoteku(const vector<dnevnikUnos>& dnevnik) {
    ofstream Dnevnik("dnevnik.txt");
    if (!Dnevnik.is_open()) {
        cout << "Nemoguce otvoriti datoteku!" << endl;
        return;
    }
    for (const dnevnikUnos& unos : dnevnik) {
        Dnevnik << unos.username << endl;
        Dnevnik << unos.datum << endl;
        Dnevnik << unos.unos << endl;
    }
    Dnevnik.close();
    cout << "Sadrzaj je spremljen u datoteku 'dnevnik.txt'." << endl;
}

//Funkcija za ispis sadrzaja iz datoteke
void ispisSadrzajaDatoteke() {
    ifstream datoteka("dnevnik.txt");
    if (!datoteka.is_open()) {
        cout << "Nemoguce otvoriti datoteku za citanje sadrzaja." << endl;
        return;
    }
    cout << "Sadrzaj datoteke 'dnevnik.txt':" << endl;
    string linija;
    while (getline(datoteka, linija)) {
        cout << linija << endl;
    }
    datoteka.close();
}

// Funkcija za brisanje unosa
void obrisiUnos(vector<dnevnikUnos>& dnevnik) {
    string datum;
    cout << "Unesite datum unosa koji zelite obrisati (DD-MM-GGGG): ";
    getline(cin, datum);

    bool obrisan = false;

    for (int i = 0; i < dnevnik.size(); ) {
        if (dnevnik[i].datum == datum) {
            dnevnik.erase(dnevnik.begin() + i);
            obrisan = true;
        }
        else {
            ++i;
        }
    }

    if (obrisan) {
        cout << "Unos(i) uspjesno obrisan(i)!" << endl;
    }
    else {
        cout << "Nema unosa za taj datum." << endl;
    }
}

//Funkcija za uredjivanje sadrzaja u dnevniku
void urediUnosUdnevnik() {
    string nazivDatoteke = "dnevnik.txt";
    ifstream datoteka(nazivDatoteke);
    if (!datoteka.is_open()) {
        cout << "Nemoguce otvoriti datoteku za uredjivanje sadrzaja." << endl;
        return;
    }

    vector<string> sadrzajDatoteke;
    string linija;

    // Ucitaj sadrzaj datoteke u vektor
    while (getline(datoteka, linija)) {
        sadrzajDatoteke.push_back(linija);
    }

    datoteka.close();

    // Ispis sadrzaja datoteke
    cout << "Trenutni sadrzaj datoteke '" << nazivDatoteke << "':" << endl;
    for (int i = 0; i < sadrzajDatoteke.size(); i++) {
        cout << i + 1 << ". " << sadrzajDatoteke[i] << endl;
    }

    // Unesite redni broj unosa za uredjivanje
    int brojUnosa;
    cout << "Unesite redni broj unosa koji zelite urediti (0 za izlaz): ";
    cin >> brojUnosa;
    cin.ignore();

    if (brojUnosa == 0 || brojUnosa > sadrzajDatoteke.size()) {
        cout << "Nevazeci broj unosa." << endl;
        return;
    }

    // Unesite novi sadrzaj
    cout << "Unesite novi sadrzaj za unos " << brojUnosa << " (pritisnite Enter za zavrsetak unosa):" << endl;
    string noviSadrzaj;
    getline(cin, noviSadrzaj);

    // Ažurirajte sadržaj u vektoru
    sadrzajDatoteke[brojUnosa - 1] = noviSadrzaj;

    // Otvorite datoteku za pisanje i ažurirajte sadržaj
    ofstream izlaznaDatoteka(nazivDatoteke);
    if (!izlaznaDatoteka.is_open()) {
        cout << "Nemoguce otvoriti datoteku za spremanje sadrzaja." << endl;
        return;
    }

    for (const string& novaLinija : sadrzajDatoteke) {
        izlaznaDatoteka << novaLinija << endl;
    }

    izlaznaDatoteka.close();
    cout << "Sadrzaj datoteke '" << nazivDatoteke << "' je uspjesno azuriran." << endl;
}

int main() {

    ucitajKorisnika(korisnici); //Ucita korisnike prije pocetka programa

    cout << "                         ,..........   ..........," << endl;
    cout << "                     ,..,'          '.'          ',..," << endl;
    cout << "                    ,' ,'            :            ', '," << endl;
    cout << "                   ,' ,'             :             ', '," << endl;
    cout << "                  ,' ,'              :              ', '," << endl;
    cout << "                 ,' ,'............., : ,.............', ', " << endl;
    cout << "                ,'  '............   '.'   ............'  '," << endl;
    cout << "                 '''''''''''''''''';''';''''''''''''''''''" << endl;
    cout << "                                    '''" << endl;

    vector <dnevnikUnos> dnevnik;

    string password;
    string trazeniPassword;
    Korisnik *trenutniKorisnik = nullptr;
    int izborA;
    int izborB;
    cout << endl;
    do {
        cout << "Dobrodosli u program Dnevnik!\n\n1. Registracija\n2. Prijava\n\nIzbor:";
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

    do {
        cout << "Meni:\n1. Pisanje dnevnika\n2. Pretraga po datumu\n3. Ispis svih unosa\n4."
                " Spremanje u datoteku\n5. Ispis sadrzaja datoteka\n6. Brisanje unosa\n7. Promjena profila\n"
                "8. Uredjivanje sadrzaja\n 9. Kraj\n\n";
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
                ispisUnosa(dnevnik, trenutniKorisnik->user);
                break;

            case 4:
                spremanjeUdatoteku(dnevnik);
                break;

            case 5:
                ispisSadrzajaDatoteke();
                break;

            case 6:
                obrisiUnos(dnevnik);
                break;

            case 7:
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
                break;

            case 8:
                urediUnosUdnevnik();
                break;

            case 9:
                spremanjeKorisnikaUdatoteku(korisnici); //Sprema korisnike prije izlaska iz programa
                cout << "Dovidjenja!";
                break;
        }
    } while (izborB != 9);

}