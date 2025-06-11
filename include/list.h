#include "person.h"

#ifndef _LIST_H
#define _LIST_H

class ListItem {
private:
    Person *p;
    ListItem *next;
public:
    ListItem() {}
    ListItem(Person *p, ListItem *next);
    Person *getItemData();
    ListItem *getNextItem();
    ~ListItem();
    friend class List;
};

/**
 * This data structure is used to store persons data.
 * each person can be a doctor, nurse, inpatient or outpatient.
 */
class List {
private:
    ListItem *el;
    int length;
public:
    List();
    List(ListItem *el);
    ~List();
    ListItem *getElement();
    Person *getPerson();
    ListItem *getNext();
    int getLength();
    void operator += (Person *&p);
    void clean();
    void promoteNurse(List *&l);
    void admitOutpatient(List *&l);
    void dischargeInpatient(List *&l);
    void print();
    void printToFile();
};

#endif