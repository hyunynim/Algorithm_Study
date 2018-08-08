#include<cstdio>
#include<Vector>
#include<algorithm>

using namespace std;
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int t;
vector<int> seq;
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		seq.resize(n);
		long long res = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%d", &seq[j]);
		}
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; ++k) {
				if (seq[j] * seq[k] != 0)
					res += gcd(seq[j], seq[k]);
			}
		}
		printf("%lld\n", res);
	}
}