#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;


void generateArray(int* arr, int n, int a, int b);
int minElement(int min, int n, int* arr);
int maxElement(int max, int n, int* arr);
void sortArray(int n, int* arr);
void showArray(int* arr, int n);
void delEvenNumb(int* arr, int &n);

int main() {
	setlocale(LC_ALL, "Russian");
	//dinamic array
	int n;
	cout << "enter size of array\n";
	cin >> n;
	int* arr = new int[n];
	int a, b;
	
	cout << "enter a and b\n";
	cin >> a >> b;
	cout << "random array\n";
	generateArray(arr, n, a, b);
	showArray(arr, n);
	//min and max el
	cout << "\nmin element=" << arr[minElement(0, n, arr)] << " and have index number " << minElement(0, n, arr) << endl;
	cout << "max element=" << arr[maxElement(0, n, arr)] << " and have index number " << maxElement(0, n, arr) << endl;


	sortArray(n, arr);
	cout << "array from max element to min element\n";
	showArray(arr, n);


	delEvenNumb(arr, n);
	cout << "\narray without even numbers\n";
	showArray(arr, n);
	delete[]arr;
	return 0;
};


void generateArray(int* arr, int n, int a, int b)
{
	srand(time(0));
	for (int i = 0; i < n; i++) {
		arr[i] = a + (rand() % (b - a) + 1);
	}
};

void showArray(int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << setw(5);
	}
}

int minElement(int min, int n, int* arr)
{
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[min]) {
			min = i;
		}
	}
	return min;
};

int maxElement(int max, int n, int* arr)
{
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[max]) {
			max = i;
		}
	}
	return max;
};

void sortArray(int n, int* arr)
{
	for (int i = 0; i < n - 1; i++) {
		int indexOfMax = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[indexOfMax]) { indexOfMax = j; }
		}
		if (indexOfMax != i) {
			swap(arr[i], arr[indexOfMax]);
		}
	}
}

void delEvenNumb(int* arr, int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			for (int j = i; j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			n--;
			i--;
		}
	}
}