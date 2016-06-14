#include "persoana.h"

#ifndef _lista_
#define _lista_

//reprezinta o lista de persoana. Fiecare persoana poate fi
//doctor , asistent sau  pacient (internat sau monitorizat). 

class Element {
private:
	Persoana *p;
	Element *urm;
public:
	Element() {}
	Element(Persoana *p, Element *urm);
	Persoana *getPers();
	Element *getElem();
	~Element();
	friend class Lista;
};


class Lista {
private:
	Element *el;
	int nrEl;
public:
	Lista();
	Lista(Element *el);
	~Lista();
	Element *getElement();
	Persoana *getPersoana();
	Element *getUrmator();
	int getNrEl();
	void operator += (Persoana *&p);
	void sterge();
	void transferA_D(Lista *&l);
	void transferM_I(Lista *&l);
	void transferI_M(Lista *&l);
	void afisare();
	void afisareF();
};

#endif