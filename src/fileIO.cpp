#include <fstream>
#include <iomanip>
#include "person.h"
using namespace std;

static fstream file;

void Person::printPersonToFile() {
    file << firstName << " " << lastName << " " << dateOfBirth->getDay() << " "
        << dateOfBirth->getMonth() << " " << dateOfBirth->getYear() << " "
        << address->getStreet() << " " << address->getNumber() << " "
        << address->getBloc() << " " << address->getApartment() << " "
        << phone;
}

void Person::printToFile() {
    printPersonToFile();
    file << endl;
}

Person *getPersonFromFile() {
    int year, month, day, number, apartment;
    char *firstName, *lastName, *street, *phone, block;
    firstName = getStringFromFile();
    lastName = getStringFromFile();
    file >> day;
    file >> month;
    file >> year;
    Date *dateOfBirth = new Date(year, month, day);
    street = getStringFromFile();
    file >> number;
    file >> block;
    file >> apartment;
    Address *address = new Address(street, number, block, apartment);
    phone = getStringFromFile();
    return new Person(firstName, lastName, dateOfBirth, address, phone);
}

void Nurse::printMedicToFile() {
    this->printPersonToFile();
    file << " " << specialty;
}

void Nurse::printToFile() {
    this->printMedicToFile();
    file << endl;
}

Person *getNurseFromFile() {
    Person *person = new Person();
    person = getPersonFromFile();
    char *specialty;
    specialty = getStringFromFile();
    return new Nurse(person, specialty);
}

void Doctor::printToFile() {
    this->printMedicToFile();
    file << " " << room << endl;
}

Person *getDoctorFromFile() {
    Person *person = new Person();
    person = getPersonFromFile();
    char *specialty;
    specialty = getStringFromFile();
    int room;
    file >> room;
    return new Doctor(person, specialty, room);
}

void Outpatient::printOutpatientToFile() {
    this->printPersonToFile();
    file << " " << diagnosis;
}

void Outpatient::printToFile() {
    this->printOutpatientToFile();
    file << endl;
}

Person *getOutpatientFromFile() {
    Person *person = new Person();
    person = getPersonFromFile();
    char *diagnosis;
    diagnosis = getStringFromFile();
    return new Outpatient(person, diagnosis);
}

void Inpatient::printToFile() {
    this->printOutpatientToFile();
    file << " " << ward << endl;
}

Person *getInpatientFromFile() {
    Person *person = new Person();
    person = getPersonFromFile();
    char *diagnosis;
    diagnosis = getStringFromFile();
    int ward;
    file >> ward;
    return new Inpatient(person, diagnosis, ward);
}

void printDelimToFile() {
    file << "_" << endl;
}

char *getStringFromFile() {
    char buffer[15];
    char *s = 0;
    int year;
    file >> buffer;
    year = strlen(buffer) + 1;
    s = new char[year];
    strcpy(s, buffer);
    return s;
}

char topCharFromFile() {
    return file.peek();
}

char top2CharFromFile() {
    file.get();
    return file.peek();
}

void openFileRead() {
    file.open("DB.txt", ios::out);
}

void openFileWrite() {
    file.open("DB.txt", ios::in);
}

void closeFile() {
    file.close();
}