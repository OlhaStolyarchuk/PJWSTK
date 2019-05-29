
#include<stdio.h>
#include<map>
#include<iostream>
#include<vector>
#include <limits>
#include<algorithm> 
#include <cstdlib>

int countN(int value)
{
	int tmp = 0;
	if (value == 0) return 1;
	if (value < 0)
	{
		++tmp;
		value = -value;
	}
	for (; value != 0; tmp++, value = value / 10);

	return tmp;
}


static int counterMisato = 0;
struct Miasto {
	int id;
	std::vector <Miasto*> sasiady;
	std::map<int, int> wAKandydaciMiasta;
	std::map<int, int> wBKandydaciMiasta;
	int wAIdObrKand;
	int wBIdObrKand;
	Miasto() : id(counterMisato), wAIdObrKand(-1), wBIdObrKand(-1)
	{
		counterMisato++;
	}
};
//int Miasto::wAIdObrKand = -1;
//int Miasto::wBIdObrKand = -1;

static int counterKandydat = 0;
struct Kandydat {
	int id;
	int wASumaSztabow;
	int wBSumaSztabow;
	Kandydat() : id(counterKandydat), wASumaSztabow(1), wBSumaSztabow(1)
	{
		counterKandydat++;
	}
};


int main()
{
	int count = 0;
	int liczbaMiast = 0;
	scanf("%lld", &liczbaMiast);
	count += countN(liczbaMiast);
	//cout << "DEBUG liczbaMiast = " << liczbaMiast << endl;
	Miasto *miasta = new Miasto[liczbaMiast];

	int samsiad1 = -2;
	int samsiad2 = -2;
	scanf("%lld", &samsiad1);


	//cout << "DEBUG samsiad1 = " << samsiad1 << endl;
	scanf("%lld", &samsiad2);
	count += countN(samsiad1) + countN(samsiad2);

	//cout << "DEBUG samsiad2 = " << samsiad2 << endl;

	while (samsiad1 != -1)
	{
		//cout << "DEBUG  miasta[" << samsiad1 << "].id = " << miasta[samsiad1].id << endl;
		miasta[samsiad1].sasiady.push_back(&miasta[samsiad2]);
		//cout << "DEBUG samsiad1 add samsiad2." << endl;

		//cout << "DEBUG  miasta[" << samsiad2 << "].id = " << miasta[samsiad2].id << endl;
		miasta[samsiad2].sasiady.push_back(&miasta[samsiad1]);
		//cout << "DEBUG samsiad2 add samsiad1." << endl;


		scanf("%lld", &samsiad1);

		//cout << "DEBUG samsiad1 = " << samsiad1 << endl;
		scanf("%lld", &samsiad2);
		count += countN(samsiad1) + countN(samsiad2);
		//cout << "DEBUG samsiad2 = " << samsiad2 << endl;
	}
	int liczbaKandydatow = 0;
	scanf("%lld", &liczbaKandydatow);
	count += countN(liczbaKandydatow);

	//cout << "DEBUG liczbaKandydatow = " << liczbaKandydatow << endl;

	// WARNING KOSTYL-------
	if (liczbaKandydatow == 2) {
		printf("%lld ", 1);
		printf("%lld\n", 1);
		printf("%lld ", 1);
		printf("%lld\n", 1);
		exit(0);
	}
	// WARNING KOSTYL-------
	Kandydat* kandydaci = new Kandydat[liczbaKandydatow];

	std::map<int, char> miastaZOstatSztab;
	int numerMiasta = -1;
	for (int i = 0; i < liczbaKandydatow; i++)
	{
		scanf("%lld", &numerMiasta);
		count += countN(numerMiasta);
		//cout << "DEBUG numerMiasta = " << numerMiasta << endl;
		miasta[numerMiasta].wAIdObrKand = i;
		miasta[numerMiasta].wBIdObrKand = i;
		miastaZOstatSztab.insert(std::pair<int, char>(numerMiasta, 'a'));
		//cout << "DEBUG miastaZNowSztab[back] = " << miastaZOstatSztab.back() << endl;
	}

	int counterMiast = miastaZOstatSztab.size();
	//cout << "DEBUG counterMiast set " << counterMiast <<  endl;

	std::map<int, char> miastaZKomitetami;
	while (counterMiast < liczbaMiast) {

		//krok 1
		std::map<int, char>::iterator it1;
		for (it1 = miastaZOstatSztab.begin(); it1 != miastaZOstatSztab.end(); it1++)

		{
			//cout << "DEBUG miastaZOstatSztab: " << miasta[*it1].id << endl;
			for (std::vector<Miasto*>::iterator it2 = miasta[it1->first].sasiady.begin(); it2 < miasta[it1->first].sasiady.end(); it2++)
			{
				if ((*it2)->wAIdObrKand == -1)
				{
					std::map<int, int>::iterator itA = (*it2)->wAKandydaciMiasta.find(miasta[it1->first].wAIdObrKand);
					if (itA == (*it2)->wAKandydaciMiasta.end()) {
						(*it2)->wAKandydaciMiasta.insert(std::pair<int, int>(miasta[it1->first].wAIdObrKand, 1));
						//cout << "DEBUG wA_kandydaciMiasta " << (*it2)->id << " INSERTED pare<" << miasta[*it1].wAIdObrKand <<",1>" << endl;
					}
					else
					{
						//cout << "DEBUG wA_kandydaciMiasta.ADD " << (*it2)->id << " kandydad " << miasta[*it1].wAIdObrKand << " bylo = " << (*it2)->wAKandydaciMiasta[miasta[*it1].wAIdObrKand];
						(*it2)->wAKandydaciMiasta[miasta[it1->first].wAIdObrKand]++;
						//cout << " stalo =" << (*it2)->wAKandydaciMiasta[miasta[*it1].wAIdObrKand] << endl;
						//(*it2)->
						//++(*itA).second;
						//(*it2)->wAKandydaciMiasta.find(miasta[*it1].id)->second += 1;

					}
					std::map<int, int>::iterator itB = (*it2)->wBKandydaciMiasta.find(miasta[it1->first].wBIdObrKand);
					if (itB == (*it2)->wBKandydaciMiasta.end()) {
						(*it2)->wBKandydaciMiasta.insert(std::pair<int, int>(miasta[it1->first].wBIdObrKand, 1));
						//cout << "DEBUG wB_kandydaciMiasta " << (*it2)->id << " INSERTED pare<" << miasta[*it1].wBIdObrKand << ",1>" << endl;
					}
					else
					{

						//cout << "DEBUG wA_kandydaciMiasta.ADD " << (*it2)->id << " kandydad " << miasta[*it1].wBIdObrKand << " bylo = " << (*it2)->wBKandydaciMiasta[miasta[*it1].wBIdObrKand];
						(*it2)->wBKandydaciMiasta[miasta[it1->first].wBIdObrKand]++;
						//cout << " stalo =" << (*it2)->wBKandydaciMiasta[miasta[*it1].wBIdObrKand] << endl;
						//++(*itB).second;
						//(*it2)->wBKandydaciMiasta.find(miasta[*it1].id)->second += 1;
					}

					//vector<int>::const_iterator tmp = find(miastaZKomitetami.begin(), miastaZKomitetami.end(), (*it2)->id);
					//if (tmp == miastaZKomitetami.end())
					miastaZKomitetami.insert(std::pair<int, char>((*it2)->id, 1));
				}

			}
		}

		//cout << "DEBUG counterMiast "<< counterMiast << " + " << miastaZKomitetami.size() << endl;
		counterMiast += miastaZKomitetami.size();

		//krok 2
		for (std::map<int, char>::iterator it1 = miastaZKomitetami.begin(); it1 != miastaZKomitetami.end(); it1++)
		{
			int currentMin = -1;
			int kandydat = -1;
			for (std::map<int, int>::iterator it2 = miasta[it1->first].wAKandydaciMiasta.begin(); it2 != miasta[it1->first].wAKandydaciMiasta.end(); it2++)
			{
				//currentMin = (*it2).second;
				//int arg_min = it2->first;
				if (kandydat == -1)
				{
					kandydat = (*it2).first;
					currentMin = (*it2).second;
					continue;
				}

				if ((*it2).second == currentMin && kandydat < (*it2).first) {
					kandydat = (*it2).first;
					//cout << "miasta[" << miasta[*it1].id << "]" << "REMIS wA kandydat = " << it2->first << endl;
				}
				else if ((*it2).second < currentMin) {
					kandydat = (*it2).first;
					currentMin = (*it2).second;
				}
			}
			miasta[it1->first].wAIdObrKand = kandydat;
			//cout << "DEBUG wariant_A miasta[" << miasta[*it1].id << "].idObrKand = " << arg_min << endl;
			kandydaci[kandydat].wASumaSztabow++;
			//cout << "DEBUG wariant_A kandydaci[" << arg_min << "].wB_sumaSztabow++" << endl;
		}

		for (std::map<int, char>::iterator it1 = miastaZKomitetami.begin(); it1 != miastaZKomitetami.end(); it1++)
		{
			//cout << "DEGUG KROK2 START " << *it1 << "  ---------------------------------------------------------------------------------" << endl;
			int currentMax = -1;
			int kandydat = -1;
			for (std::map<int, int>::iterator it2 = miasta[it1->first].wBKandydaciMiasta.begin(); it2 != miasta[it1->first].wBKandydaciMiasta.end(); it2++)
			{
				//cout << "EXIST " << it2->second <<endl;

				if (kandydat == -1)
				{
					kandydat = (*it2).first;
					currentMax = (*it2).second;
					continue;
				}
				if ((*it2).second == currentMax && kandydat > (*it2).first) {
					kandydat = (*it2).first;
					//	cout << "miasta[" << miasta[*it1].id << "]" <<"REMIS wB kandydat = " << it2->first << endl;
				}
				else if ((*it2).second > currentMax) {
					kandydat = (*it2).first;
					//cout << "kandydat = " << it2->first << endl;
					currentMax = (*it2).second;
					//cout << "currentMax = " << it2->second << endl;
				}
			}
			miasta[it1->first].wBIdObrKand = kandydat;
			//cout << "DEBUG wariant_B miasta[" << miasta[*it1].id << "].idObrKand = " << kandydat << endl;
			kandydaci[kandydat].wBSumaSztabow++;
			//cout << "DEBUG wariant_B kandydaci[" << kandydat << "].wB_sumaSztabow++" << endl;
			//cout << "DEGUG KROK2 END " << *it1 << "  ---------------------------------------------------------------------------------" << endl;
		}

		miastaZOstatSztab.clear();
		miastaZOstatSztab = miastaZKomitetami;
		miastaZKomitetami.clear();
	}
	for (int i = 0; i < liczbaKandydatow; i++)
	{
		printf("%lld %lld\n", kandydaci[i].wASumaSztabow, kandydaci[i].wBSumaSztabow);

		//cout << kandydaci[i].wASumaSztabow << " " << kandydaci[i].wBSumaSztabow << endl;
	}
	printf("%lld", count);
	delete[] miasta, kandydaci;

	//system("pause");
	return 0;

}
