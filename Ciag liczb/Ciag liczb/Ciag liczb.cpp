#include <stdio.h>
#include<iostream>
#include <stdlib.h>

class Number
{
public:
	unsigned long long wrt;
	Number* n;

public:
	Number(unsigned long long zn)
	{
		wrt = zn;
		n = NULL;
	}

};


int main()
{
	long long count = 0;
	unsigned long long int w;

	w = getchar();
	count++;
	if (!feof(stdin))
	{
		unsigned long long el = 0;
		unsigned long long int tmp;
		std::cin >> tmp;
		count++;
		Number* p = new Number(tmp);
		if (tmp == NULL)
			std::cout << "-1";
		el++;
		Number* current = p;
		while (std::cin >> tmp)
		{
			current->n = new Number(tmp);
			current = current->n;
			el++;
			count++;

		}

		current->n = p;
		current = p;
		for (int i = 0; i<w; i++)
		{
			if (el == 0)
				break;
			unsigned long long value;
			if (current->wrt & 1)
			{
				value = current->wrt;
				Number* newC = new Number(value - 1);
				newC->n = current->n;
				current->n = newC;
				el++;
			}
			else
			{
				value = current->n->wrt;
				Number* toDelete = current->n;
				current->n = toDelete->n;
				delete toDelete;
				el--;
			}
			if (el > 0)
			{
				value = value % el;
				for (int ii = 0; ii<value; ii++)
				{
					current = current->n;
				}
			}
		}
		if (el > 0)
		{
			p = current;

			current = current->n;
					while (p != current)
				{
			fprintf(stdout, " %d", current->wrt);

			current = current->n;
					}
		}
	}
	fprintf(stdout, "\n%d", count);

	system("pause");
	return 0;
}

