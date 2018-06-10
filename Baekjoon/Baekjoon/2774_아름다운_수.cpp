#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int num;
		int cnt[10] = { 0 };
		scanf("%d", &num);
		while (num > 0) {
			cnt[num % 10]++;
			num /= 10;
		}
		
		int res = 0;
		for (int i = 0; i < 10; ++i) {
			if (cnt[i])
				res++;
		}
		printf("%d\n", res);
	}
}