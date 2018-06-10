#include<cstdio>
#include<utility>

using namespace std;

int main() {
	pair<int, int> move[4];
	enum { U, R, D, L };
	move[U].first = 0, move[U].second = 1;
	move[R].first = 1, move[R].second = 0;
	move[D].first = 0, move[D].second = -1;
	move[L].first = -1, move[L].second = 0;
	pair<int, int> cur(0, 0);
	int n, cnt = 1, cntMove = 0;;
	int menu = U;
	scanf("%d", &n);
	if (n == 0) {
		printf("0 0");
		return 0;
	}
	for (int i = 0; i < 1234; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < cnt; ++k) {
				cur.first += move[menu].first;
				cur.second += move[menu].second;
				cntMove++;
				if (cntMove == n) {
					printf("%d %d", cur.first, cur.second);
					return 0;
				}
			}
			menu++;
			if (menu == 4)
				menu = 0;
		}
		++cnt;
	}
}