#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<string> name;
	vector<pair<int, int>> sorting;
	char msg[1233];
	string strTmp;
	int age;
	for (int i = 0; i < n; ++i) {
		scanf("%d %s", &age, msg);
		strTmp = msg;
		sorting.push_back({ age, i });
		name.push_back(strTmp);
	}
	sort(sorting.begin(), sorting.end());
	for (int i = 0; i < n; ++i) {
		printf("%d %s\n", sorting[i].first, name[sorting[i].second].c_str());
	}
}