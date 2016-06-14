#include <iostream>
using namespace std;
#include "activitate.h"

/****** Membri clasa Operatii ******/

Operatii::Operatii(int nrD, Persoana **docs, int nrA, Persoana **asists, Persoana *intern, Operatii *urm) {
	this->docs = docs;
	this->asists = asists;
	this->intern = intern;
	this->nrDoctori = nrD;
	this->nrAsistenti = nrA;
	this->urm = urm;
}

Operatii::~Operatii() {
	delete docs;
	delete asists;
}

void Operatii::afisareOp() {
	int i;
	cout << "Doctori : " ;
	for (i = 0 ; i < nrDoctori ; i++)
		cout << docs[i]->getNume() << " "
		<< docs[i]->getPrenume() << " ; " ;
	cout << endl ;
	cout << "  Asistenti : " ;
	for (i = 0 ; i < nrAsistenti ; i++)
		cout << asists[i]->getNume() << " "
		<< asists[i]->getPrenume() << " ; " ;
	cout << endl ;
	cout << "  Pacientul : " << intern->getNume() << " "
		<< intern->getPrenume() << " . " ;
	cout << endl ;
}

/****** Membri clasa listaOperatie ******/

listaOperatie::listaOperatie() {
	op = 0;
}

listaOperatie::listaOperatie(Operatii *op) {
	this->op = op;
}

listaOperatie::~listaOperatie() {
	if (op) {
		delete op->docs;
		delete op->asists;
	}
	op = 0;
}

Persoana **listaOperatie::getDocs() {
	return op->docs;
}

Persoana **listaOperatie::getAsists() {
	return op->asists;
}

Persoana *listaOperatie::getIntern() {
	return op->intern;
}

int listaOperatie::getNrDoctori() {
	return op->nrDoctori;
}

int listaOperatie::getNrAsistenti() {
	return op->nrAsistenti;
}

void listaOperatie::addOperatie (int nrD, Persoana **d, int nrA, Persoana **a, Persoana *i) {
	op = new Operatii(nrD,d,nrA,a,i,op);
}

void listaOperatie::afisareOperatie() {
	int i = 0;
	Operatii *cap = op;
	if (cap == 0)
		cout << "Lista operatiilor este vida !\n" ;
	else{
		while (cap) {
			i++;
			cout << i << ".";
			cap->afisareOp();
			cap = cap->urm;
		}
	}
}

void listaOperatie::afisareOperatieDoc(Persoana *d) {
	int i = 0;
	Operatii *cap = op;
	if (cap == 0)
		cout << "Lista operatiilor este vida !\n" ;
	else{
		while (cap) {
			for (int j = 0 ; j < cap->nrDoctori ; j++) {
				if (cap->docs[j] == d) {
					i++;
					cout << i << ".";
					cap->afisareOp();
				}
			}
			cap = cap->urm;
		}
	}
}

void listaOperatie::afisareOperatieAsist(Persoana *a) {
	int i = 0;
	Operatii *cap = op;
	if (cap == 0)
		cout << "Lista operatiilor este vida !\n" ;
	else{
		while (cap) {
			for (int j = 0 ; j < cap->nrAsistenti ; j++) {
				if (cap->asists[j] == a) {
					i++;
					cout << i << ".";
					cap->afisareOp();
				}
			}
			cap = cap->urm;
		}
	}
}

void listaOperatie::afisareOperatieIntern(Persoana *p) {
	int i = 0;
	Operatii *cap = op;
	if (cap == 0)
		cout << "Lista operatiilor este vida !\n" ;
	else{
		while (cap) {
			if (cap->intern == p) {
				i++;
				cout << i << ".";
				cap->afisareOp();
			}
			cap = cap->urm;
		}
	}
}