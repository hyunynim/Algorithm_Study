#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	vector<string> handle;
	string tmp;
	char msg[1234];
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		tmp = msg;
		handle.push_back(tmp);
	}
	sort(handle.begin(), handle.end());
	printf("%s", handle[x - 1].c_str());
}