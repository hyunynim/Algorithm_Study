#include<cstdio>

int main() {
	int sum = 3;
	int prec[29] = { 0 };
	int n;
	for (int i = 0; i < 29; ++i) {
		prec[i] = sum;
		sum = sum * 2 + i + 4;
	}
	scanf("%d", &n);
	int index = 28;
	while (1) {
		if (n < 3) {
			if (n == 1)
				printf("m");
			else
				printf("o");
			return 0;
		}
		while (prec[index] > n && index > 0)
			--index;
		if (prec[index] == n) {
			printf("o");
			return 0;
		}
		n -= prec[index];
		if (n > index + 4)
			n -= index + 4;
		else {
			if (n == 1)
				printf("m");
			else
				printf("o");
			return 0;
		}
		if(index > 0)
			--index;
	}
	
}