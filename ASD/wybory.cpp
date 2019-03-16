#include <iostream>
#include <vector>
#include <string>
#include<stdio.h>
//#define scanf_s scanf;
class Kandydat {
public:
	long long index;
	long long wariantA;
	long long wariantB;

	Kandydat(long long i) {
		index = i;
		wariantA = 0;
		wariantB = 0;
	}
};
class Spolecznosc {
public:
	long long index;
	std::vector<Spolecznosc*> sasiedzi;
	std::vector<Kandydat*> komitetyWyborczeA;
	std::vector<long long> praWyboryAtmp;
	std::vector<long long> praWyboryANumery;
	Kandydat* sztabWyborczyA;
	Kandydat* sztabToUpdateA;
	std::vector<Kandydat*> komitetyWyborczeB;
	std::vector<long long> praWyboryBtmp;
	std::vector<long long> praWyboryBNumery;
	Kandydat* sztabWyborczyB;
	Kandydat* sztabToUpdateB;

	Spolecznosc(long long i) {
		index = i;
		sztabWyborczyA = NULL;
		sztabWyborczyB = NULL;
		sztabToUpdateA = NULL;
		sztabToUpdateB = NULL;
	}

	void odwiedzSasiadowIZalozKomitetA() {
		if (sztabWyborczyA != NULL)
			for (int i = 0; i<sasiedzi.size(); i++)
				if (sasiedzi.at(i)->sztabWyborczyA == NULL)
					sasiedzi.at(i)->komitetyWyborczeA.push_back(sztabWyborczyA);
	}

	void odwiedzSasiadowIZalozKomitetB() {
		if (sztabWyborczyB != NULL)
			for (int i = 0; i<sasiedzi.size(); i++)
				if (sasiedzi.at(i)->sztabWyborczyB == NULL)
					sasiedzi.at(i)->komitetyWyborczeB.push_back(sztabWyborczyB);
	}
	void praWyboryA() {
		for (int i = 0; i<komitetyWyborczeA.size(); i++) {
			int liczbaKomitetowUSasiadow = 0;
			for (int j = 0; j<sasiedzi.size(); j++)
				if (sasiedzi.at(j)->sztabWyborczyA == komitetyWyborczeA.at(i))
					liczbaKomitetowUSasiadow++;
			praWyboryAtmp.push_back(liczbaKomitetowUSasiadow);
			praWyboryANumery.push_back(komitetyWyborczeA.at(i)->index);
		}
		int min = -1;
		int index = -1;

		for (int i = 0; i<praWyboryAtmp.size(); i++) {
			if (min == praWyboryAtmp.at(i) && praWyboryANumery.at(index) < praWyboryANumery.at(i))
				index = i;

			if (min > praWyboryAtmp.at(i) || min == -1) {
				min = praWyboryAtmp.at(i);
				index = i;
			}
		}

		if (index != -1)
			sztabToUpdateA = komitetyWyborczeA.at(index);
	}
	void praWyboryB() {
		for (int i = 0; i<komitetyWyborczeB.size(); i++) {
			int liczbaKomitetowUSasiadow = 0;
			for (int j = 0; j<sasiedzi.size(); j++)
				if (sasiedzi.at(j)->sztabWyborczyB == komitetyWyborczeB.at(i))
					liczbaKomitetowUSasiadow++;
			praWyboryBtmp.push_back(liczbaKomitetowUSasiadow);
			praWyboryBNumery.push_back(komitetyWyborczeB.at(i)->index);
		}

		int max = -1;
		int index = -1;

		for (int i = 0; i<praWyboryBtmp.size(); i++) {
			if (max == praWyboryBtmp.at(i) && praWyboryBNumery.at(index) > praWyboryBNumery.at(i))
				index = i;

			if (max < praWyboryBtmp.at(i) || max == -1) {
				max = praWyboryBtmp.at(i);
				index = i;
			}
		}

		if (index != -1)
			sztabToUpdateB = komitetyWyborczeB.at(index);
	}


};

