#include<cstdio>

int main() {
	int a[10];
	int b[10];
	int res[10];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 10; ++j) {
			scanf("%d", i == 0 ? &a[j] : &b[j]);
		}
	}
	int score[2] = { 0 };
	for (int i = 0; i < 10; ++i) {
		if (a[i] == b[i]) {
		}
		else if (a[i] > b[i]) {
			score[0] += 1;
			res[i] = 1;
		}
		else {
			score[1] += 1;
			res[i] = -1;
		}
	}
	if (score[0] > score[1])
		printf("A");
	else if (score[0] < score[1])
		printf("B");
	else {
		printf("D");
	}
}