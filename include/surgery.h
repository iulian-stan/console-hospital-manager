#include "person.h"

#ifndef _SURGERY_H
#define _SURGERY_H

class Surgery {
private:
    int nrDoctors, nrNurses;
    Person **doctors, **nurses, *inpatient;
    Surgery *next;
public:
    Surgery() {}
    Surgery(int nrDoctors, Person **doctors, int nrNurses, Person **nurses, Person *inpatient, Surgery *next);
    ~Surgery();
    void printOp();
    friend class SurgeryList;
};

class SurgeryList {
private:
    Surgery *surgery;
public:
    SurgeryList();
    SurgeryList(Surgery *surgery);
    ~SurgeryList();
    Person **getDoctors();
    Person **getNurses();
    Person *getInpatients();
    int getNrDoctors();
    int getNrNurses();
    void addSurgery(int nrDoctors, Person **doctors, int nrNurses, Person **nurses, Person *inpatient);
    void print();
    void printDoctors(Person *doctors);
    void printNurses(Person *nurses);
    void printInpatient(Person *inpatient);
};

#endif