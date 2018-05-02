#include <iostream>

int main() {
	int sum = 0;
	int cnt[101] = { 0 };
	int tmp;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &tmp);
		sum += tmp;
		cnt[tmp / 10]++;
	}
	int max = 0;
	int maxindex = 0;
	for (int i = 0; i < 101; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			maxindex = i;
		}
	}
	printf("%d %d", sum / 10, maxindex * 10);
}