#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int cache[100005][3];
vector<int> price[2];

int makeIt(int row, int col) {	//row == 0 then X
	if (col < 0)
		return 0;
	else {
		int & ans = cache[col][row];
		if (ans != -1)
			return ans;
		
		int res = (row == 0 ? 0 : price[row - 1][col]);
		if (row == 0)
			res += max(makeIt(0, col - 1), max(makeIt(1, col - 1), makeIt(2, col - 1)));
		else if (row == 1) 
			res += max(makeIt(0, col - 1), makeIt(2, col - 1));
		else
			res += max(makeIt(0, col - 1), makeIt(1, col - 1));
		ans = res;
		return res;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, tmp;
		memset(cache, -1, sizeof(cache));
		price[0].clear();
		price[1].clear();
		scanf("%d", &n);
		for (int k = 0; k < 2; ++k) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &tmp);
				price[k].push_back(tmp);
			}
		}
		printf("%d\n", makeIt(0, n));
	}
}