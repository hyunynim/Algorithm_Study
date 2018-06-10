#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> wine;

//max value return
int ChoiceWine(int cnt, int curIndex) {
	if (curIndex >= n)
		return 0;

	if (cnt == 2)
		return ChoiceWine(0, curIndex + 1);

	else if (cnt == 1)
		return max(ChoiceWine(0, curIndex + 1), ChoiceWine(2, curIndex + 1) + wine[curIndex]);

	else if (cnt == 0) {
		return max(ChoiceWine(0, curIndex + 1), ChoiceWine(1, curIndex + 1) + wine[curIndex]);
	}
}

int main() {
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i<n; ++i) {
		scanf("%d", &tmp);
		wine.push_back(tmp);
	}
	int sum = 0;
	sum += ChoiceWine(0, 0);
	printf("%d", sum);
}
