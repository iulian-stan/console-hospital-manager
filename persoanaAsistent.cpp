#include <iostream>
#include <iomanip> 
using namespace std;
#include "persoana.h"
#include "globale.h"

Asistent::Asistent(Persoana *pers, char *sp) : 
Persoana(pers->getNume(), pers->getPrenume(), pers->getDataNastere(), pers->getAdresa(), pers->getTelefon()) {
	this->specialitate = new char[strlen(sp) + 1];
	strcpy(this->specialitate, sp);
}

Asistent::~Asistent() {
	delete []specialitate;
}

char *Asistent::getSpecialitate() {
	return this->specialitate;
}

void Asistent::afisareAngajat() {
	this->afisarePersoana();
	cout << " " << left << setfill(' ') << setw(9) << specialitate ;
}

void Asistent::afisare() {
	this->afisareAngajat();
	cout << endl ;
}

Persoana *setAsistent() {
	Persoana *pers = new Persoana();
	pers = setPersoana();
	char *sp;
	cout << "Introduceti specialitatea " ;
	sp = getString();
	return new Asistent(pers, sp);
}