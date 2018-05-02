#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector <int> num;
	int tmp;
	scanf("%d", &tmp);
	while (tmp > 0) {
		num.push_back(tmp % 10);
		tmp /= 10;
	}
	sort(num.begin(), num.end());
	for (int i = num.size() - 1; i >= 0; --i)
		printf("%d", num[i]);
}