#include <stdio.h>

bool star[401][401] = { 0 };

enum { UP, DOWN, LEFT, RIGHT };

void print_star(int xi, int yi, int size) {
	int go = 2 * size - 1;
	int flag = UP;
	star[xi][yi] = 1;
	
	for (int i = 0; i < go; ++i) {
		for(int k = 0; k<2; k++){
			for (int j = 0; j < 2 * (i + 1); j++) {
				switch (flag) {
				case UP:
					--yi;
					break;
				case RIGHT:
					++xi;
					break;
				case DOWN:
					++yi;
					break;
				case LEFT:
					--xi;
					break;
				}
				star[xi][yi] = 1;
			}
			switch (flag) {
			case UP:
				flag = RIGHT;
				break;
			case RIGHT:
				flag = DOWN;
				break;
			case DOWN:
				flag = LEFT;
				break;
			case LEFT:
				flag = UP;
				break;
			}
		}
		
	}

}

int main() {
	int n;
	scanf("%d", &n);
	
	if (n == 1) {
		printf("*");
		return 0;
	}
	else
	{
		print_star(2 * (n - 1), 2 * n, n);
		for (int i = 0; i < 4 * n - 1; i++) {
			for (int j = 0; j < 4 * n - 3; j++) {
				if (star[j][i])
					printf("*");
				else
					printf(" ");
				if (i == 1)
					break;
			}
			printf("\n");
		}
	}
}




/*commnet*/
//선분의 개수 3n + (n-2) = 4n-2; 개
//첫 점에서 부터
//2 2 4 4 6 6 8 8 10 10 12 12 14 12
//가로로 4칸씩 늘어남
//1 5 9 13 17 21...
//1 + 4 * (n - 1)
//정사각형
//2	(2, 4)
//3	(4, 6)
//4	(6, 8)
//세로 4n - 1개
//가로 4n - 3개
//2, 2, 4, 4, 6, 6, 8, 8
//총 4n - 2번 가야함
//두번째줄 공백없음