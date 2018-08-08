#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
int cache[501][501];
int bamboo[501][501];
int n;

int sur(int x, int y, int prev) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return 0;
	else {
		int & ans = cache[y][x];
		int cur = bamboo[y][x];
		if (prev >= cur)
			return 0;
		if (ans != -1)
			return ans;
		ans = 1;
		ans = max({ ans, sur(x - 1, y, cur) + 1, sur(x + 1, y, cur) + 1, sur(x, y - 1, cur) + 1, sur(x, y + 1, cur) + 1 });
		return ans;
	}
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for(int j = 0; j<n; ++j)
			scanf("%d", &bamboo[i][j]);
	}
	int ans = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			sur(j, i, 0);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			ans = max(ans, cache[i][j]);
	}
	printf("%d", ans);
}


/*comment*/
//????
//2 1 1 1 1 -> 3나옴 왜?
//base case 순서 -> 처리하니까 답이 틀림
//bottom - up good
//항상 순서대로 처리되는게 아님
//처음푼게 맞았는데 +1 안넣은 부분이 있었음