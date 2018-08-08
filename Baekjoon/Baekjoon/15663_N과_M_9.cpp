#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<stack>
using namespace std;
vector<int> seq;
vector<vector<int>> ans;

int cnt[12345];
void print(vector<int> & pick) {
	vector<int> tmp;
	for (int i : pick)
		tmp.push_back(i);
	ans.push_back(tmp);
}

void p(int toPick, vector<int> &pick) {
	if (toPick == 0)
		print(pick);
	else {
		int chk[12345] = { 0 };
		for (int i = 0; i < pick.size(); ++i) {
			chk[pick[i]]++;
		}
		for (int i = 0; i < seq.size(); ++i) {
			if (chk[seq[i]] < cnt[seq[i]]) {
				pick.push_back(seq[i]);
				p(toPick - 1, pick);
				pick.pop_back();
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	seq.resize(n);
	vector<int> vtmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		cnt[seq[i]]++;
	}
	sort(seq.begin(), seq.end());
	p(m, vtmp);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j)
			printf("%d ", ans[i][j]);
		puts("");
	}
}