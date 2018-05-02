#include <cstdio>
#include <vector>

using namespace std;

int k;
bool isPerfect = 0;

void CheckSum(vector <int> & picked) {
	int res = 0;
	for (int i = 0; i < 3; ++i) {
		res += (picked[i]+1)*(picked[i])/2;
	}
	if (res == k)
		isPerfect = 1;
}

void Pick(vector <int> & picked, int toPick) {
	if (toPick == 0)
		CheckSum(picked);
	else {
		int next = picked.empty() ? 1 : picked.back();
		for (int i = next; i <= k - 2; ++i) {
			picked.push_back(i);
			Pick(picked, toPick - 1);
			picked.pop_back();
			if (isPerfect)
				break;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		vector <int> triNum;
		scanf("%d", &k);
		Pick(triNum, 3);
		if (isPerfect)
			printf("1\n");
		else
			printf("0\n");
		isPerfect = 0;
		triNum.clear();

	}
}