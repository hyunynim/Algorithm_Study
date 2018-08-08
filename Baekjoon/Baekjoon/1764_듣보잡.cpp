#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
vector<string> str[2];

int main() {
	int n, m;
	char msg[123];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		str[0].push_back(msg);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%s", msg);
		str[1].push_back(msg);
	}
	sort(str[0].begin(), str[0].end());
	sort(str[1].begin(), str[1].end());
	vector<string> ans;
	for (int i = 0; i < n; ++i) {
		if (binary_search(str[1].begin(), str[1].end(), str[0][i]))
			ans.push_back(str[0][i]);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%s\n", ans[i].c_str());
	}
}