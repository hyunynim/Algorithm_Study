#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int c[5][3];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &c[0][0], &c[0][1], &c[0][2]);
		for (int j = 0; j < 3; ++j) {
			c[1][j] += c[0][j];
			c[3][j] += c[0][j];
		}
		c[2][0] = max(c[1][0], c[1][1]);
		c[2][1] = max(c[1][0], max(c[1][1], c[1][2]));
		c[2][2] = max(c[1][1], c[1][2]);

		c[4][0] = min(c[3][0], c[3][1]);
		c[4][1] = min(c[3][0], min(c[3][1], c[3][2]));
		c[4][2] = min(c[3][1], c[3][2]);

		for (int j = 0; j < 3; ++j) {
			c[1][j] = c[2][j];
			c[3][j] = c[4][j];
		}
	}
	printf("%d %d", max(c[1][0], max(c[1][1], c[1][2])), min(c[3][0], min(c[3][1], c[3][2])));
}

/*comment*/
//슬라이딩 윈도우였음ㅋ
//문제를 제한적으로 생각함 다시