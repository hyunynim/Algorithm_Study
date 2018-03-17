#include <stdio.h>

int main() {
	int l, p;
	int other;
	scanf("%d %d", &l, &p);
	int people = l*p;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &other);
		printf("%d ", other - people);
	}
}