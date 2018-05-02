#include <iostream>
#include <vector>

using namespace std;

vector <int> numList;

void PrintNum(vector <int> picked);
void PickNum(int n, vector <int> & picked, int toPick, int prevIndex) {
	if (toPick == 0)
		PrintNum(picked);
	int next = picked.empty() ? 0 : prevIndex + 1;
	for (int i = next; i < n; ++i) {
		picked.push_back(numList[i]);
		PickNum(n, picked, toPick - 1, i);
		picked.pop_back();
	}
}

void PrintNum(vector <int> picked) {
	for (int i = 0; picked.begin() + i != picked.end(); ++i)
		printf("%d ", picked[i]);
	printf("\n");
}

int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		else {
			vector <int> vtmp;
			int tmp;
			for (int i = 0; i < n; ++i) {
				scanf("%d", &tmp);
				numList.push_back(tmp);
			}
			PickNum(n, vtmp, 6, 0);
			numList.clear();
			printf("\n");
		}
	}
}
