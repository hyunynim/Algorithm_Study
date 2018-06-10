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
			res[i] = 0;
			score[0]++;
			score[1]++;
		}
		else if (a[i] > b[i]) {
			score[0] += 3;
			res[i] = 1;
		}
		else {
			score[1] += 3;
			res[i] = -1;
		}
	}
	printf("%d %d\n", score[0], score[1]);
	if (score[0] > score[1])
		printf("A");
	else if (score[0] < score[1])
		printf("B");
	else {
		int i = 9;
		while (i != -1 && res[i] == 0) {
			--i;
		}
		if (i == -1)
			printf("D");
		else if (res[i]== 1)
			printf("A");
		else
			printf("B");
	}
}