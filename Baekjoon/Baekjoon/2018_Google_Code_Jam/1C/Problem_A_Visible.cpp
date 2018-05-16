#include<cstdio>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;

int Pow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2 == 1)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, l;
		int cnt['z' - 'a' + 1] = { 0 };
		char msg[1000][10];
		vector<char> seq[10];
		scanf("%d %d", &n, &l);

		for (int j = 0; j < n; ++j) {
			scanf("%s", msg[j]);
			for (int k = 0; k < l; ++k) {
				cnt[msg[j][k] - 'A']++;
				seq[k].push_back(msg[j][k]);
			}
		}

		printf("Case #%d: ", i + 1);
		int useA = 0;
		for (int j = 0; j < 26; ++j) {
			if (cnt[j])
				useA++;
		}
		for (int i = 0; i < 10; ++i) {
			sort(seq[i].begin(), seq[i].end());
			seq[i].erase(unique(seq[i].begin(), seq[i].end()), seq[i].end());
		}
		int k = 1;
		for (int sd = 0; sd < l; ++sd)
			k *= seq[sd].size();
		if (l == 1 || n == Pow(useA, l) || n == k) {
			printf("-\n");
			continue;
		}

		bool isBreak = 0, isEs = 0;
		for (int k = 0; k < seq[0].size(); ++k) {
			isBreak = 0;
			for (int l = 0; l < seq[1].size(); ++l) {
				isBreak = 0;
				for (int j = 0; j < n; ++j) {
					if (msg[j][0] == seq[0][k] && msg[j][1] == seq[1][l]) {
						isBreak = 1;
						break;
					}
				}
				if (!isBreak) {
					printf("%c%c", seq[0][k], seq[1][l]);
					isBreak = 1;
					isEs = 1;
					break;
				}
			}
			if (isEs)
				break;
		}

		if (l > 2) {
			srand(123);
			for (int j = 2; j < l; ++j) {
				printf("%c", seq[j][rand() % seq[j].size()]);
			}
		}

		printf("\n");
	}

}