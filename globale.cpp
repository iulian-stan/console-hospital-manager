#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
#include "globale.h"

void pauza() { 
	cout << "\n\n  Apasati o tasta  .... ";
	_getch();
}

void clrscr() {
	system("cls");
}

char *getString() {
	char buffer[15];
	char *s=0;
	int a;
	cin >> buffer;
	a=strlen(buffer)+1;
	s = new char[a];
	strcpy(s,buffer);
	return s;
}