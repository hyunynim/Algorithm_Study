#include <stdio.h>

int main() {
	char c;
	double res = 0.0;
	scanf("%1c", &c);
	switch (c) {
	case 'A':
		res += 4.0;
		break;
	case 'B':
		res += 3.0;
		break;
	case 'C':
		res += 2.0;
		break;
	case 'D':
		res += 1.0;
		break;
	case 'F':
		printf("0.0");
		return 0;
	}
	scanf("%c1", &c);
	switch (c) {
	case '+':
		res += .3;
		break;
	case '0':
		res += .0;
		break;
	case '-':
		res -= .3;
		break;
	}
	printf("%.1lf", res);
}