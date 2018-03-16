#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, k;
	int erase = 0;
	int min = 2, ans;
	queue <int> q, q2;
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; i++)
		q.push(i);
	while (erase != k) {
		if (q.front() % min != 0)
			q2.push(q.front());
		else
			erase++;
		if (erase == k)
			ans = q.front();
		q.pop();
		if (q.size() == 0) {
			while (q2.size() != 0) {
				q.push(q2.front());
				q2.pop();
			}
			min = q.front();
		}
	}
	printf("%d", ans);
}