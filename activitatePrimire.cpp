#include <iostream>
#include <iomanip>
using namespace std;
#include "activitate.h"

/****** Membri clasa Primire ******/

Primire::Primire(Persoana *doc, Persoana *pac, char *prescriptie, Primire *urm) {
	this->doc = doc;
	this->pac = pac;
	this->prescriptie = prescriptie;
	this->urm = urm;
}

Primire::~Primire() {
	delete prescriptie;
}

void Primire::afisarePrim() {
	cout << left << setfill(' ') << setw(9) << doc->getNume() << " "
		<< left << setfill(' ') << setw(9) << doc->getPrenume() << " "
		<< left << setfill(' ') << setw(9) << pac->getNume() << " "
		<< left << setfill(' ') << setw(9) << pac->getPrenume() << " "
		<< prescriptie << endl ;
}

/****** Membri clasa listaPrimire ******/

listaPrimire::listaPrimire() {
	this->prim = 0;
}

listaPrimire::listaPrimire(Primire *prim) {
	this->prim = prim;
}

listaPrimire::~listaPrimire() {
	Primire *del;
	while (prim) {
		del = prim;
		prim = prim->urm;
		delete del;
	}
	prim = 0;
}

Persoana *listaPrimire::getDoc() {
	return prim->doc;
}

Persoana *listaPrimire::getPac() {
	return prim->pac;
}

char *listaPrimire::getPrescriptie() {
	return prim->prescriptie;
}

Primire *listaPrimire::getUrm() {
	return prim->urm;
}

void listaPrimire::addPrimire (Persoana *d, Persoana *p, char *prescrip) {
	prim = new Primire(d,p,prescrip,prim);
}

void listaPrimire::afisarePrimire(){
	int i = 0;
	Primire *cap = prim;
	if (cap == 0)
		cout << "Lista primirilor este vida !\n" ;
	else{
		cout << "  " << left << setfill(' ') << setw(20) << "Doctor"
			<< left << setfill(' ') << setw(20) << "Pacient" 
			<< "Prescriptie" << endl;
		while (cap) {
			i++;
			cout << i << ".";
			cap->afisarePrim();
			cap = cap->urm;
		}
	}
}

void listaPrimire::afisarePrimireDoc(Persoana *d){
	int i = 0;
	Primire *cap = prim;
	if (cap == 0)
		cout << "Lista primirilor este vida !\n" ;
	else{
		cout << "  " << left << setfill(' ') << setw(20) << "Doctor"
			<< left << setfill(' ') << setw(20) << "Pacient"
			<< "Prescriptie" << endl;
		while (cap) {
			if (cap->doc == d) {
				i++;
				cout << i << ".";
				cap->afisarePrim();
			}
			cap = cap->urm;
		}
	}
}

void listaPrimire::afisarePrimirePac(Persoana *p){
	int i = 0;
	Primire *cap = prim;
	if (cap == 0)
		cout << "Lista primirilor este vida\n" ;
	else{
		cout << "  " << left << setfill(' ') << setw(20) << "Doctor"
			<< left << setfill(' ') << setw(20) << "Pacient" 
			<< "Prescriptie" << endl;
		while (cap) {
			if (cap->pac == p) {
				i++;
				cout << i << ".";
				cap->afisarePrim();
			}
			cap = cap->urm;
		}
	}
}
