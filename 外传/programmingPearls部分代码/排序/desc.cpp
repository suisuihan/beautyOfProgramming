#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <set>
#include <time.h>
#include <cmath>
using namespace std;

int bigrand() {
    return abs(RAND_MAX * rand() + rand());
}

int randint(int l, int u) {
    return 1 + bigrand() % (u - l + 1);
}

void randomSelect(int m, int n){
    if (m > 0)
        if(bigrand() % n < m){
            cout << n - 1 << " ";
            randomSelect(m -1, n - 1);
        }else
            randomSelect(m, n - 1);
}

void randomSelectAsc(int m, int n){
    if (m > 0)
        if(bigrand() % n < m){
            randomSelectAsc(m -1, n - 1);
            cout << n - 1 << " ";
        }else
            randomSelectAsc(m, n - 1);

}


int main(){
    srand((unsigned int)time(NULL));
    randomSelect(10, 20);
    cout << endl;
    randomSelectAsc(5, 10);
    cout << endl;
    randomSelectAsc(2, 3);
    cout << endl;
    return 0;
}
