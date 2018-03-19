#include <stdio.h>

void max(unsigned long long * a, unsigned long long *b) {
	unsigned long long tmp;
	if (*a > *b) {
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

int main() {
	unsigned long long a, b;
	scanf("%llu %llu", &a, &b);
	if(a == b) {
		for (int i = 0; i < a; i++)
			printf("1");
		return 0;
	}
	max(&a, &b);
	if (b%a != 0)
		printf("1");
	else {
		for (int i = 0; i < a; i++)
			printf("1");
	}

}

/*comment*/
//a == b일경우 고려 안함
//?? 왜틀리지