#include <iostream>
#include "surgery.h"
using namespace std;

/****** Surgery class methods ******/

Surgery::Surgery(int nrDoctors, Person **doctors, int nrNurses, Person **nurses, Person *inpatient, Surgery *next) {
    this->doctors = doctors;
    this->nurses = nurses;
    this->inpatient = inpatient;
    this->nrDoctors = nrDoctors;
    this->nrNurses = nrNurses;
    this->next = next;
}

Surgery::~Surgery() {
    delete doctors;
    delete nurses;
}

void Surgery::printOp() {
    int i;
    cout << "Doctors : ";
    for (i = 0; i < nrDoctors; i++)
        cout << doctors[i]->getFirstName() << " "
        << doctors[i]->getLastName() << "; ";
    cout << endl;
    cout << "  Nurses : ";
    for (i = 0; i < nrNurses; i++)
        cout << nurses[i]->getFirstName() << " "
        << nurses[i]->getLastName() << "; ";
    cout << endl;
    cout << "  Outpatients : " << inpatient->getFirstName() << " "
        << inpatient->getLastName() << " . ";
    cout << endl;
}

/****** SurgeryList class methods ******/

SurgeryList::SurgeryList() {
    surgery = 0;
}

SurgeryList::SurgeryList(Surgery *surgery) {
    this->surgery = surgery;
}

SurgeryList::~SurgeryList() {
    if (surgery) {
        delete surgery->doctors;
        delete surgery->nurses;
    }
    surgery = 0;
}

Person **SurgeryList::getDoctors() {
    return surgery->doctors;
}

Person **SurgeryList::getNurses() {
    return surgery->nurses;
}

Person *SurgeryList::getInpatients() {
    return surgery->inpatient;
}

int SurgeryList::getNrDoctors() {
    return surgery->nrDoctors;
}

int SurgeryList::getNrNurses() {
    return surgery->nrNurses;
}

void SurgeryList::addSurgery(int nrDoctors, Person **doctors, int nrNurses, Person **nurses, Person *inpatient) {
    surgery = new Surgery(nrDoctors, doctors, nrNurses, nurses, inpatient, surgery);
}

void SurgeryList::print() {
    int i = 0;
    Surgery *head = surgery;
    if (head == 0)
        cout << "Surgery list is empty !\n";
    else{
        while (head) {
            i++;
            cout << i << ".";
            head->printOp();
            head = head->next;
        }
    }
}

void SurgeryList::printDoctors(Person *doctors) {
    int i = 0;
    Surgery *head = surgery;
    if (head == 0)
        cout << "Surgery list is empty !\n";
    else{
        while (head) {
            for (int j = 0; j < head->nrDoctors; j++) {
                if (head->doctors[j] == doctors) {
                    i++;
                    cout << i << ".";
                    head->printOp();
                }
            }
            head = head->next;
        }
    }
}

void SurgeryList::printNurses(Person *nurses) {
    int i = 0;
    Surgery *head = surgery;
    if (head == 0)
        cout << "Surgery list is empty !\n";
    else{
        while (head) {
            for (int j = 0; j < head->nrNurses; j++) {
                if (head->nurses[j] == nurses) {
                    i++;
                    cout << i << ".";
                    head->printOp();
                }
            }
            head = head->next;
        }
    }
}

void SurgeryList::printInpatient(Person *p) {
    int i = 0;
    Surgery *head = surgery;
    if (head == 0)
        cout << "Surgery list is empty !\n";
    else{
        while (head) {
            if (head->inpatient == p) {
                i++;
                cout << i << ".";
                head->printOp();
            }
            head = head->next;
        }
    }
}