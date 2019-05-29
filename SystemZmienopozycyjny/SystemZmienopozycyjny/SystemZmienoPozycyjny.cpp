#include <stdio.h>
//#include<iostream>
#include <stdlib.h>
#define getchar getchar_unlocked
//void scan_integer(long long* num);
//long long licznikLiczb(long long number);

	void scan_integer(long long* num)
	{
		register int wrt = getchar();
		int tmp = 0;
		for (; ((wrt<=49 || wrt>=58)); wrt = getchar());

		for (; wrt>=48 && wrt<=59; wrt = getchar()) {
			tmp = (tmp << 1) + (tmp << 3) + wrt - 48;
		}
		*num = tmp;
	}
long long licznikLiczb(long long number) {
	long long licznik = 0;
	if (number == 0)
		return 1;
	while (number != 0) {
		number /= 10;
		++licznik;
	}
	return licznik;
}
struct Mystruct {
	long long liczby = 0;
	long long licznik = 0;
	long long dlugosc = 0;
	long long sumaLiczb = 0;
};
int main() {
	Mystruct *str;
	

	//scanf_s("%lli %lli", &count, &base);
	scan_integer(&str->licznik);
	scan_integer(&str->liczby);
	str.dlugosc += licznikLiczb(licznik);
	dlugosc += licznikLiczb(liczby);
	long long liczba;
	//scanf_s("%d", &number);
	//numlen += countnum(number);
	//sum += number;
	while (licznik--) {
		scan_integer(&liczba);
		sumaLiczb += liczba;
		dlugosc += licznikLiczb(liczba);
	}
	long long resultat = 1;
	if (liczby == 1) {
		resultat = sumaLiczb;
	}
	else {
		while (sumaLiczb >= liczby) {
			sumaLiczb /= liczby;
			resultat++;
		}
	}


	fprintf(stdout, "%lli\n%lli", resultat, dlugosc);
	//int test;
	//scanf_s("%d", &test);
	return 0;




}