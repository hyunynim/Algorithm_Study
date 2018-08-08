#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

int t, w;
int tree[1234];
int d[1010][2][31];

int go(int curI, int curX, int cnt) {
	if (curI == t)
		return 0;
	int & ans = d[curI][curX][cnt];
	if (ans != -1)
		return ans;
	ans = 0;
	if (tree[curI] == curX)
		ans = 1;
	int tmp = 0;
	tmp = max(tmp, go(curI + 1, curX, cnt));
	if (cnt < w)
		tmp = max(tmp, go(curI + 1, 1 - curX, cnt + 1));
	ans += tmp;
	return ans;
}

int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &t, &w);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &tree[i]);
		tree[i]--;
	}
	printf("%d", max(go(0, 0, 0), go(0, 1, 1)));
}