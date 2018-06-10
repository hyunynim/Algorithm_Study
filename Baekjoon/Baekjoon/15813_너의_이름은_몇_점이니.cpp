#include<cstdio>

int main() {
	long long * temp = new long long;
	printf("%s", ((long long)temp % 3 ? "0" : "1"));
}