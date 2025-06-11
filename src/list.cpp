#include <iostream>
#include <iomanip>
#include "list.h"
#include "global.h"
using namespace std;

ListItem::ListItem(Person *p, ListItem *next) {
    this->p = p;
    this->next = next;
}

ListItem::~ListItem() {
    delete p;
    p = 0;
    next = 0;
}

Person *ListItem::getItemData() {
    return p;
}

ListItem *ListItem::getNextItem() {
    return next;
}

List::List() {
    this->el = 0;
    this->length = 0;
}

List::List(ListItem *el) {
    this->el = el;
}

List::~List() {
    ListItem *del;
    while (el) {
        del = el;
        el = el->next;
        delete del;
    }
    el = 0;
}

ListItem *List::getElement() {
    return el;
}

Person *List::getPerson() {
    return el->p;
}

ListItem *List::getNext() {
    return el->next;
}

int List::getLength() {
    return length;
}

void List::operator += (Person *&person) {
    el = new ListItem(person,el);
    length++;
}

void List::print() {
    int i = 0;
    ListItem *head = el;
    if (head == 0)
        cout << "List este vida !\n";
    else{
        cout << "  " << left << setfill(' ') << setw(9) << "First Name" << " "
            << left << setfill(' ') << setw(9) << "Last Name" << " "
            << "day.month.year" << " "
            << setfill(' ') << setw(9) << "Street" << " "
            << "nr/bloc/apt" << " "
            << setfill(' ') << setw(9) << "Phone" << " "
            << setfill(' ') << setw(9) << "Spec/Diag" << " "
            << "Ward/Room" << endl;
        while (head) {
            i++;
            cout << i << ".";
            head->p->print();
            head = head->next;
        }
    }
}

void List::printToFile() {
    ListItem *head = el;
    while (head) {
        head->p->printToFile();
        head = head->next;
    }
}

void List::clean() {
    ListItem *del, *head = el;
    int i, poz;
    if (el == 0)
        cout << "The list is empty !\n";
    else{
        do{
            cout << "Enter person number (positive integer) ";
            cin >> poz;
        } while (poz < 1);
        if (poz == 1) {
            del = el;
            el = el->next;
            head = el;
            delete del;
            length--;
        }else{
            for (i = 2; (i < poz) && (el->next != 0); i++)
                el = el->next;
            if (el->next == 0)
                cout << "Invalid number !\n";
            else{
                del = el->next;
                el->next = del->next;
                delete del;
                length--;
            }
        }
        el = head;
    }
}

void List::promoteNurse(List *&l) {
    Person *aux;
    ListItem *del, *head = el;
    int i, poz, cab;
    if (el == 0)
        cout << "The list is empty !\n";
    else{
        do{
            cout << "Enter nurse number (positive integer): ";
            cin >> poz;
        } while (poz < 1);
        if (poz == 1) {
            del = el;
            el = el->next;
            head = el;
            do {
            cout << "Enter room number (positive integer): ";
                cin >> cab;
            } while (cab < 1);
            aux = new Doctor((Nurse *)del->p,cab);
            (*l) += aux;
            length--;
        }else{
            for (i = 2; (i < poz) && (el->next != 0); i++)
                el = el->next;
            if (el->next == 0)
                cout << "Invalid number !\n";
            else{
                del = el->next;
                el->next = del->next;
                do {
                cout << "Enter room number (positive integer): ";
                    cin >> cab;
                } while (cab < 1);
                aux = new Doctor((Nurse *)del->p,cab);
                (*l) += aux;
                length--;
            }
        }
        el = head;
    }
}

void List::admitOutpatient(List *&l) {
    Person *aux;
    ListItem *del, *head = el;
    int i, poz, ward;
    if (el == 0)
        cout << "The list is empty !\n";
    else{
        do{
            cout << "Enter outpatient number (positive integer): ";
            cin >> poz;
        } while (poz < 1);
        if (poz == 1) {
            del = el;
            el = el->next;
            head = el;
            do {
                cout << "Enter ward number (positive integer): ";
                cin >> ward;
            } while (ward < 1);
            aux = new Inpatient ((Outpatient *)del->p,ward);
            (*l) += aux;
            length--;
        }else{
            for (i = 2; (i < poz) && (el->next != 0); i++)
                el = el->next;
            if (el->next == 0)
                cout << "Invalid number !\n";
            else{
                del = el->next;
                el->next = del->next;
                do {
                    cout << "Enter ward number (positive integer): ";
                    cin >> ward;
                } while (ward < 1);
                aux = new Inpatient ((Outpatient *)del->p,ward);
                (*l) += aux;
                length--;
            }
        }
        el = head;
    }
}

void List::dischargeInpatient(List *&l) {
    Person *aux;
    ListItem *del, *head = el;
    int i, poz;
    if (el == 0)
        cout << "The list is empty !\n";
    else{
        do{
            cout << "Enter outpatient number (positive integer): ";
            cin >> poz;
        } while (poz < 1);
        if (poz == 1) {
            del = el;
            el = el->next;
            head = el;
            aux = new Outpatient(del->p, ((Inpatient *)del->p)->getDiagnosis());
            (*l) += aux;
        }else{
            for (i = 2; (i < poz) && (el->next != 0); i++)
                el = el->next;
            if (el->next == 0)
                cout << "Invalid number !\n";
            else{
                del = el->next;
                el->next = del->next;
                aux = new Outpatient (del->p, ((Inpatient *)del->p)->getDiagnosis());
                (*l) += aux;
                length--;
            }
        }
        el = head;
    }
}