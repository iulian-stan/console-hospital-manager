#include <iostream>
#include "global.h"
#include "actions.h"
using namespace std;

/****** Description class methods ******/

Description::Description(char *name) : Action(name) {}

void Description::executeAction() {
    cout << "This application implements an hospital management system. It keeps track of:" << endl
        << "  1. Staff" << endl
        << "  2. Patients" << endl
        << "  3. Appointments" << endl
        << "  4. Surgeries" << endl;
    cout << "It allows at any moment to: " << endl
        << "  1. Add a new staff member" << endl
        << "  2. Add a new patient" << endl
        << "  3. Set an appointment" << endl
        << "  4. Schedule a surgery" << endl;
    pause();
}

/****** AddPersonAction class methods ******/

AddPersonAction::AddPersonAction(char *name, List *&list) : Action(name) {
    this->list = list;
}

/****** AddDoctorAction class methods ******/

AddDoctorAction::AddDoctorAction(char *name, List *&doctors) : AddPersonAction(name, doctors) {
}

void AddDoctorAction::executeAction() {
    this->person = new Doctor();
    this->person = getDoctor();
    (*this->list) += this->person;
    list->print();
    pause();
}

/****** AddNurseAction class methods ******/

AddNurseAction::AddNurseAction(char *name, List *&nurses) : AddPersonAction(name, nurses) {
}

void AddNurseAction::executeAction() {
    this->person = new Nurse();
    this->person = getNurse();
    (*list) += person;
    list->print();
    pause();
}

/****** AddOutpatientAction class methods ******/

AddOutpatientAction::AddOutpatientAction(char *name, List *&outpatients) : AddPersonAction(name, outpatients) {
}

void AddOutpatientAction::executeAction() {
    this->person = new Outpatient();
    this->person = getOutpatient();
    (*list) += person;
    list->print();
    pause();
}

/****** AddInpatientAction class methods ******/

AddInpatientAction::AddInpatientAction(char *name, List *&inpatients) : AddPersonAction(name, inpatients) {
}

void AddInpatientAction::executeAction() {
    this->person = new Inpatient();
    this->person = getInpatient();
    (*list) += person;
    list->print();
    pause();
}

/****** PrintListAction class methods ******/

PrintListAction::PrintListAction(char *name, List *list) : Action(name) {
    this->list = list;
}

void PrintListAction::executeAction() {
    list->print();
    pause();
}

/****** PrintListsAction class methods ******/

PrintListsAction::PrintListsAction(char *name, List *list1, List *list2) : Action(name) {
    this->list1=list1;
    this->list2=list2;
}

void PrintListsAction::executeAction() {
    this->list1->print();
    this->list2->print();
    pause();
}

/****** RemovePersonAction class methods ******/

RemovePersonAction::RemovePersonAction(char *name, List *&list) : Action(name) {
    this->list = list;
}

void RemovePersonAction::executeAction() {
    list->print();
    list->clean();
    list->print();
    pause();
}

/****** PromoteNurseToDoctorAction class methods ******/

PromoteNurseToDoctorAction::PromoteNurseToDoctorAction(char *name, List *&nurses, List *&doctors) : Action(name) {
    this->nurses = nurses;
    this->doctors = doctors;
}

void PromoteNurseToDoctorAction::executeAction() {
    nurses->print();
    nurses->promoteNurse(doctors);
    nurses->print();
    doctors->print();
    pause();
}

/****** AdmitOutpatientAction class methods ******/

AdmitOutpatientAction::AdmitOutpatientAction(char *name, List *&outpatients, List *&inpatients) : Action(name) {
    this->outpatients = outpatients;
    this->inpatients = inpatients;
}

void AdmitOutpatientAction::executeAction() {
    outpatients->print();
    outpatients->admitOutpatient(inpatients);
    outpatients->print();
    inpatients->print();
    pause();
}

/****** DischargeInpatientAction class methods ******/

DischargeInpatientAction::DischargeInpatientAction(char *name, List *&inpatients, List *&outpatients) : Action(name) {
    this->inpatients = inpatients;
    this->outpatients = outpatients;
}

void DischargeInpatientAction::executeAction() {
    inpatients->print();
    inpatients->dischargeInpatient(outpatients);
    inpatients->print();
    outpatients->print();
    pause();
}

/****** FileWriteAction class methods ******/

FileWriteAction::FileWriteAction(char *name, List *doctors, List *nurses, List *inpatients, List *outpatients) :
Action(name) {
    this->doctors = doctors;
    this->nurses = nurses;
    this->inpatients = inpatients;
    this->outpatients = outpatients;
}

void FileWriteAction::executeAction() {
    openFileRead();
    doctors->printToFile();
    printDelimToFile();
    nurses->printToFile();
    printDelimToFile();
    inpatients->printToFile();
    printDelimToFile();
    outpatients->printToFile();
    printDelimToFile();
    closeFile();
    pause();
}

/****** FileReadAction clasa FileReadAction******/

FileReadAction::FileReadAction(char *name, List *doctors, List *nurses, List *inpatients, List *outpatients) :
Action(name) {
    this->doctors = doctors;
    this->nurses = nurses;
    this->inpatients = inpatients;
    this->outpatients = outpatients;
}

void FileReadAction::executeAction() {
    Person *p;
    openFileWrite();
    char c = topCharFromFile();
    while (c != '_' ) {
        p = getDoctorFromFile();
        (*doctors) += p;
        c = top2CharFromFile();
    }
    c = top2CharFromFile();
    while (c != '_' ) {
        p = getNurseFromFile();
        (*nurses) += p;
        c = top2CharFromFile();
    }
    c = top2CharFromFile();
    while (c != '_' ) {
        p = getInpatientFromFile();
        (*inpatients) += p;
        c = top2CharFromFile();
    }
    c = top2CharFromFile();
    while (c != '_' ) {
        p = getOutpatientFromFile();
        (*outpatients) += p;
        c = top2CharFromFile();
    }
    closeFile();
    pause();
}