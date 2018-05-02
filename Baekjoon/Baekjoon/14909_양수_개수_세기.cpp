#include<cstdio>

int main() {
	int res = 0;
	int tmp;
	while (scanf("%d", &tmp) != EOF)
		tmp > 0 ? res++ : 0;
	printf("%d", res);
}