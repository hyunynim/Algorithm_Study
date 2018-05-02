#include <iostream>

int main() {
	int score[5][5] = { 0 };
	int max = 0, maxindex = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &score[i][j]);
			score[i][4] += score[i][j];
		}
		if (max < score[i][4]) {
			max = score[i][4];
			maxindex = i;
		}
	}
	printf("%d %d", maxindex + 1, max);
}