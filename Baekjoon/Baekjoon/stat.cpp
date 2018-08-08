#include<cstdio>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main() {
	srand(time(NULL));
	int ans[2] = { 0 };
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			int r = (int)((RAND_MAX - rand()) / (long double)RAND_MAX * 2);
			printf("%c",  r ? 'H' : 'T');
			ans[r]++;
		}
		printf("\n");
	}
	printf("H%d T%d", ans[0], ans[1]);
}