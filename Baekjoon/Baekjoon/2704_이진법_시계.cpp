#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[1234];
		scanf("%s", msg);
		int hour = (msg[0] - '0') * 10 + (msg[1] - '0');
		int min = (msg[3] - '0') * 10 + (msg[4] - '0');
		int sec = (msg[6] - '0') * 10 + (msg[7] - '0');
		int res[3][6] = { 0 };
			for (int j = 5; j >= 0; --j) {
				res[0][j] = hour % 2;
				hour /= 2;
				res[1][j] = min % 2;
				min /= 2;
				res[2][j] = sec % 2;
				sec /= 2;
			}
			for (int j = 0; j < 6; ++j) {
				for (int k = 0; k < 3; ++k)
					printf("%d", res[k][j]);
			}
			printf(" ");
			for(int j= 0; j<3; ++j){
				for (int k = 0; k < 6; ++k)
					printf("%d", res[j][k]);
			}
			printf("\n");
	}
}