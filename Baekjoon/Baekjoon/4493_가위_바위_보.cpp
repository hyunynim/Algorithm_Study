#include<cstdio>

int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; ++tt) {
		int n;
		char msg[12];
		int p1 = 0, p2 = 0;
		scanf("%d", &n);
		getchar();
		for (int i = 0; i < n; ++i) {
			fgets(msg, 5, stdin);
			if ((msg[0] == 'R' && msg[2] == 'S')
				|| (msg[0] == 'S' && msg[2] == 'P')
				|| (msg[0] == 'P' && msg[2] == 'R')) ++p1;
			else if ((msg[2] == 'R' && msg[0] == 'S')
				|| (msg[2] == 'S' && msg[0] == 'P')
				|| (msg[2] == 'P' && msg[0] == 'R')) ++p2;
		}
		if (p1 == p2)
			printf("TIE\n");
		else if (p1 > p2)
			printf("Player 1\n");
		else
			printf("Player 2\n");
	}
}