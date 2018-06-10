#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int i = 1;
	int res = 0;
	for (int i = 1; i <= 501; ++i) {
		for (int j = i + 1; j <= 501; ++j) {
			if (j*j - i*i == n)
				++res;
			if (j*j - i*i > 1000)
				break;
		}
	}
	printf("%d", res);
}