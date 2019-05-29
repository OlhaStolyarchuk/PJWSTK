#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <conio.h>

class Number
{
     public:
	unsigned long long int wrt;
	Number* n;
	Number(unsigned long long int zn)
	{
		wrt = zn;
		n = NULL;
	}
};
int main()
{
	long long int count = 0;
	unsigned long long int w;
    std::cin>>w;
	count++;
	if(!feof(stdin))
	{
		unsigned long long int el = 0;
		unsigned long long int tmp;
	    std::cin>>tmp;
		count++;
		Number* p = new Number(tmp);
	
		el++;

		Number*c = p;
		 unsigned char znak;
    int kod
   znak = getch();
        kod= static_cast < int >( znak );
		while (tmp!=13)
		{
		c->n = new Number(tmp);
		c= c->n;
		el++;
		count++;
		}
        c->n = p;
		c = p;
		int i =0;
		while(i<w)
		{
			if (el == 0)
			break;
			unsigned long long int v;
			if (c->wrt & 1)
			{
			v =c->wrt;
			Number* newN = new Number(v - 1);
			newN->n = c->n;
			c->n = newN;
			el++;
			}
			else
			{
			v = c->n->wrt;
			Number* d = c->n;
			c->n = d->n;
			delete d;
			el--;
			}
		if (el > 0)
			{
			v = v % el;
			int j =0;
			while(j<v)
			{
			c = c->n;
			j++;
		}
			}
		i++;
		}
		if (el > 0)
		{
		p = c;
		fprintf(stdout, "%d", c->wrt);
     	c =c->n;
		while (p !=c)
		{
		fprintf(stdout, " %d", c->wrt);
		c =c->n;
		}
	}
}
       std::cout<<"\n"<<count;
       system("pause");
	   return 0;
}

		
