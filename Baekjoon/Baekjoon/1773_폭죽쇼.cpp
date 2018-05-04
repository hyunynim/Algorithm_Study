#include <stdio.h>
#include<vector>

using namespace std;

bool chk(vector<int> & num, int k) {
	bool chk = 0;
	for (int i = 0; i < num.size(); ++i) {
		if (k % num[i] == 0) {
			chk = 1;
			break;
		}
	}
		return chk;
}

int main() {
	int n, c, tmp;
	vector <int> time;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		time.push_back(tmp);
	}
	int res = 0;
	for (int i = 1; i <= c; ++i) {
		if (chk(time, i))
			res++;
	}
	printf("%d", res);
}