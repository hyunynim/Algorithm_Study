#include <stdio.h>

unsigned long long gcd(unsigned long long a, unsigned long long b);
unsigned long long cm(unsigned long long a, unsigned long long b, unsigned long long gcd);

int main()
{
	unsigned long long a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld", cm(a, b, gcd(a, b)));
	return 0;
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

unsigned long long cm(unsigned long long a, unsigned long long b, unsigned long long gcd) {
	return (a / gcd)*(b / gcd)*gcd;
}

/*comment*/
//printf의 형식지정문자 오타