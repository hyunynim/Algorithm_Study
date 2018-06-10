#include<cstdio>
#include<vector>
#include<functional>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n;
	char msg[567];
	scanf("%d", &n);
	vector<pair<int, pair<int, string>>> serial;
	string strtmp;
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		strtmp = msg;
		int itmp = 0;
		for (int j = 0; msg[j] != '\0'; ++j) {
			if ('0' <= msg[j] && msg[j] <= '9') {
				itmp += msg[j] - '0';
			}
		}
		serial.push_back(make_pair(strtmp.length(), make_pair(itmp, strtmp)));
	}

	sort(serial.begin(), serial.end());
	for (int i = 0; i < serial.size(); ++i) {
		printf("%s\n", serial[i].second.second.c_str());
	}
}