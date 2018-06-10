#include<cstdio>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

int ABS(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
	}
	long long res = 0;
	for (int i = 0; i < seq.size(); ++i) {
		for (int j = 0; j < seq.size(); ++j) {
			res += ABS(seq[j] - seq[i]);
		}
	}
	printf("%lld", res);
}

/*comment*/
//중복 제거하면 안되는 문제였음