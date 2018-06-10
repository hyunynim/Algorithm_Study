#include<Cstdio>

int pow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

void IO2Int(char *msg) {
	int res = 0;
	for(int i = 0; i<8; ++i){
		if (msg[i] == 'I')
			res += pow(2, 8 - i - 1);
	}
	printf("%c", res);
}

int main() {
	int t, b;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		char msg[123];
		scanf("%d", &b);
		printf("Case #%d: ", i + 1);
		for (int j = 0; j < b; ++j) {
			scanf("%8s", msg);
			IO2Int(msg);
		}
		printf("\n");
	}
}