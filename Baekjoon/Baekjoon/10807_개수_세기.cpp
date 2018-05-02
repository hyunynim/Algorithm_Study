#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector <int> num;
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	int v;
	scanf("%d", &v);
	int cnt = 0;
	for (int i = 0; num.begin() + i != num.end(); ++i) {
		if (num[i] == v)
			cnt++;
	}
	printf("%d", cnt);
}