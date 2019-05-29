#include <iostream>
using namespace std;
int cnt = 0; //count of comparisons
int n = 0;
const int MAX_ITEMS = 100;
void merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast);
void printarray(int a[], int n);
void mergesort(int a[], int start, int end) { //no significant comparisons are done during splitting

	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(a, start, mid);
		mergesort(a, mid + 1, end);
		merge(a, start, mid, mid + 1, end);
	}
}
void merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
	int temparray[MAX_ITEMS];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {//compare and select smallest from two subarrays

		if (values[leftFirst] < values[rightFirst]) {
			temparray[index] = values[leftFirst];
			cout << "Comparing: " << values[leftFirst] << " AND " << values[rightFirst] << endl;//smallest assigned to temp
			leftFirst++;
		}
		else
		{
			temparray[index] = values[rightFirst];
			cout << "Comparing: " << values[leftFirst] << " AND " << values[rightFirst] << endl;
			rightFirst++;
		}
		index++;
		cnt++; //count of comaparisons done during merge. One comparison is done per iteration of while loop.
	}

	while (leftFirst <= leftLast) {

		temparray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}

	for (index = saveFirst; index <= rightLast; index++)//copies from temp array to values array
		values[index] = temparray[index];
	printarray(values, n);
	cout << endl;

}

void printarray(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main() {

	std::cout << "Enter number of elements to be sorted : ";
	cin >> n;

	int a[MAX_ITEMS];
	for (int i = 0; i < n; i++) {
		std::cout << "Enter the element: ";
		cin >> a[i];
	}

	int start = 0;
	int end = n - 1;
	cout << "---------------------------" << endl;
	mergesort(a, start, end);
	//printarray(a, n);
	cout << endl;
	cout << "Number of comparisons : " << cnt << endl;
	system("pause");

}