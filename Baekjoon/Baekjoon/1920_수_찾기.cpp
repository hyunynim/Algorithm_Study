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
	vector<int>::iterator isE;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		isE = find(a.begin(), a.end(), tmp);
		if (isE == a.end())
			printf("0");
		else
			printf("1");
		printf("\n");
	}
}