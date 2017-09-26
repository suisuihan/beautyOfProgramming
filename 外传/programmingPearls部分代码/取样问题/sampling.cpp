#include <iostream>
#include <set>
#include <time.h>
#include "myRandom.h"

using namespace std;

class InSetSTL {
private:
	set<int> S;
public:
	InSetSTL(int maxelements, int maxval){};
	int size(){
		return S.size();
	}
	void insert(int t){
		S.insert(t);
	}
	void report(int *v){
		int j = 0;
		set<int>::iterator i;
		for(i = S.begin(); i != S.end(); i++)
			v[j++] = *i;
	}
};

class InSetArray {
private:
	int n, maxNum, *x;
public:
	InSetArray(int maxelements, int maxval){
		x = new int[maxelements + 1];
		n = 0;
		x[0] = maxval;
		maxNum = maxval;
	};
	int size(){
		return n;
	}
	void insert(int t){
		if (t > maxNum)
			return;
		int i;
		for (i = 0; x[i] < t; i++)
		;
		if(x[i] == t)
			return;
		for(int j = n; j >= i; j--)
			x[j+1] = x[j];
		x[i] = t;
		n++;
	}
	void report(int *v){
		for(int i = 0; i <n; i++)
			v[i] = x[i];
	}
};

class InSetList {
private:
	struct node {
		int val;
		node *next;
		node(int v, node *p){val = v, next = p;}
	};
	node *rinsert(node *p, int t){
		if (p->val < t)
			p->next = rinsert(p->next, t);
		else if (p->val > t){
			p = new node(t, p);
			n++;
		}
		return p;
	};
public:
	InSetList(int maxelements, int maxval){
		n = 0;
		maxNum = maxval;
		head = sentinel = new node(maxval, nullptr);
	};
	int size(){
		return n;
	}
	void insert(int t){
		head = rinsert(head, t);
	}
	void report(int *v){
		int j = 0;
		for(node * p= head; p != sentinel; p = p->next)
			v[j++] = p->val;
	}
private:
	int n, maxNum;
	node *head, *sentinel;
};

class InSetBST {
private:
	struct node {
		int val;
		node *left, *right;
		node(int i){val = i; left = right =nullptr;}
	};
	node *rinsert(node *p, int t){
		if(p == nullptr){
			p = new node(t);
			n++;
		}else if(t < p->val)
			p->left = rinsert(p->left, t);
		else if (t > p->val)
			p->right = rinsert(p->right, t);
		return p;
	};
	void traverse(node *p){
		if(p == nullptr)
			return;
		traverse(p->left);
		v[vn++] = p->val;
		traverse(p->right);
	}
	int n, *v, vn;
	node *root;
public:
	InSetBST(int maxelements, int maxval){
		n = 0;
		root = nullptr;
	};
	int size(){
		return n;
	}
	void insert(int t){
		root = rinsert(root, t);
	}
	void report(int *x){
		v = x;
		vn = 0;
		traverse(root);
	}
};

class InSetBins {
private:
	struct node {
		int val;
		node *next;
		node(int v, node *p){val = v; next = p;}
	};
	node *rinsert(node *p, int t){
		if (p->val < t)
			p->next = rinsert(p->next, t);
		else if (p->val > t){
			p = new node(t, p);
			n++;
		}
		return p;
	};
	int n, bins, maxval;
	node **bin, *sentinel;
public:
	InSetBins(int maxelements, int pmaxval){
		bins = maxelements;
		maxval = pmaxval;
		bin = new node*[bins];
		sentinel = new node(maxval, nullptr);
		for (int i =0; i < bins; i++)
			bin[i] = sentinel;
		n = 0;
	};
	int size(){
		return n;
	}
	void insert(int t){
		int i = t / (1 + maxval/bins);
		bin[i] = rinsert(bin[i], t);
	}
	void report(int *x){
		int j = 0;
		for (int i = 0; i < bins; i++){
		    for(node *p = bin[i]; p != sentinel; p = p->next)
			    x[j++] = p->val;
		}
	}
};


void gensets1(int m, int n){
	int *v = new int[m];
	InSetSTL S(m, n);
	while (S.size() < m){
		S.insert(bigrand() % n);
	}
	S.report(v);
	for (int i = 0; i < m; i++)
		cout << v[i] << " ";
	cout << endl;
}

void gensets2(int m, int n){
	int *v = new int[m];
	InSetArray S(m, n);
	while (S.size() < m){
		S.insert(bigrand() % n);
	}
	S.report(v);
	for (int i = 0; i < m; i++)
		cout << v[i] << " ";
	cout << endl;
}

void gensets3(int m, int n){
	int *v = new int[m];
	InSetList S(m, n);
	while (S.size() < m){
		S.insert(bigrand() % n);
	}
	S.report(v);
	for (int i = 0; i < m; i++)
		cout << v[i] << " ";
	cout << endl;
}

void gensets4(int m, int n){
	int *v = new int[m];
	InSetBST S(m, n);
	while (S.size() < m){
		S.insert(bigrand() % n);
	}
	S.report(v);
	for (int i = 0; i < m; i++)
		cout << v[i] << " ";
	cout << endl;
}

void gensets5(int m, int n){
	int *v = new int[m];
	InSetBins S(m, n);
	while (S.size() < m){
		S.insert(bigrand() % n);
	}
	S.report(v);
	for (int i = 0; i < m; i++)
		cout << v[i] << " ";
	cout << endl;
}


int main(){
	srand((unsigned int)time(NULL));
	// gensets2(5, 10);
	// gensets3(5, 10);
	// gensets4(5, 10);
	gensets5(5, 10);
}
