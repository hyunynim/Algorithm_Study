#include<cstdio>

int main() {
	int k, s;
	char msg[1000010];
	scanf("%d %d", &k, &s);
	getchar();
	fgets(msg, 1000000, stdin);
	k %= 26;
	int t = 0;
	for (int i = 0; i < s; ++i) {
		t = msg[i];
		if ('a' <= msg[i] && msg[i] <= 'z') {
			t += k;
			if (t > 'z')
				t -= 26;
			msg[i] = t;
		}
		if ('A' <= msg[i] && msg[i] <= 'Z') {
			msg[i] += k;
			if (msg[i] > 'Z')
				msg[i] -= 26;
		}
		if (msg[i] == '\n')
			msg[i] = '\0';
	}
	printf("%s", msg);
}

/*comment*/
//overflow 해결 안함