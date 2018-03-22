#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int n, tmp;
	scanf("%d", &n);
	vector <int> num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	printf("%d %d", *(num.begin()), *(num.end() - 1));
}