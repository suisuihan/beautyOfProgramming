#include <iostream>
#include <time.h>
#include <stdexcept>
#include "myRandom.h"
using namespace std;

template<class T>
class Priqueue{
private:
	int n, maxsize;
	T *x;
	void swap(int i, int j){
		T t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
public:
	Priqueue(int m){
		maxsize = m;
		x = new T[maxsize + 1];
		n = 0;
	}

	void insert(T t){
		if (n+1 > maxsize)
			throw out_of_range("has reached maxsize!");
		int i, p;
		x[++n] = t;
		for(i = n; i > 1 && x[p=i/2] > x[i]; i = p)
			swap(p, i);
	}

	T extractmin(){
		int i, c;
		T t = x[1];
		x[1] = x[n--];
		for(i = 1; (c = 2*i) <= n; i = c){
			if (c+1 <=n && x[c+1] < x[c])
				c++;
			if(x[i] <= x[c])
				break;
			swap(c, i);
		}
		return t;
	}

	int size(){
		return n;
	}

	int maxSize(){
		return maxsize;
	}
};

int main(){
	srand(time(NULL));
	int size = 10;
	auto *p = new Priqueue<int>(size);
	try{
	while(true)
		p->insert(bigrand() % size);
	}catch(exception &e){
		cout << e.what() << endl;
	}
	while(p->size() > 0)
	    cout << p->extractmin() << " ";
	cout << endl;
}
