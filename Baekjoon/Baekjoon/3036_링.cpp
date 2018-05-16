#include<cstdio>
#include<vector>
using namespace std;
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int n, tmp;
	vector<int> seq;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	for (int i = 1; i < seq.size(); ++i) {
		tmp = gcd(seq[0], seq[i]);
		printf("%d/%d\n", seq[0] / tmp, seq[i] / tmp);
	}
}