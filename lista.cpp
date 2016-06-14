#include <iostream>
#include <iomanip>
using namespace std;
#include "lista.h"
#include "globale.h"


Element::Element(Persoana *p, Element *urm) {
	this->p = p;
	this->urm = urm;
}

Element::~Element() {
	delete p;
	p = 0;
	urm = 0;
}

Persoana *Element::getPers() {
	return p;
}

Element *Element::getElem() {
	return urm;
}

Lista::Lista() {
	this->el = 0;
	this->nrEl = 0;
}

Lista::Lista(Element *el) {
	this->el = el;
}

Lista::~Lista() {
	Element *del;
	while (el) {
		del = el;
		el = el->urm;
		delete del;
	}
	el = 0;
}

Element *Lista::getElement() {
	return el;
}

Persoana *Lista::getPersoana() {
	return el->p;
}

Element *Lista::getUrmator() {
	return el->urm;
}

int Lista::getNrEl() {
	return nrEl;
}

void Lista::operator += (Persoana *&pers) {
	el = new Element(pers,el);
	nrEl++;
}

void Lista::afisare() {
	int i = 0;
	Element *cap = el;
	if (cap == 0)
		cout << "Lista este vida !\n" ;
	else{
		cout << "  " << left << setfill(' ') << setw(9) << "Nume" << " "
			<< left << setfill(' ') << setw(9) << "Prenume" << " " 
			<< "zi.luna.an" << " "
			<< setfill(' ') << setw(9) << "Strada" << " "
			<< "nr/bloc/ap" << " "
			<< setfill(' ') << setw(9) << "Telefon" << " "
			<< setfill(' ') << setw(9) << "Spec/Diag" << " "
			<< "Sala" << endl;
		while (cap) {
			i++;
			cout << i << ".";
			cap->p->afisare();
			cap = cap->urm;
		}
	}
}

void Lista::afisareF() {
	Element *cap = el;
	while (cap) {
		cap->p->afisareF();
		cap = cap->urm;
	}
}

void Lista::sterge(){
	Element *del, *cap = el;
	int i, poz;
	if (el == 0)
		cout << "Lista persoanelor e vida !\n" ;
	else{
		do{
			cout << "Dati numarul persoanei (numar pozitiv) ";
			cin >> poz;
		} while (poz < 1);
		if (poz == 1){
			del = el;
			el = el->urm;
			cap = el;
			delete del;
			nrEl--;
		}else{
			for (i = 2 ; (i < poz) && (el->urm != 0) ; i++) 
				el = el->urm;
			if (el->urm == 0)
				cout << "Numar eronat !\n" ;
			else{
				del = el->urm;
				el->urm = del->urm;
				delete del;
				nrEl--;
			}
		}
		el = cap;		
	}
}

void Lista::transferA_D(Lista *&l) {
	Persoana *aux;
	Element *del, *cap = el;
	int i, poz, cab;
	if (el == 0)
		cout << "Lista persoanelor e vida !\n" ;
	else{
		do{
			cout << "Dati numarul asistentului (numar pozitiv) ";
			cin >> poz;
		} while (poz < 1);	
		if (poz == 1){
			del = el;
			el = el->urm;
			cap = el;
			do {
			cout << "Introduceti numarul cabinetul (intreg pozitiv) " ;
				cin >> cab;
			} while (cab < 1);
			aux = new Doctor((Asistent *)del->p,cab);
			(*l) += aux;
			nrEl--;
		}else{
			for (i = 2 ; (i < poz) && (el->urm != 0) ; i++) 
				el = el->urm;
			if (el->urm == 0)
				cout << "Numar eronat !\n" ;
			else{
				del = el->urm;
				el->urm = del->urm;
				do {
				cout << "Introduceti numarul cabinetul (intreg pozitiv) " ;
					cin >> cab;
				} while (cab < 1);
				aux = new Doctor((Asistent *)del->p,cab);
				(*l) += aux;
				nrEl--;
			}
		}
		el = cap;		
	}
}

void Lista::transferM_I(Lista *&l) {
	Persoana *aux;
	Element *del, *cap = el;
	int i, poz, sala;
	if (el == 0)
		cout << "Lista persoanelor e vida !\n" ;
	else{
		do{
			cout << "Dati numarul pacientului (numar pozitiv) ";
			cin >> poz;
		} while (poz < 1);	
		if (poz == 1){
			del = el;
			el = el->urm;
			cap = el;
			do {
				cout << "Introduceti numarul salii (intreg pozitiv) " ;
				cin >> sala;
			} while (sala < 1);
			aux = new Internat((Monitorizat *)del->p,sala);
			(*l) += aux;
			nrEl--;
		}else{
			for (i = 2 ; (i < poz) && (el->urm != 0) ; i++) 
				el = el->urm;
			if (el->urm == 0)
				cout << "Numar eronat !\n" ;
			else{
				del = el->urm;
				el->urm = del->urm;
				do {
					cout << "Introduceti numarul salii (intreg pozitiv) " ;
					cin >> sala;
				} while (sala < 1);
				aux = new Internat((Monitorizat *)del->p,sala);
				(*l) += aux;
				nrEl--;
			}
		}
		el = cap;		
	}
}

void Lista::transferI_M(Lista *&l) {
	Persoana *aux;
	Element *del, *cap = el;
	int i, poz;
	if (el == 0)
		cout << "Lista persoanelor e vida !\n" ;
	else{
		do{
			cout << "Dati numarul pacientului (numar pozitiv) ";
			cin >> poz;
		} while (poz < 1);	
		if (poz == 1){
			del = el;
			el = el->urm;
			cap = el;
			aux = new Monitorizat (del->p, ((Internat *)del->p)->getDiagnostic());
			(*l) += aux;
		}else{
			for (i = 2 ; (i < poz) && (el->urm != 0) ; i++) 
				el = el->urm;
			if (el->urm == 0)
				cout << "Numar eronat !\n" ;
			else{
				del = el->urm;
				el->urm = del->urm;
				aux = new Monitorizat (del->p, ((Internat *)del->p)->getDiagnostic());
				(*l) += aux;
				nrEl--;
			}
		}
		el = cap;		
	}
}