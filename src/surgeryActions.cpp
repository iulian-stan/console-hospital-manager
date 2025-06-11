#include <iostream>
#include "global.h"
#include "actions.h"
using namespace std;

AddSurgeryAction::AddSurgeryAction(char *name, SurgeryList *surgeries, List *doctors, List *nurses, List *inpatients)
: Action(name) {
    this->surgeries = surgeries;
    this->doctors = doctors;
    this->nurses = nurses;
    this->inpatients = inpatients;
}

void AddSurgeryAction::executeAction() {
    int i, j, nrDoctors, nrNurses, nr;
    Person **d, **a, *in;
    ListItem *aux1 = doctors->getElement(), *aux2 = nurses->getElement(), *aux3 = inpatients->getElement() , *aux;
    if (aux1 != 0 && aux2 != 0 && aux3 !=0) {
        do {
            cout << "Enter the number of doctors (maxim "<< doctors->getLength() << "): ";
            cin >> nrDoctors;
        } while (nrDoctors < 1 || nrDoctors > doctors->getLength());
        d = new Person*[nrDoctors];
        doctors->print();
        for (i = 0; i < nrDoctors; i++) {
            do {
                cout << "Enter doctor number: ";
                cin >> nr;
            }while (nr < 1);
            aux = aux1;
            for (j = 1; j < nr && aux != 0; j++)
                aux = aux->getNextItem();
            if (aux == 0) {
                cout << "Invalid number !\n";
                i--;
            }
            else
                d[i] = aux->getItemData();
        }
        do {
            cout << "Enter the number of nurses (maxim "<< nurses->getLength() << "): ";
            cin >> nrNurses;
        } while (nrNurses < 1 || nrNurses > nurses->getLength());
        a = new Person*[nrNurses];
        nurses->print();
        for (i = 0; i < nrNurses; i++) {
            do {
                cout << "Enter nurse number: ";
                cin >> nr;
            }while (nr < 1);
            aux = aux2;
            for (j = 1; j < nr && aux != 0; j++)
                aux = aux->getNextItem();
            if (aux == 0) {
                cout << "Invalid number !\n";
                i--;
            }
            else
                a[i] = aux->getItemData();
        }
        inpatients->print();
        for (i = 0; i < 1; i++) {
            do {
                cout << "Enter inpatient number: ";
                cin >> nr;
            }while (nr < 1);
            for (j = 1; j < nr && aux3 != 0; j++)
                aux3 = aux3->getNextItem();
            if (aux3 == 0) {
                cout << "Invalid number !\n";
                i--;
            }else
                in = aux3->getItemData();
        }
        surgeries->addSurgery(nrDoctors,d,nrNurses,a,in);
    }else
        cout << "Insufficient data !\n";
    pause();
}

PrintDoctorSurgeriesAction::PrintDoctorSurgeriesAction(char *name, SurgeryList *surgeries, List *doctors) : Action(name) {
    this->surgeries = surgeries;
    this->doctors = doctors;
}

void PrintDoctorSurgeriesAction::executeAction() {
    int i, nr;
    Person *d;
    ListItem *aux = doctors->getElement();
    if (surgeries != 0 && aux != 0) {
        doctors->print();
        do {
            cout << "Enter doctor number: ";
            cin >> nr;
        }while (nr < 1);
        for (i = 1; i < nr && aux != 0; i++)
            aux = aux->getNextItem();
        if (aux == 0)
            cout << "Invalid number !\n";
        else{
            d = aux->getItemData();
            surgeries->printDoctors(d);
        }
    }else
        cout << "Insufficient data !\n";
    pause();
}

PrintNurseSurgeriesAction::PrintNurseSurgeriesAction(char *name, SurgeryList *surgeries, List *nurses) : Action(name) {
    this->surgeries = surgeries;
    this->nurses = nurses;
}

void PrintNurseSurgeriesAction::executeAction() {
    int i, nr;
    Person *a;
    ListItem *aux = nurses->getElement();
    if (surgeries != 0 && aux != 0) {
        nurses->print();
        do {
            cout << "Enter nurse number: ";
            cin >> nr;
        }while (nr < 1);
        for (i = 1; i < nr && aux != 0; i++)
            aux = aux->getNextItem();
        if (aux == 0)
            cout << "Invalid number !\n";
        else{
            a = aux->getItemData();
            surgeries->printNurses(a);
        }
    }else
        cout << "Insufficient data !\n";
    pause();
}

PrintInpatientSurgeriesAction::PrintInpatientSurgeriesAction(char *name, SurgeryList *surgeries, List *inpatients) : Action(name) {
    this->surgeries = surgeries;
    this->inpatients = inpatients;
}

void PrintInpatientSurgeriesAction::executeAction() {
    int i, nr;
    Person *in;
    ListItem *aux = inpatients->getElement();
    if (surgeries != 0 && aux != 0) {
        inpatients->print();
        do {
            cout << "Enter inpatient number: ";
            cin >> nr;
        }while (nr < 1);
        for (i = 1; i < nr && aux != 0; i++)
            aux = aux->getNextItem();
        if (aux == 0)
            cout << "Invalid number !\n";
        else{
            in = aux->getItemData();
            surgeries->printInpatient(in);
        }
    }else
        cout << "Insufficient data !\n";
    pause();
}

PrintSurgeriesAction::PrintSurgeriesAction(char *name, SurgeryList *surgeries) : Action(name) {
    this->surgeries = surgeries;
}

void PrintSurgeriesAction::executeAction() {
    surgeries->print();
    pause();
}