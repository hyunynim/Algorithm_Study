#include<cstdio>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int res = a * 100 + b;
	if (res == 218)
		printf("Special");
	else if (res < 218)
		printf("Before");
	else
		printf("After"); 
}