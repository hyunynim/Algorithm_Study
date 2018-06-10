#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> score(n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &score[i]);

	char t[123];
	int maxScore = 0, maxIndex = 98765432, tmp;
	for (int i = 0; i < m; ++i) {
		int sum = 0;
		scanf("%d", &tmp);
		for (int j = 0; j < n; ++j) {
			scanf("%s", t);
			if (t[0] == 'O')
				sum += score[j];
		}
		if (sum > maxScore) {
			maxScore = sum;
			maxIndex = tmp;
		}
		else if (sum == maxScore) {
			maxIndex = tmp < maxIndex ? tmp : maxIndex;
		}
	}
	printf("%d %d", maxIndex, maxScore);
}

/*comment*/
//최고점이 0점인 경우 제대로 처리가 안되고 있었음