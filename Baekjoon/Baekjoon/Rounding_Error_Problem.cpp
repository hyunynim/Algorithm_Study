#include<stdio.h>
#include <vector>

using namespace std;

int max = 0;
int n, l, p;
vector<int> seq;

void ChkMax(vector <int> &picked) {
	int res = 0;
	for (int i = 0; i < picked.size(); ++i) {
		res += (int)(((double)picked[i] / n) * (double)100 + 0.5);
//		printf("%d ", picked[i]);
	}
//	printf("\n");
	if (res > ::max)
		::max = res;
}


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d %d", &n, &l);
		int tmp;
		int toPick = 0;
		for (int j = 0; j < l; ++j){
			scanf("%d", &tmp);
			seq.push_back(tmp);
			toPick += tmp;
		}
		for (int j = 0; j < n - l; ++j)
			seq.push_back(0);

		bool *chk = new bool[n + 1];
		chk[0] = 0;
		int min = 1000000000;
		for (int j = 1; j <= n; ++j) {
			if ((int)((double)j / n * 100.0) == (int)(((double)j / n * 100.0) + 0.5))
				chk[j] = 0;
			else {
				if (min == 1000000000)
					min = j;
				chk[j] = 1;
			}
		}
		if (min == 1000000000) {
			seq[0] += n - toPick;
			ChkMax(seq);
			printf("Case #%d: ", i + 1);
			printf("%d\n", ::max);
			::max = 0;
			seq.clear();
			delete[] chk;
			continue;
		}
		int j = 0;
		while (j < seq.size() && toPick < n) {
			int k = seq[j];
			int ttt = 0;
			while (!chk[k + ttt] && ttt < n - toPick)
				ttt++;
			if (min < ttt);
			else {
				seq[j] += ttt;
			}
			j++;
			toPick += ttt;;
		}
		ChkMax(seq);
		//
		printf("Case #%d: ", i + 1);
		printf("%d\n", ::max);
		::max = 0;
		seq.clear();
		delete[] chk;
	}
}

/*comment*/
//시간초과