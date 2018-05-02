#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector <int> num;
	int n;
	scanf("%d", &n);
	int tmp;
	for (int i = 1; i <= n; ++i) 
		num.push_back(i);

	for (int i = 0; num.begin() + i != num.end(); ++i)
		printf("%d ", num[i]);
	printf("\n");
	while (next_permutation(num.begin(), num.end())) {
		for (int i = 0; num.begin() + i != num.end(); ++i)
			printf("%d ", num[i]);		
		printf("\n");
	}
}