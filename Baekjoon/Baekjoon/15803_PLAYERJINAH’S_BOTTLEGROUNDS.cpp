#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<pair<int, int>> pos[2];
	int x, y;
	for (int i = 0; i < 3; ++i) {
		scanf("%d %d", &x, &y);
		pos[0].push_back(make_pair(x, y));
		pos[1].push_back(make_pair(y, x));
	}
	sort(pos[0].begin(), pos[0].end());
	sort(pos[1].begin(), pos[1].end());

	if ((pos[0][2].first - pos[0][1].first) * (pos[0][1].second - pos[0][0].second) == (pos[0][1].first - pos[0][0].first)*(pos[0][2].second - pos[0][1].second))
		printf("WHERE IS MY CHICKEN?");
	else
		printf("WINNER WINNER CHICKEN DINNER!");
}

/*comment*/
//vector�� ���ؼ� �յ��϶��� �´ٰ� ����
//a = kb �϶� �� �� ���Ͱ� �����϶��� �´ٰ� ó���������