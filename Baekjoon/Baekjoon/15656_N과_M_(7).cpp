#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector <int> seq;

void printPick(vector <int> picked) {
	for (int i = 0; picked.begin() + i != picked.end(); ++i) {
		if (picked[i] != 0)
			printf("%d ", picked[i]);
	}
	printf("\n");
}

void TSP(vector <int> & picked, int toPick, int prev) {
	if (toPick == 0)
		printPick(picked);
	else {
		for (int i = prev; i < seq.size(); ++i) {
			picked.push_back(seq[i]);
			TSP(picked, toPick - 1, prev);
			picked.pop_back();
		}
	}
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	int tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	sort(seq.begin(), seq.end());
	vector <int> tsp;
	TSP(tsp, m, 0);
}