#include <iostream>
#include <queue>

using namespace std;

void lotate(int * num, int begin, int end, int mid);

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int * num = new int[n];
	for (int i = 1; i <= n; i++) 
		num[i-1] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		lotate(num, a - 1, b - 1, c - 1);
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", num[i]);
}

void lotate(int * num, int begin, int end, int mid) {
	queue <int> tmp;
	for (int i = begin; i <= end; ++i)
		tmp.push(num[i]);
	for (int i = 0; i < mid - begin; ++i) {
		tmp.push(tmp.front());
		tmp.pop();
	}
	for (int i = begin; i <= end; ++i) {
		num[i] = tmp.front();
		tmp.pop();
	}

}