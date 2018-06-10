#include<cstdio>

int main() {
	int cloud[123][123] = { 0 };
	int h, w;
	scanf("%d %d", &h, &w);
	getchar();
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%1c", &cloud[i][j]);
		}
		getchar();
	}
	int cnt = -1;
	int res[123][123] = { 0 };
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (cloud[i][j] == 'c')
				cnt = 0;
			if(cnt >=0)
				res[i][j] = cnt++;
			else
				res[i][j] = cnt;
		}
		cnt = -1;
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			printf("%d ", res[i][j]);
		printf("\n");
	}
}