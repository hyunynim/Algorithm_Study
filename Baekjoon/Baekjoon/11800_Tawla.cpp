#include<cstdio>
void swap(int *a, int * b) {
	if (*a < *b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

int main() {
	int a, b, t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d %d", &a, &b);
		printf("Case %d: ", i + 1);
		if (a == b) {
			switch (a) {
			case 1:
				printf("Habb Yakk");
					break;
			case 2:
				printf("Dobara");
				break;
			case 3:
				printf("Dousa");
				break;
			case 4:
				printf("Dorgy");
				break;
			case 5:
				printf("Dabash");
				break;
			case 6:
				printf("Dosh");
				break;
			}
		}
		else {
			swap(&a, &b);
			for (int j = 0; j < 2; ++j) {
				if (j == 1)
					a = b;
				switch (a) {
				case 1:
					printf("Yakk");
					break;
				case 2:
					printf("Doh");
					break;
				case 3:
					printf("Seh");
					break;
				case 4:
					printf("Ghar");
					break;
				case 5:
					printf("Bang");
					break;
				case 6:
					if (b == 5) {
						printf("Sheesh Beesh");
					}
					else
						printf("Sheesh");
					break;
				}
				if (a == 6 && b == 5)
					break;
				if (j == 0)
					printf(" ");
		
			}
		}
		printf("\n");
	}
}