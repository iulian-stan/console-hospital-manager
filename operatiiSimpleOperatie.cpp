#include <iostream>
using namespace std;
#include "globale.h"
#include "operatiiSimple.h"

OpAdaugaOperatie::OpAdaugaOperatie(char *nume, listaOperatie *lista, Lista *lista1, Lista *lista2, Lista *lista3) 
: Operatie (nume) {
	this->lista = lista;
	this->lista1 = lista1;
	this->lista2 = lista2;
	this->lista3 = lista3;
}

void OpAdaugaOperatie::execOperatie() {
	int i, j, nrD, nrA, nr; 
	Persoana **d, **a, *in;
	Element *aux1 = lista1->getElement(), *aux2 = lista2->getElement(), *aux3 = lista3->getElement() , *aux; 
	if (aux1 != 0 && aux2 != 0 && aux3 !=0) {
		do {
			cout << "Introduceti numarul de doctori (maxim "<< lista1->getNrEl() << ") " ; ;
			cin >> nrD ;
		} while (nrD < 1 || nrD > lista1->getNrEl());
		d = new Persoana*[nrD];
		lista1->afisare();
		for (i = 0 ; i < nrD ; i++) {
			do {
				cout << "Introduceti numarul doctorului " ;
				cin >> nr ;
			}while (nr < 1);
			aux = aux1;
			for (j = 1 ; j < nr && aux != 0 ; j++)
				aux = aux->getElem();
			if (aux == 0) {
				cout << "Numar eronat !\n" ;
				i--;
			}
			else
				d[i] = aux->getPers();
		}
		do {
			cout << "Introduceti numarul de asistenti (maxim "<< lista2->getNrEl() << ") " ;
			cin >> nrA ;
		} while (nrA < 1 || nrA > lista2->getNrEl());
		a = new Persoana*[nrA];
		lista2->afisare();
		for (i = 0 ; i < nrA ; i++) {
			do {
				cout << "Introduceti numarul asistentului " ;
				cin >> nr ;
			}while (nr < 1);
			aux = aux2;
			for (j = 1 ; j < nr && aux != 0 ; j++)
				aux = aux->getElem();
			if (aux == 0) {
				cout << "Numar eronat !\n" ;
				i--;
			}
			else
				a[i] = aux->getPers();
		}
		lista3->afisare();
		for (i = 0 ; i < 1 ; i++){
			do {
				cout << "Introduceti numarul pacientului " ;
				cin >> nr ;
			}while (nr < 1);
			for (j = 1 ; j < nr && aux3 != 0 ; j++)
				aux3 = aux3->getElem();
			if (aux3 == 0) {
				cout << "Numar eronat !\n" ;
				i--;
			}else 
				in = aux3->getPers();
		}
		lista->addOperatie(nrD,d,nrA,a,in);
	}else
		cout << "Date insuficiente !\n" ;
	pauza();
}

OpAfisareOpDupaDoctor::OpAfisareOpDupaDoctor(char *nume, listaOperatie *lista, Lista *lista1) : Operatie (nume) {
	this->lista = lista;
	this->lista1 = lista1;
}

void OpAfisareOpDupaDoctor::execOperatie() {
	int i, nr; 
	Persoana *d;
	Element *aux = lista1->getElement(); 
	if (lista != 0 && aux != 0){
		lista1->afisare();
		do {
			cout << "Introduceti numarul doctorului " ;
			cin >> nr ;
		}while (nr < 1);
		for (i = 1 ; i < nr && aux != 0 ; i++)
			aux = aux->getElem();
		if (aux == 0)
			cout << "Numar eronat !\n" ;
		else{
			d = aux->getPers();
			lista->afisareOperatieDoc(d);
		}
	}else
		cout << "Date insuficiente !\n" ;
	pauza();
}

OpAfisareOpDupaAsistent::OpAfisareOpDupaAsistent(char *nume, listaOperatie *lista, Lista *lista1) : Operatie (nume) {
	this->lista = lista;
	this->lista1 = lista1;
}

void OpAfisareOpDupaAsistent::execOperatie() {
	int i, nr; 
	Persoana *a;
	Element *aux = lista1->getElement(); 
	if (lista != 0 && aux != 0){
		lista1->afisare();
		do {
			cout << "Introduceti numarul asistentului " ;
			cin >> nr ;
		}while (nr < 1);
		for (i = 1 ; i < nr && aux != 0 ; i++)
			aux = aux->getElem();
		if (aux == 0)
			cout << "Numar eronat !\n" ;
		else{
			a = aux->getPers();
			lista->afisareOperatieAsist(a);
		}
	}else
		cout << "Date insuficiente !\n" ;
	pauza();
}

OpAfisareOpDupaPacient::OpAfisareOpDupaPacient(char *nume, listaOperatie *lista, Lista *lista1) : Operatie (nume) {
	this->lista = lista;
	this->lista1 = lista1;
}

void OpAfisareOpDupaPacient::execOperatie() {
	int i, nr; 
	Persoana *in;
	Element *aux = lista1->getElement(); 
	if (lista != 0 && aux != 0){
		lista1->afisare();
		do {
			cout << "Introduceti numarul asistentului " ;
			cin >> nr ;
		}while (nr < 1);
		for (i = 1 ; i < nr && aux != 0 ; i++)
			aux = aux->getElem();
		if (aux == 0)
			cout << "Numar eronat !\n" ;
		else{
			in = aux->getPers();
			lista->afisareOperatieIntern(in);
		}
	}else
		cout << "Date insuficiente !\n" ;
	pauza();
}

OpAfisareOperatii::OpAfisareOperatii(char *nume, listaOperatie *lista) : Operatie (nume) {
	this->lista = lista;
}

void OpAfisareOperatii::execOperatie() {
	lista->afisareOperatie();
	pauza();
}