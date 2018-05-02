#include <cstdio>

int main() {
	int n;
	int num[10001] = { 0 };
	scanf("%d", &n);
	int tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		++num[tmp];
	}
	for (int i = 1; i <= 10000; ++i) {
		if (num[i] != 0) {
			for (int j = 0; j < num[i]; ++j)
				printf("%d\n", i);
		}
	}
}