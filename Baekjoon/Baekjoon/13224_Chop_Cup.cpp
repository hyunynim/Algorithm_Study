#include<cstdio>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	char msg[60];
	int i = 0;
	int a[3] = { 1, 0 ,0 };
	scanf("%s", msg);

	while (msg[i] != '\0') {
		switch (msg[i]) {
		case 'A':
			swap(&a[0], &a[1]);
			break;
		case 'B':
			swap(&a[1], &a[2]);
			break;
		case 'C':
			swap(&a[0], &a[2]);
			break;
		}
		++i;
	}
	for (int i = 0; i < 3; ++i)
	{
		if (a[i])
			printf("%d", i + 1);
	}
}