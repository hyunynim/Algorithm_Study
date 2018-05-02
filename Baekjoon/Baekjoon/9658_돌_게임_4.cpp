#include <iostream>

int main() {
	long long n;
	scanf("%lld", &n);
	n--;
	n %= 7;
	int res;
	switch (n) {
	case 0:
	case 2:
		res = 1;
		break;
	case 1:
	case 3:
	case 4:
	case 5:
	case 6:
		res = 0;
		break;
	}
	if (res)
		printf("CY");
	else
		printf("SK");
}