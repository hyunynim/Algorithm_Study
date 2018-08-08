#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

stack<pair<char, int>> seq;
char msg[123456];
vector<pair<int, int>> stick;
vector<int> laser;

int main() {
	scanf("%s", msg);
	int i = 0;
	while (msg[i] != '\0') {
		if (msg[i] == '(')
			seq.push({ msg[i], i });
		else {
			if (seq.top().second + 1 == i) {
				laser.push_back(i);
			}
			else {
				stick.push_back({ seq.top().second, i });
			}
			seq.pop();
		}
		++i;
	}
	int ans = stick.size();
	for (int i = 0; i < stick.size(); ++i) {
		for (int j = 0; j < laser.size(); ++j) {
			if (laser[j] < stick[i].first)
				continue;
			else if (laser[j] >= stick[i].second)
				break;
			else
				++ans;
		}
	}
	printf("%d", ans);
}