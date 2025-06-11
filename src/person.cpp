#include <iostream>
#include <iomanip>
#include "person.h"
#include "global.h"
using namespace std;

static const int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

Address::Address(char *street, int number, char bloc, int apartment) {
    this->street = street;
    this->number = number;
    this->bloc = bloc;
    this->apartment = apartment;
}

char *Address::getStreet() {
    return street;
}

int Address::getNumber() {
    return number;
}

char Address::getBloc() {
    return bloc;
}

int Address::getApartment() {
    return apartment;
}

Person::Person(char *firstName, char *lastName, Date *dateOfBirth, Address *address, char *phone) {
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
    this->address = new Address(*address);
    this->dateOfBirth = new Date(*dateOfBirth);
    this->phone = new char[strlen(phone) + 1];
    strcpy(this->phone, phone);
}

Person::~Person() {
    delete []firstName;
    delete []lastName;
    delete dateOfBirth;
    delete address;
    delete []phone;
}

char *Person::getFirstName() {
    return firstName;
}

char *Person::getLastName() {
    return lastName;
}

Address *Person::getAddress() {
    return address;
}

char *Person::getPhone() {
    return phone;
}

Date *Person::getDateOfBirth() {
    return dateOfBirth;
}

void Person::printPerson() {
    cout << left << setfill(' ') << setw(9) << firstName << " "
        << left << setfill(' ') << setw(9) << lastName << " "
        << setfill('0') << setw(2) << dateOfBirth->getDay() << "."
        << setfill('0') << setw(2) << dateOfBirth->getMonth() << "."
        << dateOfBirth->getYear() << " "
        << left << setfill(' ') << setw(9) << address->getStreet() << " "
        << setfill(' ') << setw(3) << address->getNumber() << "/"
        << setfill(' ') << setw(2) << address->getBloc() << "/"
        << setfill(' ') << setw(3) << address->getApartment() << " "
        << left << setfill(' ') << setw(9) << phone;
}

void Person::print() {
    printPerson();
    cout << endl;
}

Person *getPerson() {
    int year, month, day, number, apartment;
    char *lastName, *firstName, *street, *phone, block;
    cout << "Enter first name: ";
    firstName = getString();
    cout << "Enter last name: ";
    lastName = getString();
    do {
        cout << "Enter birth day year (1900-2010): ";
        cin >> year;
    } while ( year < 1900 || year > 2010 );
    do {
        cout << "Enter birth day month (1-12): ";
        cin >> month;
    } while ( month < 1 || month > 12 );
    do {
        cout << "Enter birth day day (depending on month):  ";
        cin >> day;
    } while ( day < 1 || day > months[month] + ( month == 2 && year % 4 == 0 && year % 100 != 0 ));
    Date *d = new Date(year,month,day);
    cout << "Enter street: ";
    street = getString();
    do {
        cout << "Enter house number (positive integer): ";
        cin >> number;
    } while ( number < 1 );
    do {
        cout << "Enter block (one character): ";
        cin >> block;
    } while ( block < 1 );
    do {
        cout << "Enter apartment number (positive integer): ";
        cin >> apartment;
    } while ( apartment < 1 );
    Address *ad = new Address(street,number,block,apartment);
    cout << "Enter phone: ";
    phone = getString();
    return new Person(lastName,firstName,d,ad,phone);
}