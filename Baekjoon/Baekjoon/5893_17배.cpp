#include <iostream>
#include <string.h>

int main() {
	char msg[1010];
	int num[1010] = { 0 };
	scanf("%s", msg);
	int len = strlen(msg);
	if (len == 1 && msg[0] == '0')
	{
		printf("0");
		return 0;
	}
	int i = 0;
	while (msg[i] != '\0')
		num[i++] = msg[i] - '0';

	int res[1010] = { 0 };
	int tmp = 0;
	for (int i = len + 3; i >= 4; --i) {
		res[i] = (num[i] + num[i - 4] + tmp) % 2;
		if (num[i] + num[i - 4] + tmp >= 2)
			tmp = (num[i] + num[i - 4] + tmp) / 2;
		else
			tmp = 0;
	}
	for (int i = 3; i >= 0; --i) {
		res[i] = (num[i] + tmp)%2;
		if ((num[i] + tmp) >= 2)
			tmp = (num[i] + tmp) / 2;
		else
			tmp = 0;
	}
	if (res[0] == 0) {
		printf("1");
	}
	for (int i = 0; i < len + 4; ++i)
		printf("%d", res[i]);
}

/*comment*/
//자리수 넘어갈때 tmp = 0이 되는걸 고려 안해줌