#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
vector <int> seq;
vector <int> res1, res2;
int k, res = 0;
void chkSum(vector <int> &picked) {
	if (picked[0] + picked[1] == k) {
		res1.push_back(picked[0]);
		res2.push_back(picked[1]);
	}
}

void pick(vector <int> &picked, int toPick, int prev) {
	if (toPick == 0)
		chkSum(picked);
	int next = picked.empty() ? 0 : prev + 1;
	for (int i = next; i < seq.size(); ++i) {
		picked.push_back(seq[i]);
		pick(picked, toPick - 1, i);
		picked.pop_back();
	}
}

int main() {
	int tmp;
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}/* 문제풀땐 이거로
	while (scanf("%d", &tmp) != EOF) {
		seq.push_back(tmp);
	}*/
	sort(seq.begin(), seq.end());
	scanf("%d", &k);
	vector <int> vtmp;
	pick(vtmp, 2, 0);
	for (int i = 0; i < res1.size(); ++i) {
		if (i != 0 && res1[i] == res1[i - 1] && res2[i] == res2[i - 1])
			continue;
		printf("%d %d\n", res1[i], res2[i]);
		res++;
	}
	printf("%d", res);
}

/*comment*/
//중복case 체크 안함
//왜틀린지를 모르겠음