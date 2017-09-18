#include<iostream>
using namespace std;


template <typename T>
void insertSort(T a[], int length){
    if(length <= 1)
        return;
    for(int i = 1; i < length; i++){
        T t = a[i];
        int j = i;
        for (; j > 0 && a[j-1] > t; j--)
            a[j] = a[j-1];
        a[j] = t;
    }
}

int main(){
    int a[] = {1,3,1,4,2,8,4};
    insertSort(a, 7);
    for(auto i: a){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
