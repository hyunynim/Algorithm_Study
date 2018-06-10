#include<cstdio>

int main() {
	char msg[1000001];
	scanf("%s", msg);
	if (msg[1] == '\0') {
		printf("0\n%s", (msg[0] - '0') % 3 == 0 ? "YES" : "NO");
		return 0;
	}
	int n = 0;
	int i = 0, res = 0;
	while (msg[i] != '\0') {
		n += msg[i] - '0';
		++i;
	}
	++res;
	while (n > 9) {
		int tmp = 0;
		while (n > 0) {
			tmp += n % 10;
			n /= 10;
		}
		n = tmp;
		++res;
	}
	printf("%d\n%s", res, n % 3 == 0 ? "YES" : "NO");
}

/*comment*/
//한자리수