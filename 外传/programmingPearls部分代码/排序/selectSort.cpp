#include<iostream>
using namespace std;

template <typename T>
void swap(T a[], int i, int j) {
	T t = a[i];
	a[i] = a[j];
	a[j] = t;
}

template <typename T>
void selectSort(T a[], int length) {
	if (length <= 1)
		return;
	T minValue = a[0];
	int minIndex = 0;
	for (int i = 0; i < length; i++) {
		minValue = a[i];
		minIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (a[j] < minValue) {
				minValue = a[j];
				minIndex = j;
			}
		}
		if (i != minIndex)
			swap(a, i, minIndex);
	}
}

int main() {
	int a[] = { 1,3,1,4,2,8,4 };
	selectSort(a, sizeof(a) / sizeof(a[0]));
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
