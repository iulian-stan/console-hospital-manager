#include <iostream>
#include <conio.h>
#include <string.h>
#include "global.h"
#include "menu.h"
using namespace std;

/****** MenuItem class methods ******/

MenuItem::MenuItem(char *name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->parent = NULL;
}

void MenuItem::printShortTitle() {
    if (parent != NULL) {
        parent->printShortTitle();
        cout << " -> " << name;
    } else {
        cout << name;
    }
}

void MenuItem::printTitle() {
    printShortTitle();
    cout << ":" << endl << endl;
}

char *MenuItem::getName() {
    return this->name;
}

MenuItem::~MenuItem() {
    cout << "remove item : " << name << endl;
    delete []name;
}

/****** Action class methods ******/

Action::Action(char *name) : MenuItem(name) {}

void Action::execute() {
    clrscr();
    this->printTitle();
    this->executeAction();
}

/****** Menu class methods ******/

Menu::Menu(char *name) : MenuItem(name) {
    this->items = new MenuItem*[maxSize];
    this->size = 0;
}

Menu::~Menu() {
    for (int i=0; i<size; i++) {
        delete items[i];
    }
    delete []items;
}

void Menu::addItem(MenuItem *element) {
    size++;
    items[size - 1] = element;
    element->parent = this;
}

void Menu::print() {
    for (int i = 0; i < this->size; i++) {
        cout << "\t" << i + 1 << " - " << items[i]->getName();
        cout << endl <<endl;
    }
    cout << "\t" << "ESC sau 0 - Quit" << endl << endl;
}

int Menu::readCommandIndex() {
    while (1) {
        char ch;

        cout << "Enter a command index : ";
        ch = _getch();
        cout << endl;
        if (ch > '0' && (ch - '0') <= this->size) {
            /** valid command index */
            return ch - '1';
        } else  if (ch == '0' || ch == 0x1B) {
            /** 0 or ESC - quit the menu */
            return -1;
        } else {
            /** invalid input */
            cout << "Invalid input : " << ch
                << " Valid options '0' - '" << size << "'"
                << endl << endl;
        }
    }
}

void Menu::execute() {
    for (;;) {
        int commandIndex;

        clrscr();
        printTitle();
        print();
        commandIndex = readCommandIndex();
        if (commandIndex >= 0 && commandIndex < size) {
            items[commandIndex]->execute();
        } else {
            /** quit */
            return;
        }
    }
}
