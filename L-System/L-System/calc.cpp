#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

#pragma warning (disable:4996)

#define PI 3.14159265

void file_erstellen(const char *ersetztstring,  char *string, int winkelerhöhen, char suchzeichen ,int w)
{
	int winkel = 0, i = 0, lange = 3;
	double val = 0;
	//int winkelerhöhen = 60;
	double x = 1000, y = 8000;
	char x1[100];
	char y1[100];
	//char string[100000] = { "F--F--F" };
	char zwischenspeicher[100000] = { 0 };
	//char ersetztstring[] = { "F+F--F+F" };

	int i1 = 0, i2 = 0, i3 = 0, i4 = 0;

	val = PI / 180;
	FILE * fp;

	for (i3 = 0; i3 < w; i3++)
	{
		for (i = 0; string[i] != 0; i++)
		{
			if (string[i] == suchzeichen)
			{
				i2 = -1;
				do
				{
					i2++;
					zwischenspeicher[i2] = string[i + i2];
				} while (string[i + i2] != 0);
				//string überschreiben
				for (i1 = 0; i1 < 9; i1++)
				{
					string[i + i1] = ersetztstring[i1];
				}
				i += 7;
				//hinterteil hinzufügen
				for (i1 = 0; zwischenspeicher[i1] != 0; i1++)
				{
					string[i + i1] = zwischenspeicher[i1];
				}
			}
		}
	}


	while (i < 4)
	{
		i++;
	}
	i = 0;
	fp = fopen("L-System.html", "w");

	fputs("<!DOCTYPE html><html><body> <svg height = \"11000\" width =\"10000\"><polyline points = \"", fp);

	fputs("1000,8000 ", fp);

	while (string[i] != 0)
	{
		switch (string[i])
		{
		case '+':
			winkel += winkelerhöhen;
			break;
		case '-':
			winkel -= winkelerhöhen;
			break;

		default:
			break;
		}
		if (winkel < 0)
		{
			winkel += 360;
		}
		if (winkel > 360)
		{
			winkel -= 360;
		}

		if (string[i] == suchzeichen)
		{
			switch (winkel)
			{
			case 0:
				x += lange;
				snprintf(x1, 100, "%lf", x);
				snprintf(y1, 100, "%lf", y);
				fputs(x1, fp);
				fputs(",", fp);
				fputs(y1, fp);
				fputs(" ", fp);
				break;
			case 90:
				y += lange;
				snprintf(x1, 100, "%lf", x);
				snprintf(y1, 100, "%lf", y);
				fputs(x1, fp);
				fputs(",", fp);
				fputs(y1, fp);
				fputs(" ", fp);
				break;
			case 180:
				x -= lange;
				snprintf(x1, 100, "%lf", x);
				snprintf(y1, 100, "%lf", y);
				fputs(x1, fp);
				fputs(",", fp);
				fputs(y1, fp);
				fputs(" ", fp);
				break;
			case 270:
				y -= lange;
				snprintf(x1, 100, "%lf", x);
				snprintf(y1, 100, "%lf", y);
				fputs(x1, fp);
				fputs(",", fp);
				fputs(y1, fp);
				fputs(" ", fp);
				break;

			default:
				if (winkel < 90)
				{
					x += cos(winkel*val)*lange;
					y += sin(winkel*val)*lange;
				}
				if (winkel > 90 && winkel < 180)
				{
					x += cos(winkel*val)*lange;
					y += sin(winkel*val)*lange;
				}
				if (winkel > 180 && winkel < 270)
				{
					x += cos(winkel*val)*lange;
					y += sin(winkel*val)*lange;
				}
				if (winkel > 270)
				{
					x += cos(winkel*val)*lange;
					y += sin(winkel*val)*lange;
				}
				snprintf(x1, 100, "%lf", x);
				snprintf(y1, 100, "%lf", y);
				fputs(x1, fp);
				fputs(",", fp);
				fputs(y1, fp);
				fputs(" ", fp);
				break;
			}
		}
		i++;
	}
	fputs("\"style = \"fill:none;stroke:black;stroke-width:3\" / >Sorry, your browser does not support inline SVG.</svg></body></html>", fp);

	fclose(fp);
}



void frage_startstring(char *text)
{
	char temp[80] = { 0 };
	int i = 0;
	printf("Start String Eingeben (z.b:F--F--F):");
	fgets(temp, 80, stdin);
	printf("\n");

	for (i = 0; temp[i] != 0; i++)
	{
		*text = temp[i];
		text++;
	}

}

char frage_suchzeichen()
{
	char temp = 0;
	printf("Suchzeichen Eingeben:");
	scanf("%c", &temp);
	printf("\n");
	return temp;
}

void frage_erstzstring(char *text)
{
	char temp[80] = { 0 };
	int i = 0;
	printf("Ersetzstring String Eingeben (z.b:F+F--F+F):");
	fgets(temp, 80, stdin);
	printf("\n");

	for (i = 0; temp[i] != 0; i++)
	{
		*text = temp[i];
		text++;
	}

}

float frage_winkel()
{
	float temp = 0;
	printf("Winkel eingeben(z.b 60.0):");
	scanf("%f", &temp);
	printf("\n");
	return temp;
}


