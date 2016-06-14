#include <iostream>
using namespace std;
#include "globale.h"
#include "operatiiSimple.h"

/****** Membri clasa OpAdaugaPrimire ******/

OpAdaugaPrimire::OpAdaugaPrimire(char *nume, listaPrimire *&lista, Lista *lista1, Lista *lista2) : Operatie (nume) {
	this->lista = lista;
	this->lista1 = lista1;
	this->lista2 = lista2;
}

void OpAdaugaPrimire::execOperatie() {
	int i, nr; 
	Persoana *d, *p;
	char *pres;
	Element *aux1 = lista1->getElement(), *aux2 = lista2->getElement(); 
	if (aux1 != 0 && aux2 != 0) {
		lista1->afisare();
		do {
			cout << "Introduceti numarul doctorului " ;
			cin >> nr ;
		}while (nr < 1);
		for (i = 1 ; i < nr && aux1 != 0 ; i++)
			aux1 = aux1->getElem();
		if (aux1 == 0)
			cout << "Numar eronat !\n" ;
		else{
			d = aux1->getPers();
			lista2->afisare();
			do {
				cout << "Introduceti numarul pacientului " ;
				cin >> nr ;
			}while (nr < 1);
			for (i = 1 ; i < nr && aux2 != 0 ; i++)
				aux2 = aux2->getElem();
			if (aux2 == 0)
				cout << "Numar eronat !\n" ;
			else {
				p = aux2->getPers();
				cout << "Introduceti prescriptia " ;
				pres = getString();
				lista->addPrimire(d,p,pres);
			}
		}
	}else
		cout << "Date insuficiente !\n" ;
	pauza();
}

/****** Membri clasa OpafisareDupaDoctor ******/

OpAfisareDupaDoctor::OpAfisareDupaDoctor(char *nume, listaPrimire *lista1, Lista *lista2) : Operatie (nume) {
	this->lista1 = lista1;
	this->lista2 = lista2;
}

void OpAfisareDupaDoctor::execOperatie() {
	int i, nr; 
	Persoana *d;
	Element *aux = lista2->getElement(); 
	if (lista1 != 0 && aux != 0){
		lista2->afisare();
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
			lista1->afisarePrimireDoc(d);
		}
	}else
		cout << "Date insuficiente !\n" ;
	pauza();
}

/****** Membri clasa OpAfisareDupaPacient ******/

OpAfisareDupaPacient::OpAfisareDupaPacient(char *nume, listaPrimire *lista1, Lista *lista2) : Operatie (nume) {
	this->lista1 = lista1;
	this->lista2 = lista2;
}

void OpAfisareDupaPacient::execOperatie() {
	int i, nr; 
	Persoana *p;
	Element *aux = lista2->getElement(); 
	if (lista1 != 0 && aux != 0){
		lista2->afisare();
		do {
			cout << "Introduceti numarul pacientului " ;
			cin >> nr ;
		}while (nr < 1);
		for (i = 1 ; i < nr && aux != 0 ; i++)
			aux = aux->getElem();
		if (aux == 0)
			cout << "Numar eronat !\n" ;
		else{
			p = aux->getPers();
			lista1->afisarePrimirePac(p);
		}
	}else
		cout << "Date insuficiente !\n" ;
	pauza();
}

/****** Membri clasa OpAfisarePrimire ******/

OpAfisarePrimire::OpAfisarePrimire(char *nume, listaPrimire *lista) : Operatie (nume) {
	this->lista = lista;
}

void OpAfisarePrimire::execOperatie() {
	lista->afisarePrimire();
	pauza();
}