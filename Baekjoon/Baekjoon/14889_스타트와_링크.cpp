#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int power[123][123];
vector<int> seq;
int n;

int ABS(int a) { return a > 0 ? a : -a; }

int calc() {
	vector<int> t1, t2;
	for (int i = 0; i < n; ++i) {
		if (seq[i])
			t1.push_back(i);
		else
			t2.push_back(i);
	}
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < n / 2; ++j) {
			s1 += power[t1[i]][t1[j]];
			s2 += power[t2[i]][t2[j]];
		}
	}
	return ABS(s1 - s2);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &power[i][j]);
		}
	}
	for (int i = 0; i < n/2; ++i) {
		seq.push_back(0);
		seq.push_back(1);
	}
	sort(seq.begin(), seq.end());
	int ans = (int)1e9;
	do {
		ans = min(ans, calc());
	} while (next_permutation(seq.begin(), seq.end()));
	printf("%d", ans);
}