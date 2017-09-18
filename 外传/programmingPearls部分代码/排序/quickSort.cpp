#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

template <typename T>
void swap(T a[], int i, int j){
    T t = a[i];
    a[i] = a[j];
    a[j] = a[i];
}


template <typename T>
void quickSort(T a[], int begin, int end){
    if (begin >= end)
        return;
    int i = begin, j = end;
    int isSelect = rand()%(end - begin) + begin;
    swap(a, begin, isSelect);
    T choiceValue = a[begin];
    while(i < j){
        if(i < j and a[j] >= choiceValue) j--;
        a[i] = a[j];
        if(i < j and a[i] < choiceValue) i++;
        a[j] = a[i];
        //for(T m: a){
        //    cout << m << " ";
        //}
        //cout << endl;
    }
    a[i] = choiceValue;
    quickSort(a, begin, i - 1);
    quickSort(a, i + 1, end);
}

int main(){
    int a[] = {1,3,1,4,2,8,4};
    srand(time(NULL));
    quickSort(a, 0, 6);
    for(auto i: a){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
