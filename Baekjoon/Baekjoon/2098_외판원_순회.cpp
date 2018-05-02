#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define INTMAX 2000000000
#define MAXCITY 16

using namespace std;
int price[MAXCITY][MAXCITY], n;
double cache[MAXCITY][1 << MAXCITY];

double TSP(int here, int visited) {
	if (visited == (1 << n) - 1) return price[here][0];

	double & ref = cache[here][visited];

	if (ref >= 0) ref;
	ref = INTMAX;

	for (int i = 0; i < n; ++i) {
		if (visited & (1 << i)) continue;
		if (price[here][i] == 0) continue;
		ref = min(ref, price[here][i] + TSP(i, visited + (1 << i)));
	}
	return ref;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%d", &price[i][j]);
	}
	int res = TSP(0, 1);
	printf("%d", res);
}

/*comment*/
//계속 엉뚱한것만 계산하고 있었음
//도전!
//2는 맞았는데 1은 메모리초과
//Reference로 해결한듯 했으나 시간초과
//DP + memoization -> 시간초과