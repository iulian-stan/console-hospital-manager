#include <iostream>
#include "person.h"
#include "global.h"
using namespace std;

Doctor::Doctor(Person *person, char *specialty, int room) : Nurse(person, specialty) {
    this->room = room;
}

Doctor::Doctor(Nurse *nurse, int room) : Nurse(nurse, nurse->getSpecialty()) {
    this->room = room;
}

Doctor::~Doctor() {
}

int Doctor::getRoom() {
    return this->room;
}

void Doctor::print() {
    this->printMedic();
    cout << " " << room << endl;
}

Person *getDoctor() {
    Person *person = new Person();
    person = getPerson();
    char *specialty;
    cout << "Enter specialty: ";
    specialty = getString();
    int room;
    do {
        cout << "Enter room number (positive integer): ";
        cin >> room;
    } while ( room < 1 );
    return new Doctor(person, specialty, room);
}