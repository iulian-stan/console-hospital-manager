#include "person.h"

#ifndef _APPOINTMENT_H
#define _APPOINTMENT_H

class Appointment {
private:
    Person *doctor, *patient;
    char *prescription;
    Appointment *next;
public:
    Appointment() {}
    Appointment(Person *doctor, Person *patient, char *prescription, Appointment *next);
    ~Appointment();
    void printAppointment();
    friend class AppointmentList;
};

class AppointmentList {
private:
    Appointment *appointment;
public:
    AppointmentList();
    AppointmentList(Appointment *appointment);
    ~AppointmentList();
    Person *getDoctor();
    Person *getPatient();
    char *getPrescription();
    Appointment *getNext();
    void addAppointment(Person *d, Person *p, char *prescrip);
    void printAppointment();
    void printAppointmentDoctor(Person *d);
    void printAppointmentPatient(Person *p);
};

#endif