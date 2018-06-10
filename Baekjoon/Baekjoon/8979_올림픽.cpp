#include<cstdio>

class SCORE {
public:
	int n;
	int rank;
	int	medal[3];
};

void swap(SCORE & sc1, SCORE & sc2) {
	SCORE scTmp;
	scTmp.n = sc1.n;
	for (int i = 0; i < 3; ++i)
		scTmp.medal[i] = sc1.medal[i];

	sc1.n = sc2.n;
	for (int i = 0; i < 3; ++i)
		sc1.medal[i] = sc2.medal[i];

	sc2.n = scTmp.n;
	for (int i = 0; i < 3; ++i)
		sc2.medal[i] = scTmp.medal[i];

}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	SCORE score[1010];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &score[i].n);
		for (int j = 0; j < 3; ++j)
			scanf("%d", &score[i].medal[j]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (score[j].medal[0] < score[j + 1].medal[0])
				swap(score[j], score[j + 1]);
			else if (score[j].medal[0] == score[j + 1].medal[0]) {
				if (score[j].medal[1] < score[j + 1].medal[1])
					swap(score[j], score[j + 1]);
				else if (score[j].medal[1] == score[j + 1].medal[1]) {
					if (score[j].medal[2] < score[j + 1].medal[2])
						swap(score[j], score[j + 1]);
				}
			}
		}
	}
	int rank = 1;
	for (int i = 0; i < n; ++i) {
		if (i == 0)
			score[i].rank = rank;
		else {
			if (score[i].medal[0] == score[i - 1].medal[0]
				&& score[i].medal[1] == score[i - 1].medal[1]
				&& score[i].medal[2] == score[i - 1].medal[2])
				score[i].rank = rank;
			else {
				rank = i + 1;
				score[i].rank = rank;
			}
		}
		if (score[i].n == k) {
			printf("%d", score[i].rank);
			return 0;
		}
	}
	
}

/*comment*/
//공동 등수만큼 랭크 올려줘야함