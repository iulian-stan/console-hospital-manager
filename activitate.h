#include "persoana.h"

#ifndef _activitate_
#define _activitate_

class Primire {                    
private:
	Persoana *doc, *pac;
	char *prescriptie;
	Primire *urm;
public:
	Primire() {}
	Primire(Persoana *doc, Persoana *pac, char *prescriptie, Primire *urm);
	~Primire();
	void afisarePrim();
	friend class listaPrimire;
};

class listaPrimire {
private:
	Primire *prim;
public:
	listaPrimire();
	listaPrimire(Primire *prim);
	~listaPrimire();
	Persoana *getDoc();
	Persoana *getPac();
	char *getPrescriptie();
	Primire *getUrm();
	void addPrimire (Persoana *d, Persoana *p, char *prescrip);
	void afisarePrimire();
	void afisarePrimireDoc(Persoana *d);
	void afisarePrimirePac(Persoana *p);
};

class Operatii {
private:
	int nrDoctori, nrAsistenti;
	Persoana **docs, **asists, *intern;
	Operatii *urm;
public:
	Operatii() {}
	Operatii(int nrD, Persoana **docs, int nrA, Persoana **asists, Persoana *intern, Operatii *urm);
	~Operatii();
	void afisareOp();
	friend class listaOperatie;	
};

class listaOperatie {
private:
	Operatii *op;
public:
	listaOperatie();
	listaOperatie(Operatii *op);
	~listaOperatie();
	Persoana **getDocs();
	Persoana **getAsists();
	Persoana *getIntern();
	int getNrDoctori();
	int getNrAsistenti();
	void addOperatie (int nrD, Persoana **d, int nrA, Persoana **a, Persoana *i);
	void afisareOperatie();
	void afisareOperatieDoc(Persoana *d);
	void afisareOperatieAsist(Persoana *a);
	void afisareOperatieIntern(Persoana *i);
};

#endif