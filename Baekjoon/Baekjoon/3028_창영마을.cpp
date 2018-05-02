#include<cstdio>

void change(int *a, int *b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int main() {
	char msg[100];
	int a[3] = { 1, 0, 0 };
	scanf("%s", msg);
	int i = 0;
	while (msg[i] != '\0') {
		switch (msg[i]) {
		case 'A':
			change(&a[0], &a[1]);
			break;
		case 'B':
			change(&a[1], &a[2]);
			break;
		case 'C':
			change(&a[0], &a[2]);
			break;
		}
		++i;
	}
	for (int i = 0; i < 3; ++i) {
		if (a[i]) {
			printf("%d", i + 1);
			return 0;
		}
	}
}