#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<stack>
using namespace std;
vector<int> seq;
vector<vector<int>> ans;

int cnt;
void print(vector<int> & pick) {
	vector<int> tmp;
	for (int i : pick)
		tmp.push_back(i);
	ans.push_back(tmp);
}

void p(int toPick, vector<int> & pick, int prev) {
	if (toPick == 0)
		print(pick);
	else {
		int next = pick.empty() ? 0 : prev + 1;
		for (int i = next; i < seq.size(); ++i) {
			pick.push_back(seq[i]);
			p(toPick - 1, pick, i);
			pick.pop_back();
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> vtmp(n);
	map<int, int> mp;
	for (int i = 0; i < n; ++i) 
		scanf("%d", &vtmp[i]);
	sort(vtmp.begin(), vtmp.end());
	for (int i = 0; i < vtmp.size(); ++i)
			seq.push_back(vtmp[i]);

	vtmp.clear();
	p(m, vtmp, 0);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j)
			printf("%d ", ans[i][j]);
		puts("");
	}
}