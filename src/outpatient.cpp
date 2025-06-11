#include <iostream>
#include <iomanip>
#include "person.h"
#include "global.h"
using namespace std;

Outpatient::Outpatient(Person *person, char *diagnosis) :
Person(person->getFirstName(), person->getLastName(), person->getDateOfBirth(), person->getAddress(), person->getPhone()) {
    this->diagnosis = new char[strlen(diagnosis) + 1];
    strcpy(this->diagnosis, diagnosis);
}

Outpatient::~Outpatient() {
    delete[] diagnosis;
}

char *Outpatient::getDiagnosis() {
    return this->diagnosis;
}

void Outpatient::printOutpatient() {
    this->printPerson();
    cout << " " << left << setfill(' ') << setw(9) << diagnosis;
}

void Outpatient::print() {
    this->printOutpatient();
    cout << endl;
}

Person *getOutpatient() {
    Person *person = new Person();
    person = getPerson();
    char *diagnosis;
    cout << "Enter diagnosis: ";
    diagnosis = getString();
    return new Outpatient(person, diagnosis);
}