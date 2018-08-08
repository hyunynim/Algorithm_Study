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
//2 1 1 1 1 -> 3���� ��?
//base case ���� -> ó���ϴϱ� ���� Ʋ��
//bottom - up good
//�׻� ������� ó���Ǵ°� �ƴ�
//ó��Ǭ�� �¾Ҵµ� +1 �ȳ��� �κ��� �־���