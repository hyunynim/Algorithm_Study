#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int Abs(int a) {
	return a > 0 ? a : -a;
}
int main() {
	int a, b, c;
	while (~scanf("%d %d %d", &a, &b, &c)) {
		vector<int> num;
		num.push_back(a);
		num.push_back(b);
		num.push_back(c);
		sort(num.begin(), num.end());
		printf("%d\n", max(num[2] - num[1], num[1] - num[0]) - 1);
	}
}