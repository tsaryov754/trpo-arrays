#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
/*	// static array
	const int N = 10;
	int a[N];
	for (int i = 0; i < N; i++) {
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cout << a[i] << setw(5);
	}
	delete[]a;
	cout << "\n\n\n";
*/

	//dinamic array
	int n;
	cout << "enter size of array\n";
	cin >> n;
	int* arr = new int[n];
	srand(time(0));
	int a, b;
	cout << "enter a and b\n";
	cin >> a >> b;
	cout << "random array\n";
	for (int i = 0; i < n; i++) {
		arr[i] = a + (rand() % (b - a) + 1);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << setw(5);
	}


	int min = 0, max = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[min]) {
			min = i;
		}
	}
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[max]) {
			max = i;
		}
	}
	cout << "\nmin element=" << arr[min] << " and have index number " << min << endl;
	cout << "max element=" << arr[max] << " and have index number " << max << endl;


	for (int i = 0; i < n - 1; i++) {
		int indexOfMax = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[indexOfMax]) { indexOfMax = j; }
		}
		if (indexOfMax != i) {
			swap(arr[i], arr[indexOfMax]);
		}
	}
	cout << "array from max element to min element\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << setw(5);
	}
	cout << endl;


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
	cout << "array without even numbers\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << setw(5);
	}
	delete[]arr;
	return 0;
}