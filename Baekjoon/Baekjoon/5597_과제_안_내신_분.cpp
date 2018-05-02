#include <iostream>

int main() {
	bool chk[31] = { 0 };
	int tmp;
	for (int i = 0; i < 28; i++) {
		scanf("%d", &tmp);
		chk[tmp] = 1;
	}
	for (int i = 1; i < 31; i++) {
		if (chk[i] == 0)
			printf("%d\n", i);
	}
}