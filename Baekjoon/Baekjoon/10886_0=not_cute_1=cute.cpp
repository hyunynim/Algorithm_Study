#include <stdio.h>

int main() {
	int n, tmp;
	int cute = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == 0)
			cute--;
		else
			cute++;
	}
	if (cute > 0)
		printf("Junhee is cute!");
	else
		printf("Junhee is not cute!");
}