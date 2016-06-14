#include <iostream>
using namespace std;
#include "globale.h"
#include "operatiiSimple.h"

/****** Membri clasa ElementDespre ******/

ElementDespre::ElementDespre(char *nume) : Operatie(nume) {}

void ElementDespre::execOperatie() {
	cout << "\tProgramul simuleaza activitatea timp de o zi a unui spital,"
		<< " ducind evidenta activitatii personalului,"
		<< " monitorizarea pacientilor, eliberarea prescriptiilor"
		<< " si programarea operatiilor."<< endl;
	cout << "\tIn orice moment este posibila adaugarea unui nou angajat,"
		<< " sau primirea informatiei unui pacient,"
		<< " eliberarea unei prescrptii medicale sau inscriere la operatie." 
		<< endl;
	pauza();
}

/****** Membri clasa OpAdaugareInLista ******/

OpAdaugareInLista::OpAdaugareInLista(char *nume, Lista *&lista) : Operatie(nume) {
	this->lista = lista;
}

/****** Membri clasa OpAdaugareDoctor ******/

OpAdaugareDoctor::OpAdaugareDoctor(char *nume, Lista *&lista) : OpAdaugareInLista(nume,lista) {
}

void OpAdaugareDoctor::execOperatie() {
	this->pers = new Doctor();
	this->pers = setDoctor();
	(*this->lista)+=this->pers;
	lista->afisare();
	pauza();
}

/****** Membri clasa OpAdaugareAsistent ******/

OpAdaugareAsistent::OpAdaugareAsistent(char *nume, Lista *&lista) : OpAdaugareInLista(nume,lista) {
}

void OpAdaugareAsistent::execOperatie() {
	this->pers = new Asistent();
	this->pers = setAsistent();
	(*lista)+=pers;
	lista->afisare();
	pauza();
}

/****** Membri clasa OpAdaugareMonitorizat ******/

OpAdaugareMonitorizat::OpAdaugareMonitorizat(char *nume, Lista *&lista) : OpAdaugareInLista(nume,lista) {
}


void OpAdaugareMonitorizat::execOperatie() {
	this->pers = new Monitorizat();
	this->pers = setMonitorizat();
	(*lista)+=pers;
	lista->afisare();
	pauza();
}

/****** Membri clasa OpAdaugareInternat ******/

OpAdaugareInternat::OpAdaugareInternat(char *nume, Lista *&lista) : OpAdaugareInLista(nume,lista) {
}

void OpAdaugareInternat::execOperatie() {
	this->pers = new Internat();
	this->pers = setInternat();
	(*lista)+=pers;
	lista->afisare();
	pauza();
}

/****** Membri clasa OpAfisreLista ******/

OpAfisareLista::OpAfisareLista(char *nume, Lista *lista) : Operatie(nume) {
	this->lista = lista;
}

void OpAfisareLista::execOperatie() {
	lista->afisare();
	pauza();
}

/****** Membri clasa OpAfisareGrup ******/

OpAfisareGrup::OpAfisareGrup(char *nume, Lista *lista1, Lista *lista2) : Operatie(nume) {
	this->lista1=lista1;
	this->lista2=lista2;
}

void OpAfisareGrup::execOperatie() {
	this->lista1->afisare();
	this->lista2->afisare();
	pauza();
}

/****** Membri clasa OpStergereElement ******/

OpStergereElement::OpStergereElement(char *nume, Lista *&lista) : Operatie(nume) {
	this->lista = lista;
}

void OpStergereElement::execOperatie(){
	lista->afisare();
	lista->sterge();
	lista->afisare();
	pauza();
}

/****** Membri clasa OpTransferA_D ******/

OpTransferA_D::OpTransferA_D(char *nume, Lista *&lista1, Lista *&lista2) : Operatie(nume) {
	this->lista1 = lista1;
	this->lista2 = lista2;
}

void OpTransferA_D::execOperatie(){
	lista1->afisare();
	lista1->transferA_D(lista2);
	lista1->afisare();
	lista2->afisare();
	pauza();
}

/****** Membri clasa OpTransferM_I ******/

OpTransferM_I::OpTransferM_I(char *nume, Lista *&lista1, Lista *&lista2) : Operatie(nume) {
	this->lista1 = lista1;
	this->lista2 = lista2;
}

void OpTransferM_I::execOperatie(){
	lista1->afisare();
	lista1->transferM_I(lista2);
	lista1->afisare();
	lista2->afisare();
	pauza();
}

/****** Membri clasa OpTransferI_M ******/

OpTransferI_M::OpTransferI_M(char *nume, Lista *&lista1, Lista *&lista2) : Operatie(nume) {
	this->lista1 = lista1;
	this->lista2 = lista2;
}

void OpTransferI_M::execOperatie(){
	lista1->afisare();
	lista1->transferI_M(lista2);
	lista1->afisare();
	lista2->afisare();
	pauza();
}

/****** Membri clasa OpScriereInFisier******/

OpScriereInFisier::OpScriereInFisier(char *nume, Lista *lista1 , Lista *lista2 , Lista *lista3 ,Lista *lista4) : 
Operatie(nume) {
	this->lista1 = lista1;
	this->lista2 = lista2;
	this->lista3 = lista3;
	this->lista4 = lista4;
}

void OpScriereInFisier::execOperatie() {
	deschideScriere();
	lista1->afisareF();
	scrieDelim();
	lista2->afisareF();
	scrieDelim();
	lista3->afisareF();
	scrieDelim();
	lista4->afisareF();
	scrieDelim();
	inchideF();
	pauza();
}

/****** Membri clasa OpCitireDinFisier******/

OpCitireDinFisier::OpCitireDinFisier(char *nume, Lista *lista1 , Lista *lista2 , Lista *lista3 ,Lista *lista4) : 
Operatie(nume) {
	this->lista1 = lista1;
	this->lista2 = lista2;
	this->lista3 = lista3;
	this->lista4 = lista4;
}

void OpCitireDinFisier::execOperatie() {
	Persoana *p;
	deschideCitire();
	char c = topCharF();
	while (c != '_' ) {
		p = setDoctorF();
		(*lista1) += p;
		c = top2CharF();
	}
	c = top2CharF();
	while (c != '_' ) {
		p = setAsistentF();
		(*lista2) += p;
		c = top2CharF();
	}
	c = top2CharF();
	while (c != '_' ) {
		p = setInternatF();
		(*lista3) += p;
		c = top2CharF();
	}
	c = top2CharF();
	while (c != '_' ) {
		p = setMonitorizatF();
		(*lista4) += p;
		c = top2CharF();
	}
	inchideF();
	pauza();
}