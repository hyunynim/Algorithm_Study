#include <iostream>

int main() {
	int n;
	scanf("%d", &n);
	int win[1001] = { 0, 1, 0, 0, 0, 0, 1, 0 }; //0:SK, 1:CY
	for (int i = 4; i < n; ++i) {
		int res = win[i - 4] + win[i - 3] + win[i - 1];
		if (res == 0)
			win[i] = 1;
		else if (res == 3)
			win[i] = 0;
		else
			win[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (i % 7 == 0)
			printf("\n");
		printf("%d", win[i]);
	}
	if (win[n - 1])
		printf("CY");
	else
		printf("SK");
}