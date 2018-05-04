#include<cstdio>
typedef long long ll;

ll cache[36] = { 1 };

ll recur(int n) {
	if (cache[n] != 0)
		return cache[n];
	else {
		for (int i = 0; i < n; ++i) {
			cache[n] += recur(i)*recur(n - 1 - i);
		}
	}
	return cache[n];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", recur(n));

}