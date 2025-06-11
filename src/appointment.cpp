#include <iostream>
#include <iomanip>
#include "appointment.h"
using namespace std;

/****** Appointment class methods ******/

Appointment::Appointment(Person *doctor, Person *patient, char *prescription, Appointment *next) {
    this->doctor = doctor;
    this->patient = patient;
    this->prescription = prescription;
    this->next = next;
}

Appointment::~Appointment() {
    delete prescription;
}

void Appointment::printAppointment() {
    cout << left << setfill(' ') << setw(9) << doctor->getFirstName() << " "
        << left << setfill(' ') << setw(9) << doctor->getLastName() << " "
        << left << setfill(' ') << setw(9) << patient->getFirstName() << " "
        << left << setfill(' ') << setw(9) << patient->getLastName() << " "
        << prescription << endl;
}

/****** AppointmentList class methods ******/

AppointmentList::AppointmentList() {
    this->appointment = 0;
}

AppointmentList::AppointmentList(Appointment *appointment) {
    this->appointment = appointment;
}

AppointmentList::~AppointmentList() {
    Appointment *del;
    while (appointment) {
        del = appointment;
        appointment = appointment->next;
        delete del;
    }
    appointment = 0;
}

Person *AppointmentList::getDoctor() {
    return appointment->doctor;
}

Person *AppointmentList::getPatient() {
    return appointment->patient;
}

char *AppointmentList::getPrescription() {
    return appointment->prescription;
}

Appointment *AppointmentList::getNext() {
    return appointment->next;
}

void AppointmentList::addAppointment(Person *d, Person *p, char *prescrip) {
    appointment = new Appointment(d,p,prescrip,appointment);
}

void AppointmentList::printAppointment() {
    int i = 0;
    Appointment *head = appointment;
    if (head == 0)
        cout << "Appointment list is empty !\n";
    else{
        cout << "  " << left << setfill(' ') << setw(20) << "Doctor"
            << left << setfill(' ') << setw(20) << "Outpatient"
            << "Appointment" << endl;
        while (head) {
            i++;
            cout << i << ".";
            head->printAppointment();
            head = head->next;
        }
    }
}

void AppointmentList::printAppointmentDoctor(Person *d) {
    int i = 0;
    Appointment *head = appointment;
    if (head == 0)
        cout << "Appointment list is empty !\n";
    else{
        cout << "  " << left << setfill(' ') << setw(20) << "Doctor"
            << left << setfill(' ') << setw(20) << "Outpatient"
            << "Appointment" << endl;
        while (head) {
            if (head->doctor == d) {
                i++;
                cout << i << ".";
                head->printAppointment();
            }
            head = head->next;
        }
    }
}

void AppointmentList::printAppointmentPatient(Person *p) {
    int i = 0;
    Appointment *head = appointment;
    if (head == 0)
        cout << "Appointment list is empty !\n";
    else{
        cout << "  " << left << setfill(' ') << setw(20) << "Doctor"
            << left << setfill(' ') << setw(20) << "Outpatient"
            << "Appointment" << endl;
        while (head) {
            if (head->patient == p) {
                i++;
                cout << i << ".";
                head->printAppointment();
            }
            head = head->next;
        }
    }
}
