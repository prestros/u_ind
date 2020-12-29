// Programm zur Berechnung der Selbstinduktionsspannung bei linearem Stromanstieg
// Autor: Fabian Prestros
// Datum: 29.12.2020
#include <stdio.h>

double einlesen(char koef[1])
{
	int chk = 0;
	double zahl = 0;

	do													// In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde
	{
		printf("%s = ", koef);
		chk = scanf_s("%le", &zahl);
		while (getchar() != '\n');						// Tastaturpuffer leeren.
		if (chk == 0)									// Fehlermeldung, wenn scanf_s meldet, dass keine Ganze Zahl eingegeben wurde
			printf("Bite geben Sie eine Zahl ein!\n");
	} while (chk == 0);									// Schleifendurchlauf, bis kein Fehler mehr vorliegt.

	return zahl;
}

double induktionsspannungsberechnung(double L, double i, double t)
{
	double u;

	u = L * (i / t);									// Selbstinduktionsspannung u = L * di/dt
	return u;
}

int main()
{
	double L = 0;
	double i = 0;
	double t = 0;
	double u = 0;

	L = einlesen("L");
	i = einlesen("i");
	t = einlesen("t");
	
	u = induktionsspannungsberechnung(L, i, t);

	printf("u = %le V\n", u);							// Ausgabe der Selbstinduktionsspannung
}