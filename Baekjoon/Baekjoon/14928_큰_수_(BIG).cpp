#include <iostream>

int main() {
	char msg[1000002];
	scanf("%s", msg);
	int res = 0;
	int j = 0;
	while (msg[j] != '\0') {
		res = (res*10 + msg[j] - '0')% 20000303;
		++j;
	}
	printf("%d", res);
}