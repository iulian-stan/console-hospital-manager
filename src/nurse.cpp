#include <iostream>
#include <iomanip>
#include "person.h"
#include "global.h"
using namespace std;

Nurse::Nurse(Person *person, char *specialty) :
Person(person->getFirstName(), person->getLastName(), person->getDateOfBirth(), person->getAddress(), person->getPhone()) {
    this->specialty = new char[strlen(specialty) + 1];
    strcpy(this->specialty, specialty);
}

Nurse::~Nurse() {
    delete []specialty;
}

char *Nurse::getSpecialty() {
    return this->specialty;
}

void Nurse::printMedic() {
    this->printPerson();
    cout << " " << left << setfill(' ') << setw(9) << specialty;
}

void Nurse::print() {
    this->printMedic();
    cout << endl;
}

Person *getNurse() {
    Person *person = new Person();
    person = getPerson();
    char *specialty;
    cout << "Enter specialty: ";
    specialty = getString();
    return new Nurse(person, specialty);
}