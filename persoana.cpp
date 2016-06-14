#include <iostream>
#include <iomanip>
using namespace std;
#include "persoana.h"
#include "globale.h"

static const int luni[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

Data::Data(int an, int luna, int zi){
	this->an = an;
	this->luna = luna;
	this->zi = zi;
}

int Data::getAn() {
	return an;
}

int Data::getLuna() {
	return luna;
}

int Data::getZi() {
	return zi;
}

Adresa::Adresa(char *strada, int numar, char bloc, int apartament) {
	this->strada = strada;
	this->numar = numar;
	this->bloc = bloc;
	this->apartament = apartament;
}

char *Adresa::getStrada() {
	return strada;
}

int Adresa::getNumar() {
	return numar;
}

char Adresa::getBloc() {
	return bloc;
}

int Adresa::getApartament() {
	return apartament;
}

Persoana::Persoana(char *nume, char *prenume, Data *dataNastere, Adresa *adresa, char *telefon) {
	this->nume = new char[strlen(nume) + 1];
	strcpy(this->nume, nume);
	this->prenume = new char[strlen(prenume) + 1];
	strcpy(this->prenume, prenume);
	this->adresa = new Adresa(*adresa);
	this->dataNastere = new Data(*dataNastere);
	this->telefon = new char[strlen(telefon) + 1];
	strcpy(this->telefon, telefon);
}

Persoana::~Persoana() {
	delete []nume;
	delete []prenume;
	delete dataNastere;
	delete adresa;
	delete []telefon;
}

char *Persoana::getNume(){
	return nume;
}

char *Persoana::getPrenume() {
	return prenume;
}

Adresa *Persoana::getAdresa() {
	return adresa;
}

char *Persoana::getTelefon() {
	return telefon;
}

Data *Persoana::getDataNastere() {
	return dataNastere;
}

void Persoana::afisarePersoana() {
	cout << left << setfill(' ') << setw(9) << nume << " " 
		<< left << setfill(' ') << setw(9) << prenume << " " 
		<< setfill('0') << setw(2) << dataNastere->getZi() << "."
		<< setfill('0') << setw(2) << dataNastere->getLuna() << "."
		<< dataNastere->getAn() << " "
		<< left << setfill(' ') << setw(9) << adresa->getStrada() << " "
		<< setfill(' ') << setw(3) << adresa->getNumar() << "/"
		<< setfill(' ') << setw(2) << adresa->getBloc() << "/"
		<< setfill(' ') << setw(3) << adresa->getApartament() << " "
		<< left << setfill(' ') << setw(9) << telefon ;
}

void Persoana::afisare() {
	afisarePersoana();
	cout << endl ;
}

Persoana *setPersoana() {
	int a, l, z, nr, ap; 
	char *n, *p, *str, *tel, bl;
	cout << "Introduceti numele " ;
	n = getString();
	cout << "Introduceti prenumele " ;
	p = getString();
	do {
		cout << "Introduceti anul nasterii (1900-2010) " ;
		cin >> a;
	} while ( a < 1900 || a > 2010 );
	do {
		cout << "Introduceti luna nasterii (1-12) " ;
		cin >> l;
	} while ( l < 1 || l >12 );
	do {
		cout << "Introduceti ziua nasterii (in dependenta de luna)  " ;
		cin >> z;
	} while ( z < 1 || z > luni[l] + ( l == 2 && a % 4 == 0 && a % 100 != 0 )) ;
	Data *d = new Data(a,l,z);
	cout << "Introduceti strada " ;
	str = getString();
	do {
		cout << "Introduceti numarul casei (intreg pozitiv) " ;
		cin >> nr;
	} while ( nr < 1 );
	do {
		cout << "Introduceti blocul (un caracter) " ;
		cin >> bl;
	} while ( bl < 1 );
	do {
		cout << "Introduceti numarul apartamentului (intreg pozitiv) " ;
		cin >> ap;
	} while ( ap < 1 ); 
	Adresa *ad = new Adresa(str,nr,bl,ap);
	cout << "Introduceti telefonul " ;
	tel = getString();
	return new Persoana(n,p,d,ad,tel);
}