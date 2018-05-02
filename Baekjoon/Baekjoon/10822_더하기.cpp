#include<cstdio>

int main() {
	char msg[200];
	scanf("%s", msg);
	int i = 0, res = 0;
	while (msg[i] != '\0') {
		int tmp = 0;
		while (msg[i] != ',' && msg[i] != '\0') {
			tmp = tmp*10 + msg[i] - '0';
			++i;
		}
		res += tmp;
		if (msg[i] == '\0')
			break;
		++i;
	}
	printf("%d", res);
}