#include <iostream>
using namespace std;
#include "persoana.h"
#include "globale.h"

Internat::Internat(Persoana *pers, char *diag, int sala) : Monitorizat(pers,diag) {
	this->sala = sala;
}

Internat::Internat(Monitorizat *mon, int sala) : Monitorizat(mon,mon->getDiagnostic()) {
	this->sala = sala;
}

Internat::~Internat() {
}

int Internat::getSala() {
	return this->sala;
}

void Internat::afisare() {
	this->afisarePacient();
	cout << " " << sala << endl ;
}

Persoana *setInternat() {
	Persoana *pers = new Persoana();
	pers = setPersoana();
	char *diag;
	cout << "Introduceti diagnoza " ;
	diag = getString();
	int s;
	do {
		cout << "Introduceti numarul salii (intreg pozitiv) " ;
		cin >> s;
	} while ( s < 1 );
	return new Internat(pers,diag,s);
}