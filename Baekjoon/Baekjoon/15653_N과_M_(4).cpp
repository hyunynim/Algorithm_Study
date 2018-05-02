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
		int next = picked.empty() ? 1 : picked.back();
		for (int i = next; i <= n; ++i) {
				picked.push_back(i);
				TSP(picked, toPick - 1);
				picked.pop_back();
		}
	}
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	vector <int> tsp;
	TSP(tsp, m);
}