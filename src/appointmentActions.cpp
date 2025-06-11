#include <iostream>
#include "global.h"
#include "actions.h"
using namespace std;

/****** AddAppointmentAction class members ******/

AddAppointmentAction::AddAppointmentAction(char *name, AppointmentList *&appointments, List *doctors, List *outpatients) : Action(name) {
    this->appointments = appointments;
    this->doctors = doctors;
    this->outpatients = outpatients;
}

void AddAppointmentAction::executeAction() {
    int i, nr;
    Person *d, *p;
    char *pres;
    ListItem *aux1 = doctors->getElement(), *aux2 = outpatients->getElement();
    if (aux1 != 0 && aux2 != 0) {
        doctors->print();
        do {
            cout << "Enter doctor number: ";
            cin >> nr;
        }while (nr < 1);
        for (i = 1; i < nr && aux1 != 0; i++)
            aux1 = aux1->getNextItem();
        if (aux1 == 0)
            cout << "Invalid number !\n";
        else{
            d = aux1->getItemData();
            outpatients->print();
            do {
                cout << "Enter outpatient number ";
                cin >> nr;
            }while (nr < 1);
            for (i = 1; i < nr && aux2 != 0; i++)
                aux2 = aux2->getNextItem();
            if (aux2 == 0)
                cout << "Invalid number !\n";
            else {
                p = aux2->getItemData();
                cout << "Enter appointment: ";
                pres = getString();
                appointments->addAppointment(d,p,pres);
            }
        }
    }else
        cout << "Insufficient data !\n";
    pause();
}

/****** PrintDoctorAppointmentsAction class methods ******/

PrintDoctorAppointmentsAction::PrintDoctorAppointmentsAction(char *name, AppointmentList *appointments, List *doctors) : Action(name) {
    this->appointments = appointments;
    this->doctors = doctors;
}

void PrintDoctorAppointmentsAction::executeAction() {
    int i, nr;
    Person *d;
    ListItem *aux = doctors->getElement();
    if (appointments != 0 && aux != 0) {
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
            appointments->printAppointmentDoctor(d);
        }
    }else
        cout << "Insufficient data !\n";
    pause();
}

/****** ProintOutpatientAppointmentsAction class methods ******/

ProintOutpatientAppointmentsAction::ProintOutpatientAppointmentsAction(char *name, AppointmentList *appointments, List *outpatients) : Action(name) {
    this->appointments = appointments;
    this->outpatients = outpatients;
}

void ProintOutpatientAppointmentsAction::executeAction() {
    int i, nr;
    Person *p;
    ListItem *aux = outpatients->getElement();
    if (appointments != 0 && aux != 0) {
        outpatients->print();
        do {
            cout << "Enter outpatient number: ";
            cin >> nr;
        }while (nr < 1);
        for (i = 1; i < nr && aux != 0; i++)
            aux = aux->getNextItem();
        if (aux == 0)
            cout << "Invalid number !\n";
        else{
            p = aux->getItemData();
            appointments->printAppointmentPatient(p);
        }
    }else
        cout << "Insufficient data !\n";
    pause();
}

/****** PrintAppointmentsAction class methods ******/

PrintAppointmentsAction::PrintAppointmentsAction(char *name, AppointmentList *appointments) : Action(name) {
    this->appointments = appointments;
}

void PrintAppointmentsAction::executeAction() {
    appointments->printAppointment();
    pause();
}