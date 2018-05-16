#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n, tmp;
	vector<int> seq;
	vector<int> sum;
	int sumTmp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
		sumTmp += tmp;
		sum.push_back(sumTmp);
	}
	int m;
	int a, b;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		if (a == 0)
			printf("%d\n", sum[b]);
		else
			printf("%d\n", sum[b] - sum[a - 1]);
	}

}