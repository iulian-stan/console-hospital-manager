#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "globale.h"
#include "meniu.h"
#include "operatiiSimple.h"

int main() {
	Meniu *meniu = new Meniu("Spital");

	Lista *doctor = new Lista();
	Lista *asistent = new Lista();
	Lista *internat = new Lista();
	Lista *monitorizat = new Lista();

	listaPrimire *primire = new listaPrimire();
	listaOperatie *operatie = new listaOperatie();
	
	Meniu *submeniuPersonal = new Meniu("Personal");
	meniu->adaugaElement(submeniuPersonal);

	submeniuPersonal->adaugaElement ( new OpAfisareGrup ("Afisare Personal" , doctor , asistent));

	Meniu *submeniuDoctor = new Meniu("Doctor");
	submeniuPersonal->adaugaElement(submeniuDoctor);
	submeniuDoctor->adaugaElement ( new OpAdaugareDoctor ("Adaugare doctor" , doctor));
	submeniuDoctor->adaugaElement ( new OpStergereElement ("Concediere doctor" , doctor));
	submeniuDoctor->adaugaElement ( new OpAfisareLista ("Afisare doctori" , doctor));
	
	Meniu *submeniuAsistent = new Meniu("Asistent medical");
	submeniuPersonal->adaugaElement(submeniuAsistent);
    submeniuAsistent->adaugaElement ( new OpAdaugareAsistent ("Adaugare asistent" , asistent));
	submeniuAsistent->adaugaElement ( new OpTransferA_D ("Promovare asistent" , asistent , doctor));
	submeniuAsistent->adaugaElement ( new OpStergereElement ("Concediere asistent" , asistent));
	submeniuAsistent->adaugaElement ( new OpAfisareLista ("Afisare asistenti" , asistent));
	
	Meniu *submeniuPacienti = new Meniu("Pacienti");
	meniu->adaugaElement(submeniuPacienti);
	
	submeniuPacienti->adaugaElement ( new OpAfisareGrup ("Afisare Pacienti" , internat , monitorizat));
	
	Meniu *submeniuInternati = new Meniu("Internati");
	submeniuPacienti->adaugaElement(submeniuInternati);
	submeniuInternati->adaugaElement ( new OpAdaugareInternat ("Adaugare internat" , internat));
	submeniuInternati->adaugaElement ( new OpTransferI_M ("Eliberare internat" , internat , monitorizat));
	submeniuInternati->adaugaElement ( new OpAfisareLista ("Afisare internati" , internat));

	Meniu *submeniuMonitorizati = new Meniu("Monitorizati");	
	submeniuPacienti->adaugaElement(submeniuMonitorizati);
	submeniuMonitorizati->adaugaElement ( new OpAdaugareMonitorizat ("Adaugare monitoirzat" , monitorizat));
	submeniuMonitorizati->adaugaElement ( new OpStergereElement ("Scoatere de la evidenta" , monitorizat));
	submeniuMonitorizati->adaugaElement ( new OpTransferM_I ("Internare monitorizat" , monitorizat , internat));
	submeniuMonitorizati->adaugaElement ( new OpAfisareLista ("Afisare monitorizati" , monitorizat));

	Meniu *submeniuActivitate = new Meniu("Activitate");
	meniu->adaugaElement(submeniuActivitate);

	Meniu *submeniuPrimire = new Meniu("Primire");
	submeniuActivitate->adaugaElement(submeniuPrimire);
	submeniuPrimire->adaugaElement ( new OpAdaugaPrimire ("Adauga primire" , primire , doctor , monitorizat)); 
	submeniuPrimire->adaugaElement ( new OpAfisareDupaDoctor ("Prescriptiile eliberate de un doctor" , primire , doctor)); 
	submeniuPrimire->adaugaElement ( new OpAfisareDupaPacient ("Prescriptiile eliberate unui pacient" , primire , monitorizat)); 
	submeniuPrimire->adaugaElement ( new OpAfisarePrimire ("Afisare toate primirile" , primire)); 

	Meniu *submeniuOperatie = new Meniu("Operatie");
	submeniuActivitate->adaugaElement(submeniuOperatie);
	submeniuOperatie->adaugaElement ( new OpAdaugaOperatie ("Inscriere la operatii" , operatie , doctor , asistent , internat));
	submeniuOperatie->adaugaElement ( new OpAfisareOpDupaDoctor ("Operatiile unui doctor" , operatie , doctor));
	submeniuOperatie->adaugaElement ( new OpAfisareOpDupaAsistent ("Operatiile unui asistent" , operatie , asistent));
	submeniuOperatie->adaugaElement ( new OpAfisareOpDupaPacient ("Operatiile unui pacient" , operatie , internat));
	submeniuOperatie->adaugaElement ( new OpAfisareOperatii ("Afisare toate operatiile" , operatie));

	Meniu *submeniuFisier = new Meniu("Lucru cu fisier");
	meniu->adaugaElement(submeniuFisier);
	submeniuFisier->adaugaElement ( new OpScriereInFisier ("Scriere" , doctor , asistent , internat , monitorizat));
	submeniuFisier->adaugaElement ( new OpCitireDinFisier ("Citire" , doctor , asistent , internat , monitorizat));

	meniu->adaugaElement(new ElementDespre("Functionare"));

	meniu->executa();

	delete operatie;
	delete primire;

	delete doctor; 
	delete asistent;
	delete internat;
	delete monitorizat;

	delete meniu;

	cout << endl << endl << "Sfarsit." << endl;

	pauza();
	return 0;
}