#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int n, tmp;
	vector<int> needed;
	vector<int> res;
	queue<int> pizzaQueue;
	scanf("%d", &n);
	int max = 0, maxIndex = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		needed.push_back(tmp);
		if (tmp > max) {
			max = tmp;
			maxIndex = i;
		}
		res.push_back(0);
	}
	int totTime = 1;
	while (needed[maxIndex] > 0) {
		for (int i = 0; i < needed.size(); ++i) {
			if (needed[i] > 0) {
				pizzaQueue.push(i);
				needed[i]--;
			}
		}
		while (pizzaQueue.size()) {
			int cur = pizzaQueue.front();
			pizzaQueue.pop();
			res[cur] = totTime;
			++totTime;
		}
	}
	for (int i = 0; i < res.size(); ++i)
		printf("%d ", res[i]);
}