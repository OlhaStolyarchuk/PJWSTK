#include<stdio.h>;
#include<iostream>;
#include<algorithm>;
int main()
{
	long long  i, j;
	long long size, size2;
	scanf_s("%lld", &size);
	long long * a = new long long[size];
	long long max = 0;
	for (i = 0; i<size; i++)
	{
		scanf_s("%lld", &a[i]);
		if (a[i] > max)
		max = a[i];
	}
   long long insideOfCircle = 0;
   long long outsideOfCircle = 0;
   long long onTheCircle = 0;
   long long c = max / 2;
   long long r = c*c;
   /*
   for (i = 0; i < size; i++)
   {
	   a[i] = a[i] - c;
	   a[i] *= a[i];
   }
   */
   std::sort(a, a + size);//a wskaznik na pierwszy element tablicy,a+ size wskaznik na ostatni element tablicy
      scanf_s("%lld", &size2);
 //  long long * b = new long long[size2];
	long long number;
	for (j = 0; j < size2; j++)
	{
		scanf_s("%lld", &number);
		//for (i = 0; i < size; i++)
		//{
		//long long result = (a[i] - c) * (a[i] - c) + (number - c) * (number- c);
		//if (result < r) {
		 //   	insideOfCircle++;
		//}
		//else if (result > r) {
			//		outsideOfCircle++;
				//}
				//else
					//onTheCircle++;
			//}
		//poszuk binarnyj
		long long left = 0;//left
		long long right = size - 1;//right
		long long midd;
		while ((right-left)>1) {//poky nie zalyszytsya odyn element
			midd = (left + right)/2;
			long long wrt = (a[midd]-c)*(a[midd]-c) + (number - c)*(number - c);
			if (wrt <= r){
				left = midd;
			}
			else
			{
				right = midd - 1;
			}
		}
		long long l1 = (a[right-1] - c)*(a[right-1] - c) + (number - c)*(number - c);
		long long l2 = (a[right] - c)*(a[right] - c) + (number - c)*(number - c);
		long long l3 = (a[right+1] - c)*(a[right+1] - c) + (number - c)*(number - c);
		if (l1 == r) {
			onTheCircle++;
			insideOfCircle--;
		}
		if (l2 == r) {
			onTheCircle++;
			insideOfCircle--;
		}
		if (l3 == r) {
			onTheCircle++;
			insideOfCircle--;
		}

		long long tmp1 = (a[left] - c)*(a[left] - c) + (number - c)*(number - c);
		long long tmp2 = (a[right]-c)*(a[right] - c) + (number - c)*(number - c);
		if (tmp1 > r) {
			outsideOfCircle += size;
		}
		else if (tmp2<=r)
		{
			insideOfCircle = insideOfCircle + right + 1;
			outsideOfCircle += size - (right + 1);
		}
		else
		{
			insideOfCircle += left + 1;
			outsideOfCircle += size - (left + 1);
		}
		}

	printf_s("%lld %lld %lld", insideOfCircle, onTheCircle, outsideOfCircle);
	//printf_s("cartessian product=");
	//printf_s("{");
	//for (i = 0; i<size; i++)
	///	{
	//	for (j = 0; j<size2; j++)
	//{
	//printf_s("(%d,%d)", a[i], b[j]);
	//printf_s(",");
	//	}
	//}
	//printf_s("}");
	//getchar();
	system("pause");
}