#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int sum = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 10000; ++i) {
		if (n%i == 0)
			sum += i;
		if (n < i)
			break;
	}
	printf("%d", sum * 5 - 24);
	
}