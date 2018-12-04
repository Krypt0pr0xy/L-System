#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

#pragma warning (disable:4996)
#define PI 3.14159265





void main(void)
{
	int wiederholung = 6;

	char startstring[700000] = { 0 };
	frage_startstring(startstring);

	int w = 6;


	char erstzstring[80] = { 0 };
	frage_erstzstring(erstzstring);


	
	file_erstellen(erstzstring, startstring, frage_winkel(), frage_suchzeichen(), wiederholung);


	system("start L-System.html");
}