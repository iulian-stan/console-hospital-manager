#include <iostream>
#include "person.h"
#include "global.h"
using namespace std;

Inpatient::Inpatient(Person *person, char *diagnosis, int ward) : Outpatient(person,diagnosis) {
    this->ward = ward;
}

Inpatient::Inpatient(Outpatient *mon, int ward) : Outpatient(mon,mon->getDiagnosis()) {
    this->ward = ward;
}

Inpatient::~Inpatient() {
}

int Inpatient::getWard() {
    return this->ward;
}

void Inpatient::print() {
    this->printOutpatient();
    cout << " " << ward << endl;
}

Person *getInpatient() {
    Person *person = new Person();
    person = getPerson();
    char *diagnosis;
    cout << "Enter diagnostic: ";
    diagnosis = getString();
    int ward;
    do {
        cout << "Enter ward number (positive integer) ";
        cin >> ward;
    } while ( ward < 1 );
    return new Inpatient(person, diagnosis, ward);
}