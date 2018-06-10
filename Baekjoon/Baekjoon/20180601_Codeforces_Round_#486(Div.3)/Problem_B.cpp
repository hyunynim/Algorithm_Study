#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<string>
using namespace std;

int main() {
	int n;
	char msg[132];
	vector<pair<int, string>> seq;
	string strTmp;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		strTmp = msg;
		seq.push_back(make_pair(strTmp.length(), strTmp));
	}
	sort(seq.begin(), seq.end());
	for (int i = 1; i < seq.size(); ++i) {
		if (seq[i].second.find(seq[i - 1].second.c_str()) == string::npos) {
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 0; i < seq.size(); ++i)
		printf("%s\n", seq[i].second.c_str());
}