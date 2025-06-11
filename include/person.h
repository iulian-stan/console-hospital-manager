#ifndef _PERSON_H
#define _PERSON_H

#pragma warning(disable : 4996)

class Date {
private:
    int year, month, day;
public:
    Date() {}
    Date(int year, int month, int day);
    int getYear();
    int getMonth();
    int getDay();
};

class Address {
private:
    char *street;
    int number, apartment;
    char bloc;
public:
    Address() {}
    Address(char *street, int number, char bloc, int apartment);
    char *getStreet();
    int getNumber();
    char getBloc();
    int getApartment();
};

class Person {
private:
    char *firstName, *lastName, *phone;
    Date *dateOfBirth;
    Address *address;
protected:
    void printPerson();
    void printPersonToFile();
public:
    Person(char *firstName, char *lastName, Date *dateOfBirth, Address *address, char* phone);
    Person() {}
    ~Person();
    char *getFirstName();
    char *getLastName();
    Date *getDateOfBirth();
    Address *getAddress();
    char *getPhone();
    virtual void print();
    virtual void printToFile();
};
Person *getPerson();
Person *getPersonFromFile();

class Nurse : public Person {
private:
    char *specialty;
protected:
    void printMedic();
    void printMedicToFile();
public:
    Nurse(Person *person, char *sp);
    Nurse() {}
    ~Nurse();
    char *getSpecialty();
    void print();
    void printToFile();
};
Person *getNurse();
Person *getNurseFromFile();

class Doctor : public Nurse {
private:
    int room;
public:
    Doctor(Person *person, char *sp, int cab);
    Doctor(Nurse *nurse, int cab);
    Doctor() {}
    ~Doctor();
    int getRoom();
    void print();
    void printToFile();
};
Person *getDoctor();
Person *getDoctorFromFile();

class Outpatient : public Person {
private:
    char *diagnosis;
protected:
    void printOutpatient();
    void printOutpatientToFile();
public:
    Outpatient(Person *person, char *diagnosis);
    Outpatient() {}
    ~Outpatient();
    char *getDiagnosis();
    void print();
    void printToFile();
};
Person *getOutpatient();
Person *getOutpatientFromFile();

class Inpatient : public Outpatient {
private:
    int ward;
public:
    Inpatient(Person *person, char *diagnosis, int ward);
    Inpatient(Outpatient *mon, int ward);
    Inpatient() {}
    ~Inpatient();
    int getWard();
    void print();
    void printToFile();
};
Person *getInpatient();
Person *getInpatientFromFile();

void printDelimToFile();
char *getStringFromFile();
char topCharFromFile();
char top2CharFromFile();
void openFileRead();
void openFileWrite();
void closeFile();

#endif