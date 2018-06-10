#include<vector>
#include<cstdio>
#define pb(x) push_back(x)

using namespace std;

int main() {
	int n, m, k;
	vector<int> A[100], B[100], res[100];
	scanf("%d %d", &n, &m);
	int tmp;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			res[i].push_back(0);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &tmp);
			A[i].pb(tmp);
		}
	}
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			scanf("%d", &tmp);
			B[i].pb(tmp);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			for (int l = 0; l < m; ++l) {
				res[i][j] += A[i][l] * B[l][j];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
}