int main()
{
	long long count = 0;
	std::vector<Kandydat*> kandydaci;
	std::vector<Spolecznosc*> spolecznosci;

	long long liczbaSpolecznosci;
	scanf("%lld", &liczbaSpolecznosci);
	if (liczbaSpolecznosci > 9) {
		count++;
	}
	if (liczbaSpolecznosci == -1) {
		count++;
	}
	count++;

	for (int i = 0; i<liczbaSpolecznosci; i++)
		spolecznosci.push_back(new Spolecznosc(i));
	
	long long s1;
	long long s2;

	scanf("%lld", &s1);
	count++;
	if (s1 > 9) {
		count++;
	}
	if (s1 ==-1) {
		count++;
	}
	scanf("%lld", &s2);
	count++;
	if (s2 > 9) {
		count++;
	}
	if (s2 == -1) {
		count++;
	}
	  while (s1 != -1 ) {
		spolecznosci.at(s1)->sasiedzi.push_back(spolecznosci.at(s2)); 
		spolecznosci.at(s2)->sasiedzi.push_back(spolecznosci.at(s1));
		scanf("%lld", &s1);
		count++;
		if (s1 > 9) {
			count++;
		}
		if (s1==-1) {
			count++;
		}
		scanf("%lld", &s2);
		count++;
		if (s2 > 9) {
			count++;
		}
		if (s2 ==-1) {
			count++;
		}
	}
	//count++;

	long long liczbaKandydatow;
	scanf("%lld", &liczbaKandydatow);
	count++;
	if (liczbaKandydatow > 9) {
		count++;
	}
	long long pozycjaStartowa;

	for (int i = 0; i<liczbaKandydatow; i++) {
		Kandydat *tmp = new Kandydat(i);
		kandydaci.push_back(tmp);
		
		//	count++;
		scanf("%lld", &pozycjaStartowa);
		count++;
		if (pozycjaStartowa > 9) {
			count++;
		}
	
		tmp->wariantA++;
		tmp->wariantB++;
		spolecznosci.at(pozycjaStartowa)->sztabWyborczyA = tmp;
		spolecznosci.at(pozycjaStartowa)->sztabWyborczyB = tmp;
		//count++;
	}

	for (int i = 0; i<liczbaSpolecznosci; i++) {
		spolecznosci.at(i)->odwiedzSasiadowIZalozKomitetA();
	//	count++;
		spolecznosci.at(i)->odwiedzSasiadowIZalozKomitetB();
		//count++;
	}

	bool czyWszystkieMajaSztaby = false;
	while (!czyWszystkieMajaSztaby) {
		czyWszystkieMajaSztaby = true;
		for (int i = 0; i<liczbaSpolecznosci; i++) {
			if (spolecznosci.at(i)->sztabWyborczyA == NULL) {
				czyWszystkieMajaSztaby = false;
				spolecznosci.at(i)->praWyboryA();
				spolecznosci.at(i)->praWyboryB();
			}
	}
		for (int i = 0; i<liczbaSpolecznosci; i++) {
			if (spolecznosci.at(i)->sztabWyborczyA == NULL && spolecznosci.at(i)->sztabToUpdateA != NULL) {
				spolecznosci.at(i)->sztabWyborczyA = spolecznosci.at(i)->sztabToUpdateA;
				spolecznosci.at(i)->sztabWyborczyA->wariantA++;
				spolecznosci.at(i)->sztabWyborczyB = spolecznosci.at(i)->sztabToUpdateB;
				spolecznosci.at(i)->sztabWyborczyB->wariantB++;
			}
			
		}
		for (int i = 0; i<liczbaSpolecznosci; i++) {
			spolecznosci.at(i)->odwiedzSasiadowIZalozKomitetA();
			spolecznosci.at(i)->odwiedzSasiadowIZalozKomitetB();
		}
	}   
		for (int i = 0; i < liczbaKandydatow; i++)
		printf("%lld %lld\n", kandydaci.at(i)->wariantA, kandydaci.at(i)->wariantB);
	    printf("%lld", count);
	//std::cout << kandydaci.at(i)->wariantA << " " << kandydaci.at(i)->wariantB << std::endl;
	//std::cout << count;
//	system("pause");
}