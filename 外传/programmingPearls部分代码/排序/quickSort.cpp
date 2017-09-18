#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

template <typename T>
void swap(T a[], int i, int j){
    T t = a[i];
    a[i] = a[j];
    a[j] = t;
}

template <typename T>
void insertSort(T *a, int length){
    if (length <= 1)
        return;
    for(int i = 1; i < length; i++){
        T t = a[i];
        int j = i;
        for(; j > 0 && a[j-1] > a[j] ; j--)
                a[j] = a[j-1];
        a[j+1] = t;
    }
}

template <typename T>
void quickSort1(T a[], int begin, int end){
    if (begin >= end)
        return;
    int i = begin, j = end;
    // int isSelect = rand()%(end - begin) + begin;
    // swap(a, begin, isSelect);
    T choiceValue = a[begin];
    while(i < j){
        while(i < j and a[j] >= choiceValue) j--;
        a[i] = a[j];
        while(i < j and a[i] < choiceValue) i++;
        a[j] = a[i];
    }
    a[i] = choiceValue;
    quickSort1(a, begin, i - 1);
    quickSort1(a, i + 1, end);
}

template <typename T>
void quickSort2(T a[], int begin, int end){
    if (begin >= end)
        return;
    int i = begin, j = end;
    int isSelect = rand()%(end - begin) + begin;
    swap(a, begin, isSelect);
    T choiceValue = a[begin];
    while(i < j){
        while(i < j and a[j] >= choiceValue) j--;
        a[i] = a[j];
        while(i < j and a[i] < choiceValue) i++;
        a[j] = a[i];
    }
    a[i] = choiceValue;
    quickSort2(a, begin, i - 1);
    quickSort2(a, i + 1, end);
}

template <typename T>
void quickSort3(T a[], int begin, int end){
    int std_length = 50;
    if ((end - begin) < 50)
        return;
    int i = begin, j = end;
    int isSelect = rand()%(end - begin) + begin;
    swap(a, begin, isSelect);
    T choiceValue = a[begin];
    while(i < j){
        while(i < j and a[j] >= choiceValue) j--;
        a[i] = a[j];
        while(i < j and a[i] < choiceValue) i++;
        a[j] = a[i];
    }
    a[i] = choiceValue;
    quickSort3(a, begin, i - 1);
    quickSort3(a, i + 1, end);
    insertSort(a, end+1);
}


int main(){
    int a[] = {1,3,1,4,2,8,4};
    srand(time(NULL));
    // quickSort1(a, 0, 6);
    // quickSort2(a, 0, 6);
    quickSort3(a, 0, 6);
    for(auto i: a){
        cout << i << " ";
    }
    cout << endl;
   return 0;
}
