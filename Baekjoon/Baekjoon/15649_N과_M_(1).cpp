#include <iostream>
#include <vector>
#define INTMAX 2000000000

using namespace std;
int n;

void printPick(vector <int> picked) {
	for (int i = 0; picked.begin() + i != picked.end(); ++i) {
		if (picked[i] != 0)
			printf("%d ", picked[i]);
	}
	printf("\n");
}

void TSP(vector <int> & picked, int toPick) {
	if (toPick == 0)
		printPick(picked);
	else {
		int chk = 0;
		for (int i = 0; picked.begin() + i != picked.end(); ++i) {
			chk |= (1 << picked[i]);
		}
		for (int i = 1; i <= n; ++i) {
			if (chk & (1 << i));
			else {
				picked.push_back(i);
				TSP(picked, toPick - 1);
				picked.pop_back();
			}
		}
	}
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	vector <int> tsp;
	TSP(tsp, m);
}