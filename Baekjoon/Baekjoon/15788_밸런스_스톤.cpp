#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
ll block[500][500];
ll row[501] = { 0 };
ll col[501] = { 0 };
ll diag[2] = { 0 };
bool chk[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
int n;

int main() {
	pair<int, int> pos;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%lld", &block[i][j]);
			if (block[i][j] == 0)
				pos = { i, j };
			if (i == j)
				diag[0] += block[i][j];
			if (i + j == n - 1)
				diag[1] += block[i][j];
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			row[i] += block[i][j];
			col[i] += block[j][i];
		}
		if (ans == 0 && i != pos.first)
			ans = row[i];
	}
	for (int i = 0; i < n; ++i) {
		if (i != pos.first) {
			if (row[i] != ans) {
				printf("-1");
				return 0;
			}
		}
		if (i != pos.second) {
			if (col[i] != ans) {
				printf("-1");
				return 0;
			}
		}
	}

	if (pos.first == pos.second && pos.first + pos.second == n - 1) {
		if (row[pos.first] == col[pos.second] && diag[0] == diag[1] && diag[0] == row[pos.first])
			printf("%lld", ans - diag[0]);
		else
			printf("-1");
	}

	else if (pos.first != pos.second && pos.first + pos.second == n - 1) {
		if (row[pos.first] == col[pos.second] && diag[1] == row[pos.first])
			printf("%lld", ans - diag[1]);
		else
			printf("-1");
	}

	else if (pos.first == pos.second && pos.first + pos.second != n - 1) {
		if (row[pos.first] == col[pos.second] && diag[0] == row[pos.first])
			printf("%lld", ans - diag[0]);
		else
			printf("-1");
	}
	else {
		if(row[pos.first] == col[pos.second])
			printf("%lld", ans - row[pos.first]);
		else
			printf("-1");
	}
}

/*comment*/
//���ʿ� ���� ���� ��� �ɷ���
//���ƾ��� �ϴ� �ڵ尡 �ʹ� ��������
//��ü ������ ���ؼ� ����ؾ��ϴ� �� ���� �Ϻ� ������ ����ؼ� ������ ǰ