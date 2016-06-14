#include <iostream>
using namespace std;
#include "persoana.h"
#include "globale.h"

Doctor::Doctor(Persoana *pers, char *sp, int cab) : Asistent(pers,sp) {
	this->cabinet = cab;
}

Doctor::Doctor(Asistent *asist, int cab) : Asistent (asist,asist->getSpecialitate()) {
	this->cabinet = cab ;
}

Doctor::~Doctor() {
}

int Doctor::getCabinet() {
	return this->cabinet;
}

void Doctor::afisare() {
	this->afisareAngajat();
	cout << " " << cabinet << endl ;
}

Persoana *setDoctor() {
	Persoana *pers = new Persoana();
	pers = setPersoana();
	char *sp;
	cout << "Introduceti specialitatea " ;
	sp = getString();
	int cab;
	do {
		cout << "Introduceti numarul cabinetului (intreg pozitiv) " ;
		cin >> cab;
	} while ( cab < 1 );
	return new Doctor(pers,sp,cab);
}