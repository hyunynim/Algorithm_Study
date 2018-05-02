#include <stdio.h>
#include <string.h>

int main() {
	unsigned int num = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[10];
		int tmp;
		scanf("%s", msg);
		if (strcmp(msg, "all") == 0) {
			num = (1 << 21) - 1;
		}
		else if (strcmp(msg, "add") == 0) {
			scanf("%d", &tmp);
			num |= (1 << tmp);
		}
		else if (strcmp(msg, "remove") == 0) {
			scanf("%d", &tmp);
			num &= ~(1 << tmp);
		}
		else if (strcmp(msg, "check") == 0) {
			scanf("%d", &tmp);
			if (num & (1 << tmp)) printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(msg, "toggle") == 0) {
			scanf("%d", &tmp);
			num ^= (1 << tmp);
		}
		else if (strcmp(msg, "empty") == 0) {
			num = 0;
		}
	}
}

/*comment*/
//bit mask 공부
//all 할 경우 20이 켜지질 않았음
//20개를 켜고 싶을 경우 (1<<20) -1 이 아니라 (1<<21) -1을 해야하는듯