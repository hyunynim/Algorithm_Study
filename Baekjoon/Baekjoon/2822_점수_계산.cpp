#include <stdio.h>
#include <algorithm>

int main() {
	int score[2][8], tmp;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &score[0][i]);
		score[1][i] = i + 1;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 8; j++) {
			if (score[0][i] < score[0][j]) {
				tmp = score[0][i];
				score[0][i] = score[0][j];
				score[0][j] = tmp;
				tmp = score[1][i];
				score[1][i] = score[1][j];
				score[1][j] = tmp;
			}
		}
	}
	printf("%d\n", score[0][0] + score[0][1] + score[0][2] + score[0][3] + score[0][4]);
	std::sort(score[1], score[1] + 5);
	for (int i = 0; i < 5; i++)
		printf("%d ", score[1][i]);
}