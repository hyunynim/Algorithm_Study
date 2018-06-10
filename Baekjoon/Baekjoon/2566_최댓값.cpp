#include<cstdio>
#include<utility>
using namespace std;
int main() {
	int seq[9][9];
	int max = 0, tmp;
	pair<int, int> pos;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%d", &tmp);
			if (tmp > max) {
				max = tmp;
				pos.first = i;
				pos.second = j;
			}
		}
	}
	printf("%d\n%d %d", max, pos.first + 1, pos.second + 1);
}