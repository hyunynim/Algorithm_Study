#include<cstdio>
#include<string.h>

int main() {
	int num;
	int cnt[42];
	memset(cnt, -1, sizeof(cnt));
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &num);
		cnt[num % 42]++;
	}
	int res = 0;
	for (int i = 0; i < 42; ++i)
		cnt[i] >= 0 ? res++ : 0;
	printf("%d", res);
}