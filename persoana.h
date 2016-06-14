#ifndef _persoana_
#define _persoana_
#pragma warning(disable : 4996)

class Data {
private:
	int an,luna,zi;
public:
	Data(){}
	Data(int an, int luna, int zi);
	int getAn();
	int getLuna();
	int getZi();
};

class Adresa {
private:
	char *strada;
	int numar,apartament;
	char bloc;
public:
	Adresa(){}
	Adresa(char *strada, int numar, char bloc, int apartament);
	char *getStrada();
	int getNumar();
	char getBloc();
	int getApartament();
};

class Persoana {
private:
	char *nume, *prenume, *telefon;
	Data *dataNastere;
	Adresa *adresa;
protected:
	void afisarePersoana();
	void afisarePersoanaF();
public:
	Persoana(char *nume, char *prenume, Data *dataNastere, Adresa *adresa, char* telefon);
	Persoana() {}
	~Persoana();
	char *getNume();
	char *getPrenume();
	Data *getDataNastere();
	Adresa *getAdresa();
	char *getTelefon();
	virtual void afisare();
	virtual void afisareF();
};
Persoana *setPersoana();
Persoana *setPersoanaF();
	
class Asistent : public Persoana {
private:
	char *specialitate;
protected:
	void afisareAngajat();
	void afisareAngajatF();
public:
	Asistent(Persoana *pers, char *sp);
	Asistent() {}
	~Asistent();
	char *getSpecialitate();
	void afisare();
//	void afisareF();
};

Persoana *setAsistent();
Persoana *setAsistentF();

class Doctor : public Asistent {
private:
	int cabinet;
public:
	Doctor(Persoana *pers, char *sp, int cab);
	Doctor(Asistent *asist, int cab); 
	Doctor() {}
	~Doctor();
	int getCabinet();
	void afisare();
	void afisareF();
};
Persoana *setDoctor();
Persoana *setDoctorF();

class Monitorizat : public Persoana {
private:
	char *diagnostic;
protected:
	void afisarePacient();
	void afisarePacientF();
public:
	Monitorizat(Persoana *pers, char *diag);
	Monitorizat() {}
	~Monitorizat();
	char *getDiagnostic();
	void afisare();
	void afisareF();
};
Persoana *setMonitorizat();
Persoana *setMonitorizatF();

class Internat : public Monitorizat {
private:
	int sala;
public:
	Internat(Persoana *pers, char *diag, int sala);
	Internat(Monitorizat *mon, int sala);
	Internat() {}
	~Internat();
	int getSala();
	void afisare();
	void afisareF();
};
Persoana *setInternat();
Persoana *setInternatF();


void scrieDelim();
char *getStringF();
char topCharF();
char top2CharF();
void deschideScriere();
void deschideCitire();
void inchideF();

#endif