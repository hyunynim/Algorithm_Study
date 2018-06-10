#include<cstdio>

int main() {
	int a[5];
	int tempCount = 5;
	int loop, i, hold;
	for (int i = 0; i < 5; ++i)
		scanf("%d", &a[i]);
	for (loop = 0; loop < tempCount - 1; loop++) {
		for (i = 0; i < tempCount - 1 - loop; i++) {
			if (a[i] > a[i + 1]) {
				hold = a[i];
				a[i] = a[i + 1];
				a[i + 1] = hold;
				for (int k = 0; k < 5; ++k)
					printf("%d ", a[k]);
				printf("\n");
			}
		}
	}


}