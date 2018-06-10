#include<cstdio>
typedef long long ll;

int main() {
	char num[2][10010];
	scanf("%s %s", num[0], num[1]);
	
	ll res = 0, preCalc[10][10];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			preCalc[i][j] = i*j;
		}
	}
	int i = 0;
	while (num[0][i] != '\0') {
		int j = 0;
		while (num[1][j] != '\0') {
			res += preCalc[num[0][i] - '0'][num[1][j] - '0'];
			++j;
		}
		++i;
	}
	printf("%lld", res);
}