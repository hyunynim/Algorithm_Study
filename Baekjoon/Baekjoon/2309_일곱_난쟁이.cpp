#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> height;

int sum(vector <int> & picked) {
	int res = 0;
	for (int i = 0; i < picked.size(); ++i)
		res += picked[i];
	return res;
}

bool pick(vector <int> & picked, int toPick, int prev) {
	if (toPick == 0) {
		if (sum(picked) == 100)
			return 1;
	}
	else {
		int next = picked.empty() ? 0 : prev + 1;
		for (int i = next; i < 9; ++i) {
			picked.push_back(height[i]);
			if (pick(picked, toPick - 1, i))
				return 1;
			picked.pop_back();
		}
	}
	return 0;
}

int main() {
	vector <int> res;
	int tmp;
	for (int i = 0; i < 9; ++i) {
		scanf("%d", &tmp);
		height.push_back(tmp);
	}
	pick(res, 7, 0);
	sort(res.begin(), res.end());
	for(int i = 0; i<res.size(); ++i)
		printf("%d\n", res[i]);
}