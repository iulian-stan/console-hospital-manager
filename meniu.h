#ifndef _meniu_
#define _meniu_

                                  //Un element de meniu in general. 
                                  //Poate fi atat o operatie cat si un meniu.
class ElementMeniu {
private:
	char *nume;
	ElementMeniu *parinte;

protected:
	ElementMeniu(char *nume);
	virtual ~ElementMeniu();
	void afisareIncompletaTitlu();//afiseaza titlul mai putin caracterele 
	                              //de sfarsit, pentru a putea fi utilizata 
	                              //in afisarea propriului titlu cat si a fiilor.
	void afisareTitlu();          // va apela afisareIncompletaTitlu() + va tipari 
	                              //caracterele de sfarsit	

public:	
	char *getNume();
	virtual void executa() = 0;   //va contine logica executata la activarea acestui element
	friend class Meniu;           //este necesar pentru a putea seta parintele din clasa Meniu,  
	                              //si doar de acolo.
};

                                  //Un element de meniu care efectueaza o operatie. 
                                  //Reprezinta o frunza in arborele meniului
class Operatie : public ElementMeniu {
protected:
	Operatie(char *nume);
	virtual void execOperatie()=0;//operatia specifica acestui element

public:	                              
	void executa();			      //intreaga logica a elementului - afisare titlu + operatie
};

                                  //Reprezinta un element meniu care la randul sau este meniu. 
                                  //Poate fi atat meniul principal cat si un submeniu
class Meniu : public ElementMeniu {
private:
	static const int nrMaxElemente = 9;
	int nrElemente;	                              
	ElementMeniu **elemente;      //Meniul este stapan peste memoria fiilor sai.
                               	  //Astfel, la dealocare va dealoca si memoria fiilor.
	void afisare();               //afiseaza meniul la consola
	int citireComanda();          //asteapta apasarea unei taste, si activeaza elementul respectiv 
	                              //de meniu returneaza indicele fiului, sau -1 pentru iesire

public:
	Meniu(char *nume);
	~Meniu();                     //va dealoca fii sai, eventual recursiv.
	void adaugaElement(ElementMeniu *element);
	void executa();
};

#endif