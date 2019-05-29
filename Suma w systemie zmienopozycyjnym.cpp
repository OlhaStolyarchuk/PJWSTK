#include <stdio.h>
#include<iostream>
#include <stdlib.h>
//#define getchar getchar_unlocked


inline long long licznikLiczb(unsigned long long number) {
register long long licznik = 0;
	if (number == 0)
		return 1;
	while (number!= 0) {
		number /= 10;
		++licznik;
	}
	return licznik;
}

inline void scan_integer( long long* num)
{
	register int wrt = getchar_unlocked();
	register int tmp = 0;
	for (; ((wrt<=47 || wrt>=58)); wrt = getchar_unlocked());

	for (; wrt>=48 && wrt<=57; wrt = getchar_unlocked()) {
		tmp = (tmp << 1) + (tmp << 3) + wrt - 48;
	}
	*num = tmp;
}


int main() {

register long long liczby = 0;
register long long licznik = 0;
register long long dlugosc = 0;
register long long sumaLiczb = 0;

;
	scan_integer(&licznik);
	scan_integer(&liczby);
	dlugosc += licznikLiczb(licznik);
	dlugosc += licznikLiczb(liczby);
    long long liczba;
	while (licznik --) {
	scan_integer(&liczba);
	sumaLiczb += liczba;
	dlugosc += licznikLiczb(liczba);
	}
register long long resultat = 1;
	if (liczby == 1) {
		resultat = sumaLiczb;
	}
	else {
		while (sumaLiczb>=liczby) {
			sumaLiczb /= liczby;
			resultat++;
		}
	}
  fprintf(stdout, "%lli\n%lli", resultat, dlugosc);
return 0;
}





