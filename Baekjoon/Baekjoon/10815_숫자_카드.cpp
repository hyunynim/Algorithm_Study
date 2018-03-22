#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector <int> a;
	int n, m, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	scanf("%d", &m);
	sort(a.begin(), a.end());
	vector<int>::iterator isE;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		if (binary_search(a.begin(), a.end(), tmp))
			printf("1");
		else
			printf("0");
		printf(" ");
	}
}