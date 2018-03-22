#include <stdio.h>

int main() {
	char msg[5][16];
	for (int i = 0; i < 5; i++) {
		scanf("%s", msg[i]);
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (('0' <= msg[j][i] && msg[j][i] <= '9')
				|| ('a'<= msg[j][i] && msg[j][i] <= 'z')
				|| ('A' <= msg[j][i] && msg[j][i] <= 'Z'))
				printf("%c", msg[j][i]);
		}
	}
}

/*comment*/
//왜틀린지를 모르겠음;;;