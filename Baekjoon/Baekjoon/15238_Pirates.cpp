#include<cstdio>

int main() {
	int cnt[30] = { 0 };
	int tmp;
	char msg[1010];
	scanf("%d %s", &tmp, msg);
	int i = 0;
	while (msg[i] != '\0')
		++cnt[msg[i++] - 'a'];
	int max = 0, maxIndex = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > max) {
			max = cnt[i];
			maxIndex = i;
		}
	}
	printf("%c %d", maxIndex + 'a', max);
}