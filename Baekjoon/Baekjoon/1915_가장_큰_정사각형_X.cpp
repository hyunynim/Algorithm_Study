#include<cstdio>
#include<utility>
using namespace std;
bool arr[1001][1001] = { 0 };

bool IsRect(pair<int, int> start, int size) {
	int sx = start.first;
	int sy = start.second;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (arr[sy + i][sx + j]);
			else
				return 0;
		}
	}
	return 1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &arr[i][j]);
		}
	}
	bool isEnd = 0;
	int size = n > m ? m : n;
	for (int k = size; size >= 1; --size) {
		for (int i = 0; i <= n - size; ++i) {
			for (int j = 0; j <= m - size; ++j) {
				if (arr[i][j] && IsRect(make_pair(j, i), size)) {
					isEnd = 1;
					break;
				}
			}
			if (isEnd)
				break;
		}
		if (isEnd)
			break;
	}
	printf("%d", size * size);
}

/*comment*/
//테두리만 1이 아니라 전체가 다 1이여야 하는 듯 -> IsRect 수정
//무식하게 풀기 시간초과