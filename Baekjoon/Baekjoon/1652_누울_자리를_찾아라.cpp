#include<cstdio>

bool room[123][123];

int main() {
	char msg[123];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		for (int j = 0; j < n; ++j) {
			if (msg[j] == '.')
				room[i][j] = 1;
			else
				room[i][j] = 0;
		}
	}
	int ans[2] = { 0 };
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (room[i][j])
				++cnt;
			else
				cnt = 0;
			if (cnt == 2)
				++ans[0];
		}
	}
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (room[j][i])
				++cnt;
			else
				cnt = 0;
			if (cnt == 2)
				++ans[1];
		}
	}
	printf("%d %d", ans[0], ans[1]);
}