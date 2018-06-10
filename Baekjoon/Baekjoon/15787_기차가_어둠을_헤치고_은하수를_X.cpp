#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, m, command, tr, x;
	scanf("%d %d", &n, &m);
	vector<int> train(n, 0);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &command);
		switch (command) {
		case 1:
			scanf("%d %d", &tr, &x);
			train[tr] |= (1 << x);
			break;
		case 2:
			scanf("%d %d", &tr, &x);
			train[tr] &= (~(1 << x));
			break;
		case 3:
			scanf("%d", &tr);
			if (train[tr] & (1 << 20))
				train[tr] ^= (1 << 20);
			train[tr] <<= 1;
			break;
		case 4:
			scanf("%d", &tr);
			if (train[tr] & (1 << 1))
				train[tr] ^= (1 << 1);
			train[tr] >>= 1;
			break;
		}
	}
	vector<int> res;
	int j = 0;
	while (1) {
		for (int i = 0; i < res.size(); ++i) {
			if (res[i] == train[j]) {
				printf("%d", res.size());
				return 0;
			}
		}
		res.push_back(train[j++]);
		if (res.size() == train.size()) {
			printf("%d", res.size());
			return 0;
		}
	}
}

/*comment*/
//그냥 shift -> 확인 후 켜져있으면 xor로 켜고 shift
//틀림
//1. 혹시 문제의 의도가 기차가 순서대로 지나가므로 i번째 기차가 못지나가면 i+1번째 부터는 못지나간다?
//0개짜리 포함해서 중복 제거인듯
//shift연산이 연산만하고 대입을 안해놨었음
//근데 또틀림
//다시 1번처럼 풀어보자
//틀림 왜자꾸 틀리는거
//중복제거가 맞다고 생각하고 뭐가 틀린지 찾아보자
//중복 제거면 틀린게 없는것 같은데