#include <iostream>
#include <vector>

using namespace std;

int n;

void printPick(vector <int> & picked) {
	for (int i = 0; picked.begin() + i != picked.end(); ++i)
		printf("%d ", picked[i]);
	printf("\n");
}

void pick(vector <int> & picked, int toPick) {
	if (toPick == 0)
		printPick(picked);
	int next = picked.empty() ? 1 : picked.back() + 1;
	for (int i = next; i <= n; ++i) {
		picked.push_back(i);
		pick(picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	vector <int> tmp;
	if (m == 1) {
		for (int i = 1; i <= n; ++i)
			printf("%d\n", i);
	}
	else {
		pick(tmp, m);
	}
}