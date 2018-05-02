#include <iostream>

int main() {
	int Y = 0, M = 0;
	int n;
	scanf("%d", &n);
	int tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		Y += tmp / 30 + 1;
		M += tmp / 60 + 1;
	}
	if (Y*10 < M*15)
		printf("Y %d", Y*10);
	else if (Y*10 > M*15)
		printf("M %d", M*15);
	else
		printf("Y M %d", Y*10);
}