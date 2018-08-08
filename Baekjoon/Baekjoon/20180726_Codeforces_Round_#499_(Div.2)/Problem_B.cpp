#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;

int food[123];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n > m) {
		printf("0");
		return 0;
	}
	vector<int> seq(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &seq[i]);
		food[seq[i]]++;
	}
	
	vector<int> f;
	int ans = 0;
	for (int i = 1; i <= 100; ++i) {
		if (food[i]) {
			f.push_back(food[i]);
		}
	}
	for (int i = m / n; i >= 1; --i) {
		int tmp = 0;
		for (int j = 0; j < f.size(); ++j) {
			tmp += f[j] / i;
		}
		if (tmp >= n) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}