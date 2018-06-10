#include<cstdio>
#include<queue>
#include<functional>

using namespace std;

int main() {
	priority_queue<int> card[101];
	int n, m, tmp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &tmp);
			card[i].push(tmp);
		}
	}

	int score[101] = { 0 };
	int maxScore, maxIndex;
	priority_queue<int, vector<int>, greater<int>> draw;
	for (int i = 0; i < m; ++i) {
		maxScore = 0;
		maxIndex = 0;
		
		for (int j = 0; j < n; ++j) {
			if (maxScore < card[j].top()) {
				while (draw.size())
					draw.pop();
				maxScore = card[j].top();
				maxIndex = j;
			}
			else if (maxScore == card[j].top()) {
				draw.push(j);
			}
			card[j].pop();
		}
		score[maxIndex]++;
		while (draw.size()) {
			score[draw.top()]++;
			draw.pop();
		}
	}

	maxScore = 0;
	maxIndex = 0;
	for (int i = 0; i < n; ++i) {
		if (maxScore < score[i]) {
			while (draw.size())
				draw.pop();
			maxScore = score[i];
			maxIndex = i;
		}
		else if (maxScore == score[i])
			draw.push(i+1);
	}
	draw.push(maxIndex + 1);
	while (draw.size()) {
		printf("%d ", draw.top());
		draw.pop();
	}
}