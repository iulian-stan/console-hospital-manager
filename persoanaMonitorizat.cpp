#include <iostream>
#include <iomanip> 
using namespace std;
#include "persoana.h"
#include "globale.h"

Monitorizat::Monitorizat(Persoana *pers, char *diag) : 
Persoana(pers->getNume(), pers->getPrenume(), pers->getDataNastere(), pers->getAdresa(), pers->getTelefon()) {
	this->diagnostic = new char[strlen(diag) + 1];
	strcpy(this->diagnostic, diag);
}

Monitorizat::~Monitorizat() {
	delete[] diagnostic;
}

char *Monitorizat::getDiagnostic() {
	return this->diagnostic;
}

void Monitorizat::afisarePacient() {
	this->afisarePersoana();
	cout << " " << left << setfill(' ') << setw(9) << diagnostic ;
}

void Monitorizat::afisare() {
	this->afisarePacient();
	cout << endl ;
}

Persoana *setMonitorizat() {
	Persoana *pers = new Persoana();
	pers = setPersoana();
	char *diag;
	cout << "Introduceti diagnoza " ;
	diag = getString();
	return new Monitorizat(pers, diag);
}