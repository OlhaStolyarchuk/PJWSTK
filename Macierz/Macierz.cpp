#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <map>
#include <new>
//#define getchar getchar_unlocked
int main() {

	int negate = 0;
	register int c = getchar();
	int sizeOfTab = 0;
	for (; c>47 && c<58; c = getchar()) {
		sizeOfTab = (sizeOfTab << 1) + (sizeOfTab << 3) + c - '0';
	}
	fprintf(stdout, "readed: %d\n", sizeOfTab);


	if (c == ' ') c = getchar();
	int numbKA = 0;
	for (; c>47 && c<58; c = getchar()) {
		numbKA = (numbKA << 1) + (numbKA << 3) + c - '0';
	}
	fprintf(stdout, "readed: %d\n", numbKA);


	long long **sumTab = new long long*[sizeOfTab];
	for (int i = 0; i<sizeOfTab; i++)
	{
		sumTab[i] = new long long[sizeOfTab];
	}
	for (int row = 0; row<sizeOfTab; row++)
		for (int col = 0; col<sizeOfTab; col++)
		{
			if (c == ' ' || c == '\n') c = getchar();
			int numb = 0;
			if (c == '-') {
				negate = 1;
				c = getchar();
			}
			for (; c>47 && c<58; c = getchar()) {
				numb = (numb << 1) + (numb << 3) + c - '0';
			}
			if (negate)
				numb = -numb;
			fprintf(stdout, "readed to [%u, %u]: %d\n", row, col, numb);
			sumTab[row][col] = numb;
			if (row>0)
			{
				sumTab[row][col] += sumTab[row - 1][col];
			}
			negate = 0;
		}



	for (int row = 0; row<sizeOfTab; row++)
	{
		for (int col = 0; col<(sizeOfTab - 1); col++)
		{
			sumTab[row][col + 1] += sumTab[row][col];
		}
	}

	for (int i = 0; i<numbKA; i++)
	{
		int rowFrom = 0;
		int columnFrom = 0;
		int rowTo = 0;
		int columnTo = 0;
		if (c == ' ' || c == '\n') c = getchar();
		for (; c>47 && c<58; c = getchar()) {
			rowFrom = (rowFrom << 1) + (rowFrom << 3) + c - '0';
		}
		c = getchar();
		for (; c>47 && c<58; c = getchar()) {
			columnFrom = (columnFrom << 1) + (columnFrom << 3) + c - '0';
		}
		c = getchar();
		for (; c>47 && c<58; c = getchar()) {
			rowTo = (rowTo << 1) + (rowTo << 3) + c - '0';
		}
		c = getchar();
		for (; c>47 && c<58; c = getchar()) {
			columnTo = (columnTo << 1) + (columnTo << 3) + c - '0';
		}

		long long sum = sumTab[rowTo][columnTo];
		if (rowFrom > 0)
			sum -= sumTab[rowFrom - 1][columnTo];
		if (columnFrom > 0)
			sum -= sumTab[rowTo][columnFrom - 1];
		if (rowFrom > 0 && columnFrom > 0)
			sum += sumTab[rowFrom - 1][columnFrom - 1];
		/*
		for(i=toprow; i<=bottomrow; i++)
		{
		for(j=leftcol; j<=rightcol; j++)
		{
		sum+=matrix[i][j];
		}
		}
		*/
		fprintf(stdout, "%d\n", sum);
	}

	//    std::map<long, long> map;
	//    long maxRep = 0;
	//
	//    for (int nTab = 0; nTab < numbKA; nTab++) {

	//
	//    long tmp = sumTab[rowTo + 1][columnTo + 1] - sumTab[rowFrom][columnTo + 1]
	//    - sumTab[rowTo + 1][columnFrom] + sumTab[rowFrom][columnFrom];
	//    if (map.erase(tmp)) {
	//    long newVal = map[tmp] + 1;
	//    map.emplace(tmp, newVal);
	//    if (maxRep < newVal)
	//    maxRep = newVal;
	//    }
	//    else {
	//    map.emplace(tmp, (long)1);
	//    res3 += tmp;
	//    }
	//    if (maxRep == 0)
	//    maxRep = 1;
	//    for (long long i : map.values()) {
	//    if (i == maxRep)
	//    res2++;
	//    }
	//
	//    res1 = map.size();
	//    if (numbKA != 0)
	//    res3 = res3 / numbKA;
	//    std::cout << res1 << " " << res2 <<" " << res3;
	//    }
	system("pause");
}