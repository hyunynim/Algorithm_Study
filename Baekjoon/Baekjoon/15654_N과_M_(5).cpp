#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
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
		bool * isPicked = new bool[n];
		memset(isPicked, 0, sizeof(isPicked));
		for (int i = 0; i < picked.size(); ++i) {
			for (int j = 0; j < seq.size(); ++j) {
				if (picked[i] == seq[j]) {
					isPicked[j] = 1;
					break;
				}
			}
		}
		for (int i = 0; i < seq.size(); ++i) {
			if (!isPicked[i]) {
				picked.push_back(seq[i]);
				TSP(picked, toPick - 1, i + 1);
				picked.pop_back();
			}
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