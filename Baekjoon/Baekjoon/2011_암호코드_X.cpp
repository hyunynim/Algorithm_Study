#include<cstdio>
int d[5432] = { 1, 1 };
int main() {
	char msg[5432];
	scanf("%s", msg);
	if (msg[0] == '0' && msg[1] == '\0') {
		printf("0");
		return 0;
	}
	int n = 0;
	for (int i = 2; msg[i - 1] != '\0'; ++i) {
		if (('0' <= msg[i - 1] && msg[i - 1] <= '9' && msg[i - 2] == '1')
			|| ('0' <= msg[i - 1] && msg[i - 1] <= '6' && msg[i - 2] == '2')) {
			if (msg[i - 1] != '0')
				d[i] = d[i - 2] + d[i - 1];
			else if (msg[i - 1] == '0' && (msg[i - 2] == '1' || msg[i - 2] == '2'))
				d[i] = d[i - 2];
			else
				d[i] = d[i - 1];
		}
		else
			d[i] = d[i - 1];
		d[i] %= 1000000;
		++n;
	}
	printf("%d", d[n + 1]);
}