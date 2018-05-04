#include<cstdio>
#include<queue>
#include<string.h>

using namespace std;

int main() {
	char msg[1000001];
	scanf("%s", msg);
	if (strcmp(msg, "0") == 0) {
		printf("0");
		return 0;
	}
	if (strcmp(msg, "1") == 0) {
		printf("1");
		return 0;
	}
	if (strcmp(msg, "10") == 0) {
		printf("2");
		return 0;
	}
	if (strcmp(msg, "11") == 0) {
		printf("3");
		return 0;
	}
	
	int i = 0;
	queue<int> num;
	int k = strlen(msg)%3;

	while ((3-k) % 3) {
		num.push(0);
		k++;
	}

	while (msg[i] != '\0') {
		num.push(msg[i] - '0');
		++i;
	}

	while (num.size()) {
		int dig = 0;
		dig += num.front() * 4;
		num.pop();
		dig += num.front() * 2;
		num.pop();
		dig += num.front() * 1;
		num.pop();
		printf("%d", dig);
	}
}