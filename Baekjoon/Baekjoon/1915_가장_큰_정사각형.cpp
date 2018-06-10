#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
int arr[1001][1001] = { 0 };

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
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%1d", &arr[i][j]);
		}
	}
	int sizeMax = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (arr[i][j])
				arr[i][j] = min(min(arr[i - 1][j - 1], arr[i - 1][j]), arr[i][j - 1]) + 1;
			if (arr[i][j] > sizeMax)
				sizeMax = arr[i][j];
		}
	}
	printf("%d", sizeMax*sizeMax);
}

/*comment*/
//�׵θ��� 1�� �ƴ϶� ��ü�� �� 1�̿��� �ϴ� �� -> IsRect ����
//�����ϰ� Ǯ�� �ð��ʰ�
//���ƾ���