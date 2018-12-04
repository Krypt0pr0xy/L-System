#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

#pragma warning (disable:4996)

#define PI 3.14159265





void main(void)
{
	float winkel = 60.0;
	char startstring[80];
	char suchzeichen;
	char ersetzstring[80];

	frage_startstring(startstring, 80);
	suchzeichen = frage_suchzeichen();
	frage_erstzstring(ersetzstring, 80);
	char buffer[700000] = "F--F--F";

	file_erstellen("F+F--F+F", buffer,60, 'F' );



	char *zeiger; // Zeiger definieren

	zeiger = &startstring[0]; // Zeiger Zeiger auf erstes zeichen setzten

	// Schleife ueber startstring

	while (*zeiger != '\0')
	{
		if (*zeiger == suchzeichen)
		{
			// ersetzstring ausgeben
			printf("%s", ersetzstring);
		}
		else
		{
			//Zeichenausgeben
			printf("%c", *zeiger);
		}
		zeiger++;
	}


	system("start L-System.html");
}