#include<cstdio>
#include<vector>
#include<utility>

using namespace std;

int main() {
	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t) {
		int n, tmp;
		scanf("%d", &n);
		vector<pair<int, int>> seq;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			bool chk = 0;
			int j;
			for (j = 0; j < seq.size(); ++j) {
				if (seq[j].first == tmp) {
					chk = 1;
					break;
				}
			}
			if (chk)
				seq[j].second++;
			else
				seq.push_back({ tmp, 1 });
		}
		for (int i = 0; i < seq.size(); ++i) {
			if (seq[i].second == 1)
				printf("Case #%d: %d\n", t+1, seq[i].first);
		}
		seq.clear();
	}
}
/*comment*/
//Case 소문자로 출력