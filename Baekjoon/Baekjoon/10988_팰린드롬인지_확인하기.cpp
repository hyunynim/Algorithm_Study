#include<cstdio>
#include<string.h>
int main() {
	char msg[150];
	scanf("%s", msg);
	int len = strlen(msg) - 1;
	for (int i = 0; i < len - i; ++i){
		if (msg[i] != msg[len - i]) {
			printf("0");
			return 0;
		}
	}
	printf("1");
}