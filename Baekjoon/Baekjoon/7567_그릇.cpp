#include <stdio.h>

int main() {
	char msg[60], tmp;
	int isO = 0;
	int res = 0;
	int i = 0;
	scanf("%s", msg);
	while (msg[i] != '\0') {
		if (isO == 0) {
			res += 10;
			isO = 1;
		}
		else {
			if (tmp == msg[i])
				res += 5;
			else
				res += 10;
		}
		tmp = msg[i++];
	}
	printf("%d", res);
}
/*comment*/
//그냥 string으로 받을걸 괜히 character로 받음