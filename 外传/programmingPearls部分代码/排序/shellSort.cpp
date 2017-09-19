#include <iostream>
using namespace std;

template <typename T>
void shellSort(T a[], int len)
{
    if (len <= 1)
        return;
    int i, j, gap;
    T temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
    {
        for (i = gap; i < len; i++)
        {
            temp = a[i];
            for (j = i - gap; j >= 0 && a[j] > temp; j -= gap)
                a[j + gap] = a[j];
            a[j + gap] = temp;
        }
    }
}

int main()
{
    int a[] = {49, 38, 65, 97, 26, 13, 27, 49, 55, 4};
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    shellSort(a, sizeof(a) / sizeof(a[0]));
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}