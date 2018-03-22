#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, b, c, tmp;
	vector <int> a;
	long long ans = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	scanf("%d %d", &b, &c);
	for (int i = 0; a.begin() + i != a.end(); ++i) {
		a[i] -= b;
		++ans;
		if (a[i] > 0) {
			if (a[i] % c != 0)
				ans += (long long)a[i] / c + 1;
			else
				ans += (long long)a[i] / c;
		}
	}
	printf("%lld", ans);
}