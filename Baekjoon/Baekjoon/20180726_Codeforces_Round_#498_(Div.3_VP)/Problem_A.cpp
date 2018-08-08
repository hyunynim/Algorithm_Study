#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	for (int i = 0; i < n; ++i) {
		if (seq[i] % 2 == 0)
			printf("%d ", seq[i] - 1);
		else
			printf("%d ", seq[i]);
	}
}