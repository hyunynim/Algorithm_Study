#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
	vector<pair<int, string>> seq;
	char msg[60];
	string tmp;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		tmp.assign(msg);
		seq.push_back(make_pair(tmp.length(), tmp));
		tmp.clear();
	}
	sort(seq.begin(), seq.end());

	for (int i = 0; i < seq.size(); ++i) {
		if (i != 0 && seq[i - 1].second == seq[i].second) continue;
		cout << seq[i].second << '\n';

	}

}