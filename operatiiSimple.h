#include "meniu.h"
#include "lista.h"
#include "activitate.h"

#ifndef _operatiiSimple_
#define _operatiiSimple_


class ElementDespre : public Operatie {    //Afiseaza pe ecran modul de 
public:                                    //functionare al programului
	ElementDespre(char *nume);
	void execOperatie();
};

class OpAdaugareInLista : public Operatie { //Adauga o persoana in lista
protected:
	Lista *lista;
	Persoana *pers;
public:
	OpAdaugareInLista(char *nume, Lista *&lista);
	virtual void execOperatie() = 0;
};

			class OpAdaugareDoctor : public OpAdaugareInLista { //Adauga un doctor in lista
			public:
				OpAdaugareDoctor(char *nume, Lista *&lista);
				void execOperatie();
			};

			class OpAdaugareAsistent : public OpAdaugareInLista { //Adauga un asistent in lista
			public:
				OpAdaugareAsistent(char *nume, Lista *&lista);
				void execOperatie();
			};

			class OpAdaugareInternat : public OpAdaugareInLista { //Adauga un pacient internat in lista
			public:
				OpAdaugareInternat(char *nume, Lista *&lista);
				void execOperatie();
			};

			class OpAdaugareMonitorizat : public OpAdaugareInLista { //Adauga un pacient monitorizat in lista
			public:
				OpAdaugareMonitorizat(char *nume, Lista *&lista);
				void execOperatie();
			};

class OpTransferA_D : public Operatie { //Promoveaza un asistent
private:
	Lista *lista1 , *lista2;
public:
	OpTransferA_D(char *nume, Lista *&lista1, Lista *&lista2);
	void execOperatie();
};

class OpTransferM_I : public Operatie { //Interneaza un pacient monitorizat
private:
	Lista *lista1 , *lista2;
public:
	OpTransferM_I(char *nume, Lista *&lista1, Lista *&lista2);
	void execOperatie();
};

class OpTransferI_M : public Operatie { //Elibereaza un pacient internat
private:                                //acesta fiind monitorizat in continuare
	Lista *lista1 , *lista2;
public:
	OpTransferI_M(char *nume, Lista *&lista1, Lista *&lista2);
	void execOperatie();
};


class OpAfisareLista : public Operatie { //Afiseaza continutul unei liste de persoane
private:
	Lista *lista;
public:
	OpAfisareLista(char *nume, Lista *lista);
	void execOperatie();
};

class OpAfisareGrup : public Operatie { //Afiseaza continutul a doua liste de persoane
private:
	Lista *lista1, *lista2;
public:
	OpAfisareGrup(char *nume, Lista *lista1, Lista *lista2);
	void execOperatie();
};

class OpStergereElement : public Operatie { //Sterge o persoana din lista
private:
	Lista *lista;
public:
	OpStergereElement(char *nume, Lista *&lista);
	void execOperatie();
};

class OpAdaugaPrimire : public Operatie { //Permite eliberarea unei prescriptii 
private:                                  //indicind pacientul din lista
	listaPrimire *lista;                  //pacientilor monitorizat si a 
	Lista *lista1, *lista2;               //doctorului care a eliberat-o
public:
	OpAdaugaPrimire(char *nume, listaPrimire *&lista, Lista *lista1, Lista *lista2);
	void execOperatie();
};

class OpAfisareDupaDoctor : public Operatie { //Afiseaza prescriptiile
private:                                      //eliberate de un doctor
	listaPrimire *lista1;                     //plus pacientul internat
	Lista *lista2;                            //carui i-a fost scrisa
public:
	OpAfisareDupaDoctor(char *nume, listaPrimire *lista1, Lista *lista2);
	void execOperatie();
};

class OpAfisareDupaPacient : public Operatie { //Afiseaza prescriptiile
private:                                       //eliberate unui pacient
	listaPrimire *lista1;                      //internat plus numele
	Lista *lista2;                             //doctorului 
public:
	OpAfisareDupaPacient(char *nume, listaPrimire *lista1, Lista *lista2);
	void execOperatie();
};

class OpAfisarePrimire : public Operatie { //Afiseaza toate prescriptile inregistrate
private:
	listaPrimire *lista;
public:
	OpAfisarePrimire(char *nume, listaPrimire *lista);
	void execOperatie();
};

class OpAdaugaOperatie : public Operatie { //Programeaza o operatie tinind cont de 
private:                                   //doctori (maxim 2), asistenti (maxim 6)
	listaOperatie *lista;                  //si pacient
	Lista *lista1, *lista2, *lista3;
public:
	OpAdaugaOperatie(char *nume, listaOperatie *lista, Lista *lista1, Lista *lista2, Lista *lista3);
	void execOperatie();
};

class OpAfisareOpDupaDoctor : public Operatie {//Afiseaza informatia operatiilor
private:                                       //la care a participat un doctor
	listaOperatie *lista;
	Lista *lista1;
public:
	OpAfisareOpDupaDoctor(char *nume, listaOperatie *lista, Lista *lista1);
	void execOperatie();
	};

class OpAfisareOpDupaAsistent : public Operatie {//Afiseaza informatia operatiilor
private:                                         //la care a participat un asistent
	listaOperatie *lista;
	Lista *lista1;
public:
	OpAfisareOpDupaAsistent(char *nume, listaOperatie *lista, Lista *lista1);
	void execOperatie();
};

class OpAfisareOpDupaPacient : public Operatie {  //Afiseaza informatia operatiilor
private:                                          //executate asupra unui asistent
	listaOperatie *lista;
	Lista *lista1;
public:
	OpAfisareOpDupaPacient(char *nume, listaOperatie *lista, Lista *lista1);
	void execOperatie();
};

class OpAfisareOperatii : public Operatie {   //Afiseaza informatia operatiilor inregistrate
private:
	listaOperatie *lista;
public:
	OpAfisareOperatii(char *nume, listaOperatie *lista);
	void execOperatie();
};

class OpScriereInFisier : public Operatie {   //Inscrie informatia referitoare la 
	Lista *lista1, *lista2, *lista3, *lista4; //angajati si pacienti in fisier
public:
	OpScriereInFisier(char *nume, Lista *lista1, Lista *lista2, Lista *lista3, Lista *lista4);
	void execOperatie();
};

class OpCitireDinFisier : public Operatie {   //Citeste informatia referitoare la 
	Lista *lista1, *lista2, *lista3, *lista4; //angajati si pacienti din fisier
public:
	OpCitireDinFisier(char *nume, Lista *lista1, Lista *lista2, Lista *lista3, Lista *lista4);
	void execOperatie();
};

#endif