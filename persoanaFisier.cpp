#include <fstream>
#include <iomanip>
using namespace std;
#include "persoana.h"

static fstream F;//("Spital.txt");

void Persoana::afisarePersoanaF() {
	F << nume << " " << prenume << " " << dataNastere->getZi() << " "
		<< dataNastere->getLuna() << " " << dataNastere->getAn() << " "
		<< adresa->getStrada() << " " << adresa->getNumar() << " "
		<< adresa->getBloc() << " " << adresa->getApartament() << " "
		<< telefon ;
}

void Persoana::afisareF() {
	afisarePersoanaF();
	F << endl ;
}

Persoana *setPersoanaF() {
	int a, l, z, nr, ap; 
	char *n, *p, *str, *tel, bl;
	n = getStringF();
	p = getStringF();
	F >> z;
	F >> l;
	F >> a;
	Data *d = new Data(a,l,z);
	str = getStringF();
	F >> nr;
	F >> bl;
	F >> ap;
	Adresa *ad = new Adresa(str,nr,bl,ap);
	tel = getStringF();
	return new Persoana(n,p,d,ad,tel);
}

void Asistent::afisareAngajatF() {
	this->afisarePersoanaF();
	F << " " << specialitate ;
}

/*void Asistent::afisareF() {
	this->afisareAngajatF();
	F << endl ;
}*/

Persoana *setAsistentF() {
	Persoana *pers = new Persoana();
	pers = setPersoanaF();
	char *sp;
	sp = getStringF();
	return new Asistent(pers, sp);
}

void Doctor::afisareF() {
	this->afisareAngajatF();
	F << " " << cabinet << endl ;
}

Persoana *setDoctorF() {
	Persoana *pers = new Persoana();
	pers = setPersoanaF();
	char *sp;
	sp = getStringF();
	int cab;
	F >> cab ;
	return new Doctor(pers,sp,cab);
}

void Monitorizat::afisarePacientF() {
	this->afisarePersoanaF();
	F << " " << diagnostic ;
}

void Monitorizat::afisareF() {
	this->afisarePacientF();
	F << endl ;
}

Persoana *setMonitorizatF() {
	Persoana *pers = new Persoana();
	pers = setPersoanaF();
	char *diag;
	diag = getStringF();
	return new Monitorizat(pers, diag);
}

void Internat::afisareF() {
	this->afisarePacientF();
	F << " " << sala << endl ;
}

Persoana *setInternatF(){
	Persoana *pers = new Persoana();
	pers = setPersoanaF();
	char *diag;
	diag = getStringF();
	int s;
	F >> s ;
	return new Internat(pers,diag,s);
}

void scrieDelim() {
	F << "_" << endl;
}

char *getStringF() {
	char buffer[15];
	char *s=0;
	int a;
	F >> buffer;
	a=strlen(buffer)+1;
	s = new char[a];
	strcpy(s,buffer);
	return s;
}

char topCharF() {
	return F.peek();
}

char top2CharF() {
	F.get();
	return F.peek();
}

void deschideScriere() {
	F.open("Spital.txt",ios::out);
}

void deschideCitire() {
	F.open("Spital.txt",ios::in);
}

void inchideF() {
	F.close();
}