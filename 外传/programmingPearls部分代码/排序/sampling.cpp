// programmingPearls.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <set>
#include <time.h>
using namespace std;

template <typename T>
void insertSort(T *a, int length) {
	if (length <= 1)
		return;
	for (int i = 1; i < length; i++) {
		T t = a[i];
		int j = i;
		for (; j > 0 && a[j - 1] > a[j]; j--)
			a[j] = a[j - 1];
		a[j + 1] = t;
	}
}

template <typename T>
void quickSort3(T a[], int begin, int end) {
	int std_length = 50;
	if ((end - begin) < 50)
		return;
	int i = begin, j = end;
	int isSelect = rand() % (end - begin) + begin;
	swap(a, begin, isSelect);
	T choiceValue = a[begin];
	while (i < j) {
		while (i < j && a[j] >= choiceValue) j--;
		a[i] = a[j];
		while (i < j && a[i] < choiceValue) i++;
		a[j] = a[i];
	}
	a[i] = choiceValue;
	quickSort3(a, begin, i - 1);
	quickSort3(a, i + 1, end);
	insertSort(a, end + 1);
}



int bigrand() {
	return RAND_MAX * rand() + rand();
}

int randint(int l, int u) {
	return 1 + bigrand() % (u - l + 1);
}

void gensets(int m, int n) {
	set<int> s;
	while (s.size() < m)
		s.insert(bigrand() % n);
	//for (auto i = s.begin(); i != s.end(); ++i)
	//	cout << *i << endl;
}

inline void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void genshuf(int m, int n) {
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
		a[i] = i;
	for (int i = 0; i < m; ++i)
		swap(a, i, randint(i, n - 1));
	quickSort3(a, 0, m - 1);
}


int main() {
	
	srand((unsigned int)time(NULL));
	gensets(5000000, 1000000000);
	//genshuf(50, 100);
	//genshuf(5000000, 1000000000);
	return 0;
}
