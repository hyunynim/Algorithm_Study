#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> sz(n);
	for (int i = 0; i < n; ++i) {
		cin >> sz[i];
	}
	sort(sz.begin(), sz.end());

	vector<int>::iterator it = sz.begin();
	int res = 0;
	int sizeOffset = sz[0] + k, tmp = 1;
	for (int i = 1; i < sz.size(); ++i) {
		if (sz[i - 1] < sz[i] && sizeOffset >= sz[i]) {
			res += tmp;
			tmp = 1;
		}
		else if (sz[i - 1] == sz[i])
			++tmp;
		else
			tmp = 1;
		sizeOffset = sz[i] + k;
	}
	printf("%d", sz.size() - res);
}

/*comment*/
//쭉 연결시키는 방식으로 했는데 최솟값이 보장이 안되는건가
//왜틀리는건지 잘 모르겠음
//두 박테리아 사이즈가 같을때 check 안함
//사이즈가 같다가 못먹고 넘어갔을때 tmp 초기화 안해줌