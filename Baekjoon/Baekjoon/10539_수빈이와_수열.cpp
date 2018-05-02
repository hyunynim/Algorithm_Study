#include <cstdio>
#include <vector>
#include <stack>>

using namespace std;

int main() {
	int n;
	vector <int> num;
	stack <int> res;
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	for (int i = num.size() - 1; i > 0; --i) {
		res.push(num[i] * (i + 1) - num[i - 1] * (i));
	}
	res.push(num[0]);
	while (res.size()) {
		printf("%d ", res.top());
		res.pop();
	}
}