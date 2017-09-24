#include <stdlib.h>
#include <cmath>
using namespace std;

int bigrand() {
	return abs(RAND_MAX * rand() + rand());
}

int randint(int l, int u) {
	return 1 + bigrand() % (u - l + 1);
}
