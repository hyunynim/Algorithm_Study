#include <cstdio>

int main() {
	int n;
	char msg[20];
	int a = 0, b = 0;
	scanf("%d %s", &n, msg);
	int i = 0;
	while (msg[i] != '\0') {
		if (msg[i] == 'A')
			a++;
		else
			b++;
		++i;
	}
	if (a == b)
		printf("Tie");
	else if (a > b)
		printf("A");
	else
		printf("B");
}