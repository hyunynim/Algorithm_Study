#include <iostream>

int main() {
	char msg[101];
	scanf("%s", msg);
	int i = 0;
	int res = 0;
	while (msg[i] != '\0') {
		bool isNum = 1;
		while (msg[i] != ',' && msg[i+1] != '\0') {
			if ('0' > msg[i] || msg[i] > '9') {
				isNum = 0;
				break;
			}
			i++;
		}
		if (isNum)
			res++;
		else {
			while (msg[i] != ',' && msg[i+1] != '\0')i++;
		}
		i++;
	}
	printf("%d", res);
}