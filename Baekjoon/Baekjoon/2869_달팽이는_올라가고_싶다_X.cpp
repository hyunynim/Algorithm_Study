#include <iostream>


int main() {
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);

	if (v % (a - b) == 0)
		printf("%d", v / (a - b) - 1);
	else
		printf("%d", v / (a - b));
	return 0;
